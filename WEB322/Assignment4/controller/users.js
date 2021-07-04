const express = require('express');
const bcrypt = require("bcryptjs");
const path = require("path");
const userModel = require('../modules/user');
const router = express.Router();
const emailRegExp = /^[0-9a-zA-Z]([-_\.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_\.]?[0-9a-zA-Z])*\.[a-zA-Z]{2,3}$/i;
const pwdRegExp = /^(?=.*\d)(?=.*[a-zA-Z])[0-9a-zA-Z]{8,24}$/;

var db_config = {
    email:  'admin@admin.com',
    pwd:    process.env.DB_CONFIG_PWD
}; 

router.get("/login_page",(req, res) => {
    res.render("user/login_page");
});

router.post("/login_page",(req, res) => {
    console.log(req.body);
    let validData = {};
    let passedValid = true;
        
    const { email, pwd } = req.body;
    const { User } = req.body;
    if(typeof email !== "string" || email.length === 0){
        validData.email = "Must write your e-mail"
        passedValid = false;
    }
    else if (email.length < 2 || !emailRegExp.test(email)){
        validData.email = "Please write your e-mail"
        passedValid = false;
    }
   if(typeof pwd !== "string" || pwd.length === 0){
        validData.pwd = "Must write your Password"
        passedValid = false;
    }
    else if (pwd.length < 8 || !pwdRegExp.test(pwd)){
        validData.pwd = "Please write your Password(over 8)"
        passedValid = false;
    }
    userModel.findOne({
        userType: req.body.User
    }).then((user) => {
        if (passedValid) {
            if(User === "user"){
                let errors = [];
                userModel.findOne({
                    email: req.body.email
                })
                .then((user) => {
                    if (user) {
                        bcrypt.compare(req.body.pwd, user.pwd)
                        .then((isMatched) => {
                            if (isMatched) {
                                req.session.user = user;
                                res.redirect("/");
                            }
                            else {
                                errors.push("Password does not match!");
                                res.render("user/login_page", {
                                    errors
                                });
                            }
                        })
                        .catch((err) => {
                            console.log(`Error comparing passwords: ${err},`);
                            errors.push("Error=compared password");
                            res.render("user/login_page", {
                                errors
                            });
                        });
                    }
                    else {
                        errors.push("E-mail is not found.");
                        res.render("user/login_page", {
                            errors
                        });
                    }
                })
                .catch((err) => {
                    console.log(`Error finding the user from the database: ${err},`);
                    errors.push("Error=Not found on Data");
                    res.render("user/login_page", {
                        errors
                    });
                });
            }
            else if(User === 'admin'){
                if(email.toString() === db_config.email.toString()){
                    if(pwd.toString() === process.env.DB_CONF_PWD){
                       
                    }
                }
                else{
                    res.render("user/login_page", {
                        results: validData,
                        values: req.body
                    });
                }
            }
        }
        else
        {
            res.render("user/login_page", {
                results: validData,
                values: req.body
            });
        }
    
    });
   
});

router.get("/register_page",(req, res) => {
    res.render("user/register_page");
});
router.post("/register_page",(req, res) => {
    console.log(req.body);
    let validData = {};
    let passedValid = true;
    const { firstName, lastName, email, pwd } = req.body;

    if(typeof firstName !== "string" || firstName.length === 0){
        validData.firstName = "Must write your first name"
        passedValid = false;
    }
    else if (firstName.length < 2){
        validData.firstName = "Please write your first name"
        passedValid = false;
    }
    if(typeof lastName !== "string" || lastName.length === 0){
        validData.lastName = "Must write your last name"
        passedValid = false;
    }
    else if (lastName.length < 2){
        validData.lastName = "Please write your last name"
        passedValid = false;
    }
    if(typeof email !== "string" || email.length === 0){
        validData.email = "Must write your e-mail"
        passedValid = false;
    }
    else if (email.length < 2 || !emailRegExp.test(email)){
        validData.email = "Please write your e-mail"
        passedValid = false;
    }
   if(typeof pwd !== "string" || pwd.length === 0){
        validData.pwd = "Must write your Password"
        passedValid = false;
    }
    else if (pwd.length < 8 || !pwdRegExp.test(pwd)){
        validData.pwd = "Please write your Password(over 8)"
        passedValid = false;
    }
   if (passedValid) {
        const user = new userModel({
            firstName:req.body.firstName,
            lastName:req.body.lastName,
            email:req.body.email,
            pwd:req.body.pwd
        });
        user.save()
        .then((userSaved) => {
            console.log(`User ${userSaved.firstName} has been saved to the database.`);
        })
        .catch((err) => {
            console.log(`Error adding user to the database. ${err}`);
        });

        const sgMail = require("@sendgrid/mail");
        sgMail.setApiKey(process.env.SEND_GRID_KEY);

        const msg = {
            to: `${email}`,
            from: "wchoi28@myseneca.ca",
            subject: "Thanks for being our member :) ",
            html:
                `
                Thanks for sign up the our page!<br>
                <br>
                Your Full Name: ${firstName} ${lastName}<br>
                Your Email Address: ${email}<br>
                <br>
                <br>
                sincerely<br>
                Wonchul Choi            <br>
                Student Num: 118362201  <br>
                Student Id : wchoi28    <br>
                Copyright © Winter 2021, Wonchul Choi, WEB322NDD<br>
                `
        };
        sgMail.send(msg)
            .then(() => {
                req.session.user = user;
                res.render("user/welcome", {
                    results: validData,
                    values: req.body
                });
            })
            .catch(err => {
                console.log(`Error ${err}`);
                res.send("Error");
            });
    }
    else
    {
        res.render("user/register_page", {
            results: validData,
            values: req.body
        });
    }    
});
router.get("/logout", (req, res) => {
    req.session.destroy();
    
    res.redirect("/user/login_page");
});
module.exports = router;