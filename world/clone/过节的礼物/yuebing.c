// yuebing 月饼


inherit ITEM;

void create()
{
        set_name("月饼", ({"yue bing", "bing"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是给大家的礼物.。\n");
                set("unit", "只");
                set("no_get", 1);
                set("no_give", 1);
           
        }
}
void init()
{
add_action("do_eat","eat");
}
int do_eat()
{object me;
me = this_player();
if(!me->query("mark/yuebing"))
{
message_vision("$N一口把月饼吞下了肚里。\n",me);
me -> add("combat_exp",100000);
me -> add("potential",60000);
tell_object(me,"你被奖励了十万点武学,六万点潜能。\n");
me->set("mark/yuebing",1);
}
else tell_object(me,"你已经吃过一次月饼了，还想吃？\n");
destruct(this_object());
return 1;
}
