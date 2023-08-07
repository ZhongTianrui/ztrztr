var main = document.getElementsByClassName("container");
fetch('getfromid?key=' + localStorage.getItem("user_id")) //请求地址
.then(res=>res.json()) //将请求到的数据转换为json js对象
.then(res=>{   //输出数据
    if (res.sta == false) {
        alert("请登录!")
    } else {
        alert("你好，" + res.un + ",欢迎来到本次活动，公告：暂无");
    }
})