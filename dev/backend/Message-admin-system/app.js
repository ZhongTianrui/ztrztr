//this js was the main code of this project,all proccess will begin in here!
const express = require("express");
const { Server } = require("socket.io");
const { createServer } = require("http");
const path = require('path');
const crypto = require('crypto')
//引入mongoose
const mongoose = require('mongoose');
//定义字符串常量
const db_url = "mongodb://localhost:27017/2023824"
mongoose.connect("mongodb://127.0.0.1/2023824",function(err){
    if(err) return console.log(err);
    console.log('连接成功');
})
//2.连接成功
mongoose.connection.on('connected',function(){
    console.log('[DB] Database connected!',db_url);
})
//3.连接失败
mongoose.connection.on('error',function(err){
    console.log('[DB] Database err,',err);
})
//4.断开连接
mongoose.connection.on('disconnection',function(){
    console.log('[DB] Database disconnect!');
})
const { Schema } = mongoose;

const UserSchema = new Schema({
    un:{
        type:String
    },
    pwd:{
        type:String
    },
    ID:{
        type:String
    },
});
//定义UserSchema的Schema
const UserModel = mongoose.model('UserModel',UserSchema)

// let Model = new UserModel({
//     un:'ztrztr',
//     pwd:'zz770011'
// })

// Model.save(function(err,res){
//     if(err){
//         console.log('[DB] Database Save error!',err);
//     }else{
//         console.log('[DB] Database save succes', res);
//     }
// })


const port = 3000;
const wsPort = 3000;

const app = express();
const httpServer = createServer(app);
const io = new Server(httpServer, {});

io.on("connection", (socket) => {
    console.log("[webSocket] An user connect,ID: " + socket.id);
});

app.use(express.static(path.join(__dirname, 'public')));
app.get('/', (req, res) => {
    console.log("[Server] \'/\' has been geted!");
    res.sendFile(__dirname + '/index.html');
});

app.get('/reg', (req, res) => {
    console.log("[Server] An user visited the reg page");
    res.sendFile(path.join(__dirname, 'public', 'reg.html'));
});

app.get('/login', (req, res) => {
    console.log("[Server] An user visited the login page");
    res.sendFile(path.join(__dirname, 'public', 'login.html'));
});

app.get('/notes', (req, res) => {
    console.log("[Server] An user visited the notes page");
    res.sendFile(path.join(__dirname, 'public', 'notes.html'));
});

//English
app.get('/zh/reg', (req, res) => {
    console.log("[Server] An user visited the zh-reg page");
    res.sendFile(__dirname, '/public/zh/reg.html')
});

app.get('/zh/login', (req, res) => {
    console.log("[Server] An user visited the zh-login page");
    res.sendFile(__dirname, '/public/zh/login.html')
});

app.get('/zh', (req, res) => {
    console.log("[Server] \'/\' has been geted!");
    res.sendFile(__dirname + '/public/zh/index.html');
});
//Chinese

app.get('/api/loginPost', (req, res) => {
    console.log("[Server] An user login!Form:" + req.query);
    // if (req.query.un == "ztrztr" && req.query.pwd == "zz770011") res.send({"ok" : true});
    // else res.send({"ok" : false});
    //记录数查询
    UserModel.countDocuments(req.query, function(err,data){
        if(err){
            console.log(err)
        }else{
            if (data >= 1) {
                console.log("[DB] Login succes")
                UserModel.find(req.query, function(err,dataa){
                    console.log({"ok" : true, "ID" : dataa[0].ID});
                    res.send({"ok" : true, "ID" : dataa[0].ID});
                });
            }
            else console.log(data), res.send({"ok" : false})
        }
    })

})
app.get('/api/getUserByID', (req, res) => {
    console.log("[Client] An user use getUserByID !Form:" + req.query);
    // if (req.query.un == "ztrztr" && req.query.pwd == "zz770011") res.send({"ok" : true});
    // else res.send({"ok" : false});
    //记录数查询
    UserModel.find({"ID":req.query.ID}, function(err,dataa){
        if (dataa.length > 0) res.send(dataa[0]);
        else res.send({"err":"NotFound!"})
    });

})
app.get('/api/regPost', (req, res) => {
    console.log("[Server] An user reg!Form:" + req.query);
    var b = 0;
    UserModel.countDocuments({"un" : req.query.un}, function(err,data){
        if(err){
            console.log(err)
        }else{
            if (data >= 1) {
                b = 1
            }
        }
    })
    var len = 10;
    var id = crypto.randomBytes(Math.ceil(len / 2)).toString('hex').slice(0, len);
    //创建模型
    console.log(id);
    let Model = new UserModel({
        username:req.query.un,
        password:req.query.pwd,
        ID:id
    })
    console.log(b)
    //2.同模型的sava([fn]),保存模型到数据库中
    if (b >= 1) res.send({"err" : "nameError"})
    else {
        console.log("111")
        // Model.save(function(err,ress){
        //     if(err){
        //         console.log('保存失败：',err);
        //         res.send({"err":err})
        //     }else{
        //         console.log(ress);
        //         res.send({"reg" : "ok"})
        //     }
        // })
        UserModel.create({"un" : req.query.un, "pwd": req.query.pwd, "ID" : id},function(err){
            if(err) {
                res.send("出现了一点问题。")
                return console.log(err);
            }
            console.log(id);
            console.log("1111")
            res.send({"ok" : true})
        })
    }
})
httpServer.listen(port);