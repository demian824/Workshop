/************************************************************************************
* WEB322 – Assignment 2 (Winter 2021)
* I declare that this assignment is my own work in accordance with Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from
* any other source (including web sites) or distributed to other students.
*
* Name:         Wonchul Choi
* Student ID:   118362201
* Course:       Web322 NDD
*
************************************************************************************/

const path = require("path");
const express = require("express");
const exphbs = require('express-handlebars');
const app = express();

app.engine('.hbs', exphbs({
    extname: '.hbs',
    defaultLayout: 'main'
}));
app.set('view engine', '.hbs');
app.use(express.static("static"));
app.use(express.static(__dirname + "/public"));

const generalController = require("./controller/general");
const menuController = require("./controller/meal");

app.use("/", generalController);
app.use("/menu", menuController);

app.use((req, res) => {
    res.status(404).send("Page Not Found");
});

app.use(function(err, req, res, next){
    console.error(err.stack);
    res.status(500).send("Something borke!")
})
const HTTP_PORT = process.env.PORT || 8080;

function onHttpStart(){
    console.log("Express http server listening on : " + HTTP_PORT);
}

app.listen(HTTP_PORT, onHttpStart);