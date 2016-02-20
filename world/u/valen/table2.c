//created by vikee for xlqy-zq station Spring Holiday gift.
//2001-1-9 23:02

//说明:需要把cheer1和cheer2两文件放到和你宏定义的目录一致的目录里.

#include <ansi.h>

#define CHEER1 "/u/tianlin/cheer1" 
#define CHEER2 "/u/tianlin/cheer2"
#define CHEER3 "/u/tianlin/cheer3"
#define CHEER4 "/u/tianlin/cheer4"
#define CHEER5 "/u/tianlin/cheer5"
#define CHEER6 "/u/tianlin/cheer6"
#define CHEER7 "/u/tianlin/cheer7"


inherit ITEM;
int get_gift(string arg);
void create()
{
    set_name(HIY"礼物台" NOR ,({"gift table","table"}));
  set("long","这是古惑仔巫师为了照顾新手的礼物台，玩家可以在这里拿(take)礼物(gift)。");
  set("unit", "个");
  set("value", 1000000000000);
}
void init()
{
  if (!wizardp(this_player())) 
   set("no_get","连礼物台都想拿走？太贪心了吧!\n");
  add_action("get_gift","take");
}
int get_gift(string arg)
{
  object me = this_player();
  object lw;
  
  if (!userp(me))
      return notify_fail("你什么也没拿到。\n");
  if (arg!="gift")  
      return notify_fail("你要拿什么?\n");
      
  if (me->query("yudian/newyear")) 
      return notify_fail("你想起自己已经拿过礼物了,又把手缩了回来。\n");
 
  //combat_exp+daoxing < 500K的礼物
  //if (me->query("combat_exp")+me->query("daoxing")<500000)
  lw=new("/u/vikee/liwu1.c"); 
  //高手礼物
  //else 
 // {
 //  lw=new("/u/vikee/liwu2.c");
 // }
 //玩家如果幸运的话会得到很好的礼物.
 //条件:1.原始kar>28 
 //     2.random(2)*random(2)*random(2)*random(2)*random(2)*random(2)=1   1/32的概率.
 
// if (me->query("kar")>28 && random(2)*random(2)*random(2)*random(2)*random(2)*random(2))
 // {
 // 	  //把上面的gift销毁,避免玩家拿到两个礼物.
 // 	  destruct(lw);
 //// 	  lw=new("/u/vikee/liwu3.c");
 // }
 
  
  //清屏
  write(REF);
  
  //增加场景,随机显示两个图片.
  switch(random(7))
  	{
	  	case 0:
	  	cat(CHEER1);
	  	break;
	  	case 1:
	  	cat(CHEER2);
	  	break;
	  	case 2:
	  	cat(CHEER3);
	  	break;
	  	case 3:
	  	cat(CHEER4);
	  	break;
	  	case 4:
	  	cat(CHEER5);
	  	break;  	
	  	case 5:
	  	cat(CHEER6);
	  	break;  	
	  	case 6:
	  	cat(CHEER7);
	  	break;  	
  	}
  //礼物送到玩家身上.
  message_vision("$N从"HIY"礼物台"NOR"上取下一个礼物。\n"NOR, me ); 
  lw->move(me); 
  lw->set("owner",me->query("id"));
  //玩家设置属性.
  me->set("yudian/newyear",1);
  return 1;
}

