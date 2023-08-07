var mongoose = require('./conn');
var Schema = mongoose.Schema;
//接受传参的类型  （请参考官方手册或文档）
var userSchema = new Schema({
    un: String,
    pwd: String,
    isadmin: Boolean,
    id: String
  });
///默认会操作第三个参数配置的表  user表（集合）
  var User=mongoose.model('User',userSchema,'user');
 
  module.exports=User