#include <ansi.h>

inherit ITEM;
string *names = ({ "快乐豆", "蹦蹦糖", "开心果","麦当劳","肯德基" });
string *msg_eat=({HIR"$N吃着快乐豆，高兴的叫到:我好happy,我好happy..\n",
                  HIC"$N把蹦蹦糖放都嘴里，嘴里噼里啪啦一顿乱响,心情无比舒畅.\n",
                  HIM"$N一边吃着开心果,一边回想着自己在MUD中成长的经历,真是感慨万千..\n",
                  HIY"$N吃着麦当劳里的薯条和鸡翅，感动的口水直流.\n",
                  HIG"$N吃着里肯德基的薯条和鸡块，一副心满意足的样子.\n",                  
                        });
                        
int do_eat(string arg);
void create()
{
  int num;
  num=random(sizeof(names));
  set_name(names[num],({"gift"}));
  
  set("unit","个");
  set("value", 0);
  set("long","祝你在新的一年里工作顺利！学习进步！身体健康！万事如意！");
  setup();
}

void init()
{
   if (!wizardp(this_player())) {
    set("no_get","这个东西象占在地上，怎么也拿不起来。\n");
    set("no_give","你疯了？新年礼物还送人?\n");
    set("no_drop","这么珍贵的礼物，扔了多可惜呀！\n");
    set("no_sell","这东西不能卖。\n");
   }
  if(this_player()==environment())
  add_action("do_eat", "eat");

}

int do_eat(string arg)
{
  string msg;
  object me=this_player();  
  int get_qn,get_wx,get_dx;
  int my_exp,my_dx,my_kar;

  if (!arg && arg!="gift")
    return notify_fail("你要吃什么?\n");  

  if (this_object()->query("owner")!=me->query("id"))
    return notify_fail("你突然觉得反胃，吃的东西都吐了出来!\n");  
	    
//  msg=msg_eat[random(sizeof(msg_eat))];  
  if (this_object()->query("name")=="快乐豆")
  msg=msg_eat[0]; 
  if (this_object()->query("name")=="蹦蹦糖")
  msg=msg_eat[1];  
  if (this_object()->query("name")=="开心果")
  msg=msg_eat[2];  
  if (this_object()->query("name")=="麦当劳")
  msg=msg_eat[3];  
  if (this_object()->query("name")=="肯德基")
  msg=msg_eat[4];  

  message_vision(msg+"\n"NOR, me );  
  
  my_exp=me->query("combat_exp");
  my_dx=me->query("daoxing");
  my_kar=me->query("kar");

   get_qn=(random(2000)+6000)*my_kar/39;
   get_wx=(random(10000)+20000)*my_kar/39;
    get_dx=(random(1000)+6000)*my_kar/39;
  if ((my_exp+my_dx)<1000000)
  {
	get_qn=get_qn/2;
	get_wx=get_wx/2;
	get_dx=get_dx/2;
  }
  
  if (random(2)*random(2)*random(2)*random(2)*random(2)*random(2))
  {
	get_qn=get_qn*2;
	get_wx=get_wx*1.5;
	get_dx=get_dx*1.2;
  }

if ((my_exp+my_dx)<100000)
  {
         get_qn=2000+random(500);
         get_wx=3000+random(500);
         get_dx=1000+random(500);
  }

  me->add("potential",get_qn);  
  me->add("combat_exp",get_wx);
  me->add("daoxing",get_dx);
  
  tell_object(me,HIW"你的奖励是：\n" +
  chinese_number(get_wx) + "点武学\n"+        
  COMBAT_D->chinese_daoxing(get_dx) + "道行\n"+        
  chinese_number(get_qn) + "点潜能\n" NOR);
    
  destruct(this_object());
  return 1;
}

