const socket = io();
socket.on("connect", () => {
    console.log(socket.id);
    var un = "";
    un = prompt("Username:")
    if (un.length > 0) {
        socket.emit("con", un);
    }
    socket.on("ok", (arg) => {
        console.log(arg);
        socket.on("newMsg", (arg) => {
            var msgBox = document.getElementById('msgBox');
            var msg = document.createElement("li");
            msg.innerHTML = arg.un + " : " + arg.msg;
            msgBox.appendChild(msg);
        });
    });
    var btn = document.getElementById('send');
    btn.onclick=function(){
        var msg = prompt("Message:");
        socket.emit("sendMsg", {"un" : un, "msg" : msg});
    }
});