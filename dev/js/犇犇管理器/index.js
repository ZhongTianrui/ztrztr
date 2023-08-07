const https = require('https');
var url = 'https://www.luogu.com.cn/api/feed/list?page='
const express = require('express');
const app = express();
const path = require('path');
var mongoose=require('mongoose') 
var userModel=require('./user')

app.use(express.static(path.join(__dirname, '/')));
app.get('/', (req, res) => {
    var bendata = [];
    for (var i = 0; i <= 6; i ++) {
        const options = {
            hostname: url + i.toString(), // 替换为你要请求的API的主机名
            method: 'GET'
        };
        const req = https.request(url + i.toString(), (res) => {
            let data = '';
    
            res.on('data', (chunk) => {
                data += chunk;
            });
    
            res.on('end', () => {
                var feeds = data.feeds;
                bendata += feeds.result;
                const fs = require('fs');
                // fs.writeFile('res.txt', data, (error) => {
                //     if (error) {
                //         console.error(error);
                //     } else {
                //         console.log('File written successfully');
                //     }
                // });
    
            });
        });
    
        req.on('error', (error) => {
        console.error(error);
        });
    
        req.end();
    }
    var ans = [];
    for (var i = 0; i < bendata.length; i ++) {
        var useR = bendata[i].user;
        if (useR.name == req.query.name) {
            console.log(bendata[i].content);
            ans += bendata[i].content;
        }
    }
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});

