/************************************************************************************
* WEB322 – Assignment 1 (Winter 2021)
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
const app = express();

app.use(express.static("static"));
app.get("/",(req, res) => {
    res.sendFile(path.join(__dirname, "/views/home.html"));
});
app.get("/login_page",(req, res) => {
    res.sendFile(path.join(__dirname, "/views/login_page.html"));
});
app.get("/menu",(req, res) => {
    res.sendFile(path.join(__dirname, "/views/menu.html"));
});
app.get("/register_page",(req, res) => {
    res.sendFile(path.join(__dirname, "/views/register_page.html"));
});
app.get("/about_us",(req, res) => {
    res.sendFile(path.join(__dirname, "/views/about_us.html"));
});
app.get("/", (req, res) =>{
    const headers = req.headers;
    res.send(headers); 
})

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