/*
 * WEB322 – Assignment 2 (Winter 2021)
 * I declare that this assignment is my own work in accordance with Seneca Academic
 * Policy. No part of this assignment has been copied manually or electronically from
 * any other source (including web sites) or distributed to other students.
 *
 * Name:         Wonchul Choi
 * Student ID:   118362201
 * Course:       Web322 NDD
 *
 */
const express = require('express');
const router = express.Router();
const emailRegExp = /^[0-9a-zA-Z]([-_\.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_\.]?[0-9a-zA-Z])*\.[a-zA-Z]{2,3}$/i;
const pwdRegExp = /^(?=.*\d)(?=.*[a-zA-Z])[0-9a-zA-Z]{8,24}$/;

router.get("/",(req, res) => {
    res.render("general/home");
});
router.get("/about_us",(req, res) => {
    res.render("general/about_us");
});

router.get("/login_page",(req, res) => {
    res.render("general/login_page");
});

router.post("/login_page",(req, res) => {
    console.log(req.body);
    let validData = {};
    let passedValid = true;
        
    const { email, pwd } = req.body;
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
        res.render("general/welcome", {
            results: validData,
            values: req.body
         });
    }
    else
    {
        res.render("general/login_page", {
            results: validData,
            values: req.body
        });
    }
});

router.get("/register_page",(req, res) => {
    res.render("general/register_page");
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
                res.render("general/welcome", {
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
        res.render("general/register_page", {
            results: validData,
            values: req.body
        });
    }


});

module.exports = router;