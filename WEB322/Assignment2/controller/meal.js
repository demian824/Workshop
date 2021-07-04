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

router.get("/",(req, res) => {
    res.render("meal/category",{
        topMenu: mealModule.getTopMeal()
    });
});
router.get("/casual",(req, res) => {
    res.render("meal/meal",{
        items: mealModule.getCasual()
        
    });
});
router.get("/classic",(req, res) => {
    res.render("meal/meal",{
        items: mealModule.getClassic()
    });
});
router.get("/ethnic",(req, res) => {
    res.render("meal/meal",{
        items: mealModule.getEthnic()
    });
});
router.get("/seasonal",(req, res) => {
    res.render("meal/meal",{
        items: mealModule.getSeasonal()
    });
});
module.exports = router;