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

router.get("/",(req, res) => {
    res.render("general/home");
});
router.get("/about_us",(req, res) => {
    res.render("general/about_us");
});



module.exports = router;