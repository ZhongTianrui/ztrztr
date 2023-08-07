const { createServer } = require("http");
const { Server } = require("socket.io");

const httpServer = createServer();
const io = new Server(httpServer, {
    cors: true
  });

io.on("connection", (socket) => {
    console.log("User " + socket.id + " connected to ZChat!");
});

httpServer.listen(3001);