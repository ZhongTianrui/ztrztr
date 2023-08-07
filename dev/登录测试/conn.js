var mongoose=require('mongoose') 
 
//这里的2017b是你的库名 如果没有他会自动创建
mongoose.connect("mongodb://127.0.0.1/2023723",function(err){
    if(err) return console.log(err);
    console.log('连接成功');
})
 
module.exports=mongoose