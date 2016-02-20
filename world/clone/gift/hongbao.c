#include <ansi.h> //调用颜色
inherit ITEM;       //物品类型
int do_open(string arg); //动作
void create()
{
  set_name(HIR "红包" NOR,({"hong bao","bao"})); //名字 id 设定
  set("long","这是一份红包，你可以试着打开("+HIR+"open"+NOR+")来看看。"); //look设定
  set("unit","份"); //单位
  set("value", 0); //价值
  setup(); 
}
void init()
{
   if (!wizardp(this_player())) {
    set("no_get","这个东西拿不起来。\n"); //除了wiz player不能做到的事情
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("no_sell","这东西不能卖。\n");
   }
    if(this_player()==environment())
      add_action("do_open", "open"); //行动
}
int do_open(string arg)
{
  object me=this_player();
  if (!arg && arg!="bao") return notify_fail("你要打开什么?\n"); //行动目标
  if (me->query("newyear_hongbao")) return notify_fail("你已经拿过红包了怎么还想要！！！\n"); 
  message_vision(HIR"$N把礼物盒轻轻的打开，恭喜发财！！恭喜发财！！！\n" NOR,me); //打开礼物时的描述
  me->add("balance",5000000);   //加rsg 1个
  tell_object(me,HIW"你被奖励了：\n" +
  "500gold钱庄存款！\n" NOR); //奖励说明
  me->set("newyear_hongbao",1); //做标记
  destruct(this_object());
  return 1; //传回

}