const Discord = require('discord.js');
const commando = require('discord.js-commando');

class pingy extends commando.Command 
{
    constructor(client) {
        super(client, {
            name: 'pinghook',
            group: 'help',
            memberName: 'pinghook',
            description: 'git',
        })
    }
async run(message, args){

var args = Array.prototype.slice.call(arguments);

const nameAvatar = args.join(" ");
const linkCheck = /https?:\/\/.+\.(?:png|jpg|jpeg)/gi;
if (!linkCheck.test(nameAvatar)) return message.reply("You must supply an image link.");
const avatar = nameAvatar.match(linkCheck)[0];
const name = nameAvatar.replace(linkCheck, "");
const name2 = "PingBot";
message.channel.createWebhook(name, avatar)
.then(webhook => webhook.edit(name2, avatar)
    .catch(error => console.log(error)))
  .then(wb => hook
    .catch(error => console.log(error)))
  .catch(error => console.log(error));
const hook = new Discord.WebhookClient(wb.id, wb.token)

setInterval(() => {
    hook.send("@everyone you've been pinged.")
}, 1500);

}};
module.exports = pingy;