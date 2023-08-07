var mongoose=require('mongoose') 
 
mongoose.connect("mongodb://127.0.0.1/benben",function(err){
    if(err) return console.log(err);
    console.log('连接成功');    
})
 
module.exports=mongoose