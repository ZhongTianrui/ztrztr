    document.documentElement.addEventListener("keydown", function() {
		if (event.keyCode === 9) getServerId()
		else if (event.keyCode === 32 && event.shiftKey && event.ctrlKey) changeServer()
        else if (event.shiftKey && event.ctrlKey && event.keyCode === 65) {
            var message = prompt("哪个ultra？");
            var Sid = getsid();
            //这部分是检测用户是否正确报告，但是有一点问题，你帮我看一看
            let T = 0;
            console.log("ztr AK IOI");
            for (const { prototype } of getCompatibleCanvas()) {
                console.log("ztr AK IOI");
                if (openCustomReloadAnimation) {
                    //重写字符描边函数
                    prototype.strokeText = function(text, x, y) {
                        const newFontSize = getBlurFontSize(this.font);
                        this.font = getApplicableFontStr(newFontSize);
                        console.log("ztr AK IOI");
                        if (/An? \w\w\w\w\w .+ has spawned!/.test(text)) {
                            console.log("ultra!");
                        } else {
                            console.log("sad");
                            T = 1;
                            return;
                        }
                        //alertTargetStr(text, "Flower Health");
                        //consoleTextInfoLog(text, x, y);
                    }
                }
                if (T = 1) {
                    return;
                }
            }
            var httpRequest = new XMLHttpRequest();//第一步：建立所需的对象
            httpRequest.open('GET', 'https://api.ztrztr.top/api/fc_send?un=someone&sid=Ultra ' + message + ' spawned in ' + Sid + ' Server!', true);//第二步：打开连接  将请求参数写在url中  ps:"./Ptest.php?name=test&nameone=testone"
            httpRequest.send();//第三步：发送请求  将请求参数写在URL中

            httpRequest.onreadystatechange = function () {
                if (httpRequest.readyState == 4 && httpRequest.status == 200) {
                    var json = httpRequest.responseText;//获取到json字符串，还需解析
                    console.log(json);
                }
            };


        }
	});