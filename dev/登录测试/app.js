const express = require('express');
const app = express();
const path = require('path');
var mongoose=require('mongoose') 
var userModel=require('./user')
const crypto = require('crypto');

app.use(express.static(path.join(__dirname, '/')));
app.get('/li', (req, res) => {
  const filePath = path.join(__dirname, 'li.html');
  console.log("A user use /li");
  res.sendFile(filePath);
});

app.get('/', (req, res) => {
  const filePath = path.join(__dirname, 'index.html');
  console.log("A user use /");
  res.sendFile(filePath);
});

app.get('/re', (req, res) => {
    const filePath = path.join(__dirname, 're.html');
    console.log("A user use /re");
    res.sendFile(filePath);
  });

app.get('/login', (req, res) => {
    console.log("A user login");
    

    // if (req.query.un == "ztrztr" && req.query.pwd == "zz770011") {
    //     res.send("登录成功！");
    // } else {
    //     res.send("登录失败！");
    // }
    userModel.find(req.query, (err, ress) => {
        if (err) console.log(err);
        if (ress.length == 0) {
            console.log("Err");
            res.send({"sta" : false});
        } else {
            console.log("OK");
            //res.send("登录成功！账号 key:" + ress[0]._id + ", 你是否是 admin：" + ress[0].isadmin);
            res.send({"sta" : true, "key" : ress[0].id, "isadmin" : ress[0].isadmin})
        }
    })
  });

  app.get('/getfromid', (req, res) => {
    

    // if (req.query.un == "ztrztr" && req.query.pwd == "zz770011") {
    //     res.send("登录成功！");
    // } else {
    //     res.send("登录失败！");
    // }
    userModel.find({"id" : req.query.key}, (err, ress) => {
        if (err) console.log(err);
        if (ress.length == 0) {
            console.log("Err");
            res.send({"sta" : false});
        } else {
            console.log("OK");
            //res.send("登录成功！账号 key:" + ress[0]._id + ", 你是否是 admin：" + ress[0].isadmin);
            res.send({"sta" : true, "un" : ress[0].un, "isadmin" : ress[0].isadmin})
        }
    })
  });

  app.get('/reg', (req, res) => {
    console.log("A user reg");
    var ans = req.query;
    ans["isadmin"] = (req.query.un == "ztrztr"); 
    ans["id"] = crypto.randomBytes(Math.ceil(256 / 2)).toString('hex').slice(0, 256);
    userModel.find({"un" : req.query.un}, (err, ress) => {
        if (err) console.log(err);
        if (ress.length == 0) {
            userModel.create(ans,function(err){
                if(err) {
                    res.send("出现了一点问题。")
                    return console.log(err);
                }
                res.redirect("/")
            })
        } else {
            res.send("用户名已经被占用！")
        }
    })

  });

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});
