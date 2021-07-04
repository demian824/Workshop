const bcrypt = require("bcryptjs");
const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const userSchema = new Schema({
    firstName: 
    {
        type: String,
        required: true
    },
    lastName: 
    {
        type: String,
        required: true
    },
    email:
    {
        type: String,
        required: true,
        unique: true
    },
    pwd:
    {
        type: String,
        required: true
    },
    userType:{
        type: String,
        default: "user"
    },
    dateCreated: {
        type: Date,
        default: Date.now()
    }
});

const adminAccout = {
    firstName: "admin",
    lastName: "",
    email:  "admin@admin.com",
    pwd:    "master",
    userType:   "admin",
    dateCreated: Date.now()
};

userSchema.pre("save", function(next) {
    var user = this;

    bcrypt.genSalt(10)
    .then((salt) => {      
        bcrypt.hash(user.pwd, salt)
        .then((encryptedPwd) => {
            user.pwd = encryptedPwd;
            next();
        })
        .catch((err) => {
            console.log(`Error occured when hashing. ${err}`);
         });
    })
    .catch((err) => {
        console.log(`Error occured when salting. ${err}`);
     });
 });

const userModel = mongoose.model("Users", userSchema);

module.exports = userModel;