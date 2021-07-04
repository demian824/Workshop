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
const mealModule = require("../modules/dishData");
const express = require('express');
const router = express.Router();
const path = require("path");
const { EWOULDBLOCK } = require("constants");
const { db } = require("../modules/dishData");


router.get("/load_data", (req, res) =>{
    mealModule.find().count({}, (err, count) =>{
        if(err){
            return res.send(err);
        }
        else if(count === 0) {
            mealModule.collection.insertMany(mealModule.getAllMenu(), (err, docs)=>{
                if(err){
                    return res.send(err);
                }
                else {
                    console.log("Success");
                    res.redirect("/menu/upload");

                }
            });
        }
        else{
            console.log("Data is already loaded");
            res.render("user/upload");
        }
    });
});

router.get("/edit", (req,res) => {
    res.render("user/edit");
});

router.post("/edit", (req,res) => {
 
    mealModule.find({name: req.body.name})
    .exec()
    .then((err,menu) =>{
        mealModule.updateOne(
            {name: req.body.name},
            {$set: {
                ingredient: req.body.ingredient,
                category: req.body.category,
                price: req.body.price,
                serving: req.body.serving,
                time: req.body.time,
                calorie: req.body.calorie,
                rate: req.body.rate
            }
        })
        .exec()
        .then(()=>{
            console.log("Successfully updated name: " + req.body.name);
            res.redirect("/user/admin_page");
        })
        .catch(err => {
            console.log(err);
        });
    });
});

router.get("/remove", (req,res) =>{
    res.render("user/remove");
});

router.post("/remove",(req,res)=>{    
    mealModule.deleteOne({name: req.body.name})
    .exec()
    .then(() => {        
        console.log("removed menu")
        res.redirect("user/admin_page");
    })
    .catch(err => {
        console.log(err);
    });      
});

router.get("/upload",(req, res) => {
    res.render("user/upload");
});
router.post("/upload",(req, res) => {
    const newMenu = new mealModule({
        name: req.body.name,
        ingredient: req.body.ingredient,
        category: req.body.category,
        description: req.body.description,
        price: req.body.price,
        serving: req.body.serving,
        time: req.body.time,
        calorie: req.body.calorie,
        rate: req.body.rate
    });

    newMenu.save()
    .then((newMenuSaved) => {
        console.log(`Menu ${newMenuSaved.name} has been saved on the server`);

        req.files.image.name = `D_signature_${newMenuSaved._id}${path.parse(req.files.image.name).ext}`;

        req.files.image.mv(`static/uploads/${req.files.image.name}`)
        .then(()=>{
            mealModule.updateOne({
                _id: newMenuSaved._id
            },
            {
                imageUrl: `/uploads/${req.files.image.name}`
            })
            .then(()=>{
                console.log("Menu was updated with Picture");
                req.session.menus = newMenu;

                res.redirect("/menu/upload");
            });
        });
    })
    .catch((err) => {
        console.log(`Error adding menu to the database. ${err}`);
    });
});

router.get("/",(req, res) => {       
    mealModule.find()
    .exec()
    .then((menu)=>{
        let topRecipe = [];
        menu = menu.map(value=> value.toObject());
        for(var i = 0; i < menu.length; i++){
            if(menu[i].isTopMeal)
                topRecipe.push(menu[i]);
        }
        res.render("meal/category", {
            topMenu: topRecipe,
            items: menu
        })

    })
    .catch((err) =>{
        console.log(err);
    });
});
router.get("/casual",(req, res) => {
    mealModule.find({category: "casual"})
    .exec()
    .then((casualMenu)=> {
        let menuCategory;
        casualMenu = casualMenu.map(value => value.toObject());
        menuCategory = casualMenu[0].category.toUpperCase();
        res.render("meal/meal", {
            category: menuCategory,
            items: casualMenu
        });

    })
    .catch(err =>{
        console.log(err);
    })
});
router.get("/classic",(req, res) => {
    mealModule.find({category: "classic"})
    .exec()
    .then((classicMenu)=> {
        let menuCategory;
        classicMenu = classicMenu.map(value => value.toObject());
        menuCategory = classicMenu[0].category.toUpperCase();
        res.render("meal/meal", {
            category: menuCategory,
            items: classicMenu
        });

    })
    .catch(err =>{
        console.log(err);
    });
});
router.get("/ethnic",(req, res) => {
    mealModule.find({category: "ethnic"})
    .exec()
    .then((ethnicMenu)=> {
        let menuCategory;
        ethnicMenu = ethnicMenu.map(value => value.toObject());
        menuCategory = ethnicMenu[0].category.toUpperCase();
        res.render("meal/meal", {
            category: menuCategory,
            items: ethnicMenu
        });
    })
    .catch(err =>{
        console.log(err);
    });
  
});
router.get("/seasonal",(req, res) => {
    mealModule.find({category: "seasonal"})
    .exec()
    .then((seasonalMenu)=> {
        let menuCategory;
        seasonalMenu = seasonalMenu.map(value => value.toObject());
        menuCategory = seasonalMenu[0].category.toUpperCase();
        res.render("meal/meal", {
            category: menuCategory,
            items: seasonalMenu
        });
    })
    .catch(err =>{
        console.log(err);
    });
});
module.exports = router;