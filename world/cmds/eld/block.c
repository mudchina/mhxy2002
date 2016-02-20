// block.c
// modified by mon 7/25/97

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string option, target;

	if( !arg) {
         CHANNEL_D->do_channel(me,"chat*",sprintf("拿着胶布四处张望,看看贴在谁的嘴上比较合适。"));
         return notify_fail("你要关掉／或打开谁的频道？\n");
          }
        if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;
	if ( option != "-s" && option != "-u" ) target = arg;

	obj = find_player(target);
        if(!obj) return notify_fail("没有这个人．．．\n");

	if(option=="-s") {  // say, tell, reply, emote and whisper,chat
	  if( wizardp(obj)) return notify_fail("有必要吗？\n");
	  obj->set("channel/tell_block",time()+86400);
          obj->set("channel/chat_block",time()+86400);
	  tell_object(obj, "你的所有频道被暂时关闭了！\n");
	  CHANNEL_D->do_channel(me,"chat*",sprintf("气急败坏的说,你这个小兔崽子,居然还有这么多废话,看来不治治是不行了!!!"));
          CHANNEL_D->do_channel(me,"chat*",sprintf("说罢,从工具箱中拿出一大块胶布,把"+obj->query("name")+"的嘴给贴的严严实实。"));  
        } else if(option=="-u") { // open channel
          obj->delete("channel/tell_block");
          obj->delete("channel/chat_block");
	  tell_object(obj, "你的频道被打开了！\n");
	  CHANNEL_D->do_channel(me,"chat*", sprintf("恶狠狠的说,看你以后还敢不敢乱说话了,然后把" + obj->query("name") + "嘴上的胶布撕了下来。"));
          CHANNEL_D->do_channel(me,"chat", sprintf(obj->query("name")+"既然有悔过自新的想法,就暂时解除惩罚吧。"));
	} else {  // chat and rumor
	  // block chat and rumor for 24 hours. (24*3600 sec).
	  if( wizardp(obj)) return notify_fail("有必要吗？\n");
          obj->set("channel/chat_block",time()+86400);
	  tell_object(obj, "你的公用频道被暂时关闭了！\n");
          CHANNEL_D->do_channel(me,"chat*",sprintf("从工具箱中取出一块胶布,贴在"+obj->query("name")+"嘴上。")); 
          CHANNEL_D->do_channel(me,"chat",sprintf( obj->query("name")+ "废话太多,罚其闭嘴思过!\n"));
        }

	return 1;

}

int help(object me)
{
   write(@HELP
指令格式： block <某人>     暂时关掉某人的chat和rumor频道。
           block -s <某人>  暂时关掉某人的say，reply，emote，tell和whisper。
           block -u <某人>  恢复某人的所有通道。

HELP
   );
   return 1;
}
