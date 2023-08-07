function main(){
        
    var canvas = document.querySelector('#cavsImage');
    var ctx = canvas.getContext('2d');

    canvas.width = document.body.clientWidth ;
    canvas.height = document.body.clientHeight;
    window.addEventListener("resize", main);
    var img1 = new Image();
    let X = canvas.width / 2;
    let Y = canvas.height / 2;
    img1.src='https://static.florr.io/ca98bcc0846732e3d21650a7290d23b7d66139fa/favicon-32x32.png';
    img1.onload = function() {
        ctx.drawImage(img1,X, Y)
        // ctx.drawImage(img1,15,70,70,70,350,350,210,210);
    };
    // for (let i = 0; i <= 100; i++) {
    //     ctx.clearRect(0, 0, X * 2, Y * 2);
    //     setTimeout(() => {
    //         cls(canvas, ctx)
    //         ctx.drawImage(img1,X - i * 1,Y - i * 1);
    //     }
    //     , 10 * i)
    //     console.log(X, Y);
    // }
    draw(img1, 10, 10000, canvas, ctx, X, Y);
}
function draw(img, speed, dis, canvas, ctx, X, Y) {
    for (let i = 0; i <= dis; i++) {
        // ctx.clearRect(0, 0, canvas.width, canvas.height);
        setTimeout(() => {
            // cls(canvas, ctx)
            ctx.drawImage(img,X - i * 1, Y - i * 1);
        }
        , speed * i)
        // console.log(X, Y);
    }
}
function cls(canvas, ctx){
    ctx.clearRect(0, 0, canvas.width, canvas.height);
}