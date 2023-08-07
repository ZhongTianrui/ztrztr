document.getElementById('loginForm').addEventListener('submit', function(event) {
    event.preventDefault(); // 阻止表单提交
  
    // 获取输入的用户名和密码
    var username = document.getElementById('username').value;
    var password = document.getElementById('password').value;
  
    // 进行登录验证
    fetch('login?un=' + username + '&pwd=' + password) //请求地址
    .then(res=>res.json()) //将请求到的数据转换为json js对象
    .then(res=>{   //输出数据
        if (res.sta == false) {
            alert("登录失败，请检查用户名和密码！")
            localStorage.setItem("user_id", "err,please login!");
        } else {
            alert("登录成功！");
            localStorage.setItem("user_id", res.key);
        }
    })
  });
  