var c=document.getElementById("mainCanvas");
var ctx=c.getContext("2d");
ctx.mozImageSmoothingEnabled = false;
ctx.webkitImageSmoothingEnabled = false;
ctx.msImageSmoothingEnabled = false;
ctx.imageSmoothingEnabled = false;

var img = new Image();   // 创建一个<img>元素
img.src = './svg/player.svg'
img.onload = function(){
    console.log("Canvas Loaded")
    ctx.drawImage(img,30,30, 100, 100);
}
