const express = require('express');
const cors = require("cors");
const jwt = require('jsonwebtoken');
const passport = require("passport");
const passportJWT = require("passport-jwt");
const dotenv = require("dotenv");
const bodyParser = require('body-parser');

dotenv.config();

const userService = require("./user-service.js");

const app = express();

var ExtractJwt = passportJWT.ExtractJwt;
var JwtStrategy = passportJWT.Strategy;

var jwtOptions = {};
jwtOptions.jwtFromRequest = ExtractJwt.fromAuthHeaderWithScheme("jwt");

jwtOptions.secretOrKey = process.env.JWT_SECRET;

var strategy = new JwtStrategy(jwtOptions, function (jwt_payload, next) {
    console.log('payload received', jwt_payload);

    if (jwt_payload) {   
        next(null, { _id: jwt_payload._id, 
            userName: jwt_payload.userName}); 
    } else {
        next(null, false);
    }
});


passport.use(strategy);
app.use(express.json());
app.use(bodyParser.json());
app.use(cors());

const HTTP_PORT = process.env.PORT || 8080;

/* TODO Add Your Routes Here */
app.get("/", (req, res) =>{
    res.send(`{message: \"API Listening\"}`);
})
app.post("/api/user/register", (req, res) => {
    res.send(`{message: \"register\"}`);
    userService.registerUser(req.body)
        .then((msg) => {
            res.json({ "message": msg });
        }).catch((msg) => {
            res.status(422).json({ "message": msg });
        });
});

app.post("/api/user/login", (req, res) => {
    res.send(`{message: \"login\"}`);
    console.log("favourite");
    userService.checkUser(req.body)
        .then((user) => {

            var payload = { 
                _id: user._id,
                userName: user.userName               
            };

            var token = jwt.sign(payload, jwtOptions.secretOrKey);

            res.json({ "message": "login successful", "token": token });
        }).catch((msg) => {
            res.status(422).json({ "message": msg });
        });
});

app.get("/api/user/favourites", passport.authenticate('jwt', { session: false }), (req,res)=>{
    res.send(`{message: \"favourites\"}`);
    userService .getFavourites().then((req)=>{
        res.json(req.user._id);
    }).catch((msg)=>{
        res.status(500).json({ "message": msg });
    });
});

app.put("/api/user/favourites/:id", passport.authenticate('jwt', { session: false }), (req,res)=>{
    res.send(`{message: \"favourites\"}`);
    userService .addFavourites(req.user._id).then((req)=>{
        res.json(req.user._id, req.params.id);
    }).catch((msg)=>{
        res.status(500).json({ "message": msg });
    });
});

app.delete("/api/user/favourites/:id", passport.authenticate('jwt', { session: false }), (req,res)=>{
    res.send(`{message: \"delete\"}`);
    userService .removeFavourite(req.user._id, req.params.id).then((req)=>{
        res.json(req.user._id, req.params.id);
    }).catch((msg)=>{
        res.status(500).json({ "message": msg });
    });
});
userService.connect()
.then(() => {
    app.listen(HTTP_PORT, () => { console.log("API listening on: " + HTTP_PORT) });
})
.catch((err) => {
    console.log("unable to start the server: " + err);
    process.exit();
});
