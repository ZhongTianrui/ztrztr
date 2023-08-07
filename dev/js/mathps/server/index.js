const express =  require("express");
const app = express();

const mongoose = require('mongoose');
const db_url = "mongodb+srv://ztrztr:zz770011@cluster0.ajplqtm.mongodb.net/mathps?retryWrites=true&w=majority"
mongoose.connect(db_url,{useNewUrlParser:true,useUnifiedTopology:true}) 
mongoose.connection.on('connected',function(){
    console.log('连接成功：',db_url);
})
mongoose.connection.on('error',function(err){
    console.log('连接错误：',err);
})
mongoose.connection.on('disconnection',function(){
    console.log('断开连接');
})
module.exports = mongoose;

//定义UserSchema的Schema
const UserSchema = mongoose.Schema({
    username:{
        type:String
    },
    password:{
        type:String
    },
    age:{
        type:Number
    }
});

const UserModel = mongoose.model('users',UserSchema)

app.get('/api/reg', (req, res) => {
    var name = req.query.name;
    var pw_MD5 = req.query.pw;
    let Model = new UserModel({
        username:name,
        password:pw_MD5,
    })
    Model.save(function(err,res){
        if(err){
            console.log(err);
        }else{
            console.log(res);
        }
    })
    // console.log('reg', req.query);
    res.send({ status: 0, message: 'success!' });
}); 
app.get('/api/login', (req, res) => {
    var name = req.query.name;
    var pw_MD5 = req.query.pw;
    let Model = new UserModel({
        username:name,
        password:pw_MD5,
    })
    var npw;
    npw = UserModel.count({username:name, password:pw_MD5}, function (err, cnt) {
      console.log(cnt);
    if (cnt > 0) {
        res.send({ status: 0, message: 'success!' });
    } else {
        res.send({ status: 0, message: 'faile!' });
    }
    });
    // console.log(npw);
    console.log('login:', req.query);
})
app.listen(
    3000,
    () => console.log("The server have started on port 3000,api started on /api")
);