// yuebing 月饼


inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(RED"国庆节红包"NOR, ({"hongbao", "gift"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是国庆节给大家的礼物.。\n");
                set("unit", "只");
                set("no_get", 1);
                set("no_give", 1);
           
        }
}
void init()
{
add_action("do_open","open");
}
int do_open()
{object me;
me = this_player();
if(!me->query("marks/hongbao"))
{
message_vision("$N用着颤抖的双手缓缓地打开了红包。\n",me);
me -> add("combat_exp",5000);
me -> add("potential",3000);
tell_object(me,"你被奖励了五千点实战经验,三千点潜能。\n");
me->set("marks/hongbao",1);
}
else tell_object(me,"你已经拿过一次红包了，还想拿？\n");
destruct(this_object());
return 1;
}
