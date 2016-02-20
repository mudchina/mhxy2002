// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// lumber_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
        set_name("铁斧", ({ "lumber axe", "axe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把沈重的铁斧，用来砍柴。\n");
                set("value", 200);
                set("wield_msg",
"$N拿出一把砍柴用的$n，握在手中当作武器。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_axe(15, TWO_HANDED);
        setup();
}


void init()
{
  add_action("do_kan", "kan");
}

int do_kan(string arg)
{
   object me=this_player();
   string env;
  if(me->is_busy())
    return notify_fail ("你正忙着呢！\n");
   if(!me->query("lingtai/kancai"))
     return notify_fail("您来砍材，这怎么敢当呢？\n");
   if(!arg && arg != "cai" )
     return notify_fail("你要砍什么？\n");
   env=environment(me)->query("short");
   if(env!="枯松坪"&&env!="松树林")
     return notify_fail("开玩笑,这里哪有什么材给你砍.\n");
   if(environment(me)->query("clean"))
     return notify_fail("这儿的材被您砍玩了\n");
   if((int)me->query("kee") <80)
     return notify_fail("你太累了，歇歇吧！\n");
   message_vision("$N举起斧头,用力的砍着.\n", me);
   write("只见一堆堆整齐的干材放在地上.\n");
    call_out("finish_kan",5,me);
  me->start_busy(5);
   return 1;
}
void finish_kan(object ob)
{
   object me=ob;
   object where=environment(me);
   message_vision("$N抹了一把汗，得意的笑了笑。你已经把这一片的材都砍完拉.\n",
me);
   me->receive_damage("kee", 60);
   where->set("clean",1);
   me->delete("lingtai/shaodi");
   tell_object(me,"你觉得在劳累之余也有所收获。\n");
   tell_object(me,"你的经验和扑击格斗之术提高了。\n");
   me->improve_skill("unarmed",random(me->query("int")),1);
   me->add("faith",1);
   me->add("combat_exp",8);
   me->add("potential",3);
   this_object()->move(find_living("dao shi"));
}
