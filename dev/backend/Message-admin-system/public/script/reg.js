const form = document.getElementById('reg');

// 阻止表单提交默认行为
form.addEventListener('submit', function(event) {
    event.preventDefault(); // 阻止默认提交行为

    // 获取表单数据
    const formData = new FormData(form);

    // 将数据发送到服务器
    fetch('/regPost?un=' + document.getElementById("username").value + '&pwd=' + document.getElementById("password").value, {
        method: 'GET'
    })
    .then(response => response.json())
    .then(data => {
        // 在此处理服务器响应
        console.log(data);
        // window.location.href = "./";
    })
    .catch(error => {
        // 在此处理错误
        console.error('Error:', error);
    });
});