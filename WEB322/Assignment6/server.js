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
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
const session = require("express-session");
const fileUpload = require("express-fileupload");
const dotenv = require('dotenv');
dotenv.config({path:"./config/keys.env"});
const app = express();

app.engine('.hbs', exphbs({
    extname: '.hbs',
    defaultLayout: 'main'
}));
app.set('view engine', '.hbs');
app.use(session({
    secret: process.env.SESSION_SECRET,
    resave: false,
    saveUninitialized: true
}));
app.use((req, res, next) =>{
    res.locals.user = req.session.user;
    next();
});

app.use(express.static("static"));
app.use(express.static(__dirname + "/public"));
app.use(bodyParser.urlencoded({extended:false}));
app.use(fileUpload());
const generalController = require("./controller/general");
const menuController = require("./controller/meal");
const userController = require("./controller/users");

app.use("/", generalController);
app.use("/menu", menuController);
app.use("/user", userController);

mongoose.connect(process.env.MONGO_DB_CONNECTION_STRING, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    useCreateIndex: true
})
.then(() => {
    console.log("Connected to the MongoDB database.");
})
.catch((err) => {
    console.log(`There was a problem connecting to MongoDB ... ${err}`)
});



app.use((req, res) => {
    res.status(404).send("Page Not Found");
});

app.use(function(err, req, res, next){
    console.error(err.stack);
    res.status(500).send("Something borke!")
})
const HTTP_PORT = process.env.PORT;

function onHttpStart(){
    console.log("Express http server listening on : " + HTTP_PORT);
}

app.listen(HTTP_PORT, onHttpStart);