const https = require('https');
const fs = require("fs");
const express = require("express");
const bodyParser = require('body-parser');
const { json } = require('body-parser');
var request = require('request');
const { Console } = require('console');
url = 'https://www.luogu.com.cn/paste/'
Date.prototype.Format = function (fmt) {
  var o = {
      "M+": this.getMonth() + 1, //月份 
      "d+": this.getDate(), //日 
      "H+": this.getHours(), //小时 
      "m+": this.getMinutes(), //分 
      "s+": this.getSeconds(), //秒 
      "q+": Math.floor((this.getMonth() + 3) / 3), //季度 
      "S": this.getMilliseconds() //毫秒 
  };
  if (/(y+)/.test(fmt)) fmt = fmt.replace(RegExp.$1, (this.getFullYear() + "").substr(4 - RegExp.$1.length));
  for (var k in o)
  if (new RegExp("(" + k + ")").test(fmt)) fmt = fmt.replace(RegExp.$1, (RegExp.$1.length == 1) ? (o[k]) : (("00" + o[k]).substr(("" + o[k]).length)));
  return fmt;
}

var JSONcode;
decodeURI = ''
const app= express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json())
var ultra_spawned_time = {}
app.get('/api/getsid/${id}', (req, res)=>{
  console.log("NA  EU  AS")
var url="https://api.n.m28.io/endpoint/florrio-map-" + id + "-green/findEach/";
var username = "ztrztr";
var msg = "IAKIOI";
const express = require("express");
const app= express();
var requestData={
    //https://discord.com/api/oauth2/authorize?client_id=1099152271109005502&permissions=2415921152&scope=applications.commands%20bot
    // "text": "[" + username + "]{" + msg + "}",
    // "attachments": [
    //   {
    //     "title": "Rocket.Chat",
    //     "title_link": "https://rocket.chat",
    //     "text": "[" + username + "]{" + msg + "}",
    //     // "image_url": "https://chat.ztrztr.top/images/integration-attachment-example.png",
    //     "color": "#764FA5"
    //   }
    // ]
  };
 
httprequest(url,requestData);
 
function httprequest(url,data){
    request({
        url: url,
        method: "GET",
        json: true,
        headers: {
            "content-type": "application/json",
        },
        // body: requestData
    }, function(error, response, body) {
        if (!error && response.statusCode == 200) {
            res.send({"data" : body.servers["vultr-miami"].id + " " + body.servers["vultr-frankfurt"].id + " " + body.servers["vultr-tokyo"].id}); 
        }
    });
};
});
app.get('/api/fc_rec', (req, res)=>{
  res.header('Access-Control-Allow-Origin', '*');
  console.log("fc_rec")
  res.send({"update" : "2"});
});
app.get('/api/fn_u', (req, res)=>{
  res.header('Access-Control-Allow-Origin', '*');
  console.log("fc_rec")
  res.send({"update" : "6", msg : "v1.6，修复服务器问题。"});
});
app.get('/api/fn_n', (req, res)=>{
  res.header('Access-Control-Allow-Origin', '*');
  console.log("fc_rec")
  res.send({"update" : "1", msg : "New UPDATE!"});
});
app.get('/api/lh_u', (req, res)=>{
  res.header('Access-Control-Allow-Origin', '*');
  console.log("fc_rec")
  res.send({"u" : 1, msg : ""});
});
app.get('/api/fc_send', (req, res)=>{

var url="https://chat.ztrztr.top/hooks/642904a166a580d8d2c7580c/XkAf4G9yfvEXNLLChLwYvqKoScmv3E8heyLSZkAgPC6cqCjk";
var username = req.query.un;
var msg = req.query.sid;
var img = "https://cdn.luogu.com.cn/upload/usericon/602124.png";
console.log(img);
  var requestData={
    "text": "Ultra or Super Spawned!",
    "attachments": [
      {
        "title": msg,
        "text": msg, 
        "image_url": img,
        "color": "#764FA5"
      }
    ]
  };
 
httprequest(url,requestData);
 
function httprequest(url,data){
    request({
        url: url,
        method: "POST",
        json: true,
        headers: {
            "content-type": "application/json",
        },
        body: requestData
    }, function(error, response, body) {
        if (!error && response.statusCode == 200) {
            console.log(body) // 请求成功的处理逻辑
        }
    });
};
res.send({ok : 'ok'});
});
app.get('/api/luogu', (req, res)=>{
  url = 'https://www.luogu.com.cn/paste/' + req.query.url;
  keycode = req.query.keycode;
  // JSONtt = ''
  console.log(url);
  https.get(url, (ress) => {
    let data = '';
    
    ress.on('data', (chunk) => {
      data += chunk;
    });
  
  
    ress.on('end', () => {
      // console.log(data.substring(data.search('decodeURIComponent') + 20, data.search('feConfigVersion') - 12));
      decodeURI = data.substring(data.search('decodeURIComponent') + 20, data.search('feConfigVersion') - 12)
      // console.log(unescape(decodeURI));
      JSONcode = JSON.parse(decodeURIComponent(unescape(decodeURI)));
      console.log(JSONcode.currentData.paste.user);
      // console.log(keycode);
      // console.log(JSONcode.currentData.paste.data);
      if (keycode == JSONcode.currentData.paste.data) res.send(JSONcode.currentData.paste.user);
      else res.send({'isOK' : false});
      
    });
  }).on('error', (err) => {
    console.log('Error: ', err.message);
  });
  
  
  
});

app.get('/api/luogu/page', (req, res)=>{
    res.header('Access-Control-Allow-Origin', '*');
    url = 'https://www.luogu.com.cn/' + req.query.url;
    keycode = req.query.keycode;
    // JSONtt = ''
    console.log(url);
    https.get(url, (ress) => {
      let data = '';
      
  
      ress.on('data', (chunk) => {
        data += chunk;
      });
    
    
      ress.on('end', () => {
        // console.log(data)
        decodeURI = data.substring(data.search('decodeURIComponent') + 20, data.search('feConfigVersion') - 12)
        console.log(data.search('Redirecting to /auth/login'))
        var needLogin = data.search('Redirecting to /auth/login')
        if (needLogin != -1) {
          res.send({'needLogin' : true})
        } else {
          console.log(decodeURIComponent((decodeURI)))
        // console.log(unescape(decodeURI));
        JSONcode = JSON.parse(decodeURIComponent((decodeURI)));
        // console.log(JSONcode.currentData.paste.user);
        // console.log(keycode);
        // console.log(JSONcode.currentData.paste.data);
        JSONcode['needLogin'] = false
         res.send(JSONcode);
        // else res.send({'isOK' : false});
        }
        
      });
    }).on('error', (err) => {
      console.log('Error: ', err.message);
    });
    
    
    
  });

app.post('/api/chat-bot', (req, res)=>{
    console.log(req.body);
    console.log("---------------------------------------\n-------------------------------------\n");
    var Json = req.body;
    let sd;
    let uuu = Json.text.substring(1);
    url = 'https://www.luogu.com.cn/' + uuu;
    keycode = req.query.keycode;
    // JSONtt = ''
    console.log(url);
    console.log(Json);
    // if (Json.cmd == "help") {
        // console.log(data)

      // res.send({
      //   "text": "Example message",
      //   "attachments": [
      //     {
      //       "title": "Help",
      //       "title_link": "https://chat.ztrztr.top",
      //       "text": "The Bot of OIchat",
      //       "color": "#764FA5"
      //     }
      //   ]
      // })
    // } else {
    // res.send({
    //   "text": "Example message",
    //   "attachments": [
    //     {
    //       "title": "Err",
    //       "title_link": "https://chat.ztrztr.top",
    //       "text": "Cmd bot found!",
    //       "color": "#764FA5"
    //     }
    //   ]
    // })
  // }
  https.get(url, (ress) => {
    let data = '';
    
    ress.on('data', (chunk) => {
      data += chunk;
    });
  
  
    ress.on('end', () => {
      decodeURI = data.substring(data.search('decodeURIComponent') + 20, data.search('feConfigVersion') - 12)
      console.log(data.search('Redirecting to /auth/login'))
      var needLogin = data.search('Redirecting to /auth/login')
      if (needLogin != -1) {
        res.send({
          "text": "Example message",
          "attachments": [
            {
              "title": "Help",
              "title_link": "https://chat.ztrztr.top",
              "text": "This page need login.",
              "color": "#764FA5"
            }
          ]
        })
      } else {
        console.log(decodeURIComponent((decodeURI)))
      // console.log(unescape(decodeURI));
      JSONcode = JSON.parse(decodeURIComponent((decodeURI)));
      // console.log(JSONcode.currentData.paste.user);
      // console.log(keycode);
      // console.log(JSONcode.currentData.paste.data);
      JSONcode['needLogin'] = false
      res.send({
        "text": "Example message",
        "attachments": [
          {
            "title": "Help",
            "title_link": "https://chat.ztrztr.top",
            "text": "JSONcode",
            "color": "#764FA5"
          }
        ]
      })
      // else res.send({'isOK' : false});
      }
      
    });
  }).on('error', (err) => {
    console.log('Error: ', err.message);
  });
  });

app.listen(8084, ()=>{
  console.log('Server is running at http://localhost:8084')
  var ntime = new Date().Format("yyyy-MM-dd HH:mm:ss");
  console.log(ntime)
})
