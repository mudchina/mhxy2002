// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit STICK;

void create()
{
        set_name("竹扫帚", ({"broom"}));
        set_weight(1000);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N把$n握在手中．\n");
        }
        init_stick(10);
        setup();
}

void init()
{
  add_action("do_shao", "sao");
}

int do_shao(string arg)
{
   object me=this_player();
   string env;
   
   if(me->query("class")!="taoist"||me->query("lingtai_quest/quest_type")!="打扫"
      ||me->query("lingtai_quest/done"))
     return notify_fail("您来扫地，这怎么敢当呢？\n");
   if(!arg && arg != "di" )
     return notify_fail("你要扫什么？\n");
   if(me->is_busy())return notify_fail("你正忙这呢！\n");

   env=environment(me)->query("short");
    if(env!=me->query("lingtai_quest/quest"))
     return notify_fail("可没有人要你来打扫这儿。\n");

   if((int)me->query("kee") <80)
     return notify_fail("你太累了，歇歇吧！\n");

   message_vision("$N挥舞着大扫帚扫起地来。\n", me);
   write("只见片片黄叶被你扫到一边。\n");
   me->start_busy(5);
   call_out("finish_shao",5,me);
   
   return 1;
}

void finish_shao(object me)
{
   message_vision("$N抹了一把汗，得意的笑了笑。庭子被你打扫得干干净净。\n", me);
   me->receive_damage("kee", 60);
   me->set("lingtai_quest/done",1);
   destruct(this_object());
}


