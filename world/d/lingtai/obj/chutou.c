// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit STICK;

void create()
{
        set_name("锄头", ({"hoe"}));
        set("no_drop",1);
        set_weight(1000);
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
  add_action("do_dig", "dig");
}

int do_dig(string arg)
{
   object me=this_player();
   string env;
   
    if(me->query("class")!="taoist"||me->query("lingtai_quest/quest_type")!="种地"
        ||me->query("lingtai_quest/done"))
     return notify_fail("您来种地，这怎么敢当呢？\n");
   if(!arg && arg != "di" )
     return notify_fail("你要挖什么？\n");

   if(me->is_busy())return notify_fail("你正忙这呢！\n");
   env=environment(me)->query("short");
   if(env!="菜园")
     return notify_fail("您在这儿乱挖什么？\n");

   if((int)me->query("kee") <80)
     return notify_fail("你太累了，歇歇吧！\n");

   message_vision("$N走到一块荒地上，抡起锄头，开始种地。\n", me);
   me->start_busy(8);
   call_out("dig1",2,me);
   call_out("dig2",4,me);
   call_out("dig3",6,me);
   call_out("finish_dig",8,me);
   
   return 1;
}

void dig1(object me)
{
   message_vision("$N擦了擦头上的汗水，继续干了起来。\n", me); 	
}
void dig2(object me)
{
   message_vision("$N歇了一会儿，倚着锄头，望着身后好的菜地，微微一笑。\n", me); 	
}
void dig3(object me)
{
   message_vision("快要结束了，$N顾不得擦头上的汗水，迅速挥动着锄头。\n", me); 	
}

void finish_dig(object me)
{
   message_vision("$N抹了一把汗，得意的笑了笑。身后是整整齐齐一片已开好的菜地。\n", me);
   me->set("lingtai_quest/done",1);
    destruct(this_object());
}


