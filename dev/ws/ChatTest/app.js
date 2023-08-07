const express = require("express");
const { createServer } = require("http");
const { Server } = require("socket.io");

const app = express();
const httpServer = createServer(app);
const io = new Server(httpServer, { /* options */ });

app.use(express.static('back'));

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/back/index.html');
});  

io.on("connection", (socket) => {
    console.log("A User just connection to this server!");
    console.log("ID:" , socket.id);
    socket.on("con", (arg) => {
        console.log("username:", arg);
        io.emit("newMsg", {"un" : "[SYSTEM]", "msg" : arg + " 来了"});
        socket.emit("ok", arg)
    });
    socket.on("sendMsg", (arg) => {
        console.log(arg)
        io.emit("newMsg", arg);
    });
});

httpServer.listen(3000);