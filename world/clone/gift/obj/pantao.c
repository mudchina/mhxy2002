// pantao.c 蟠桃

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "蟠桃" NOR, ({ "tao", "pan tao", "pantao" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "天国蟠桃园里的蟠桃，据说吃了可以返老还童。\n");
                set("value", 10000);
                set("unit", "颗");
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N狼吞虎咽地将" + this_object()->name() +
                       "吃了下去。\n", me);
        if (random(10) >= 1)
        {
                tell_object(me, "你觉得好像没什么变化。\n");
        } else
        {
                tell_object(me, HIG "忽然你发觉自己的肌肤开始蜕变，慢慢变得滑嫩起来。\n");
               if(me->query("age")>14) me->add("age_modify", -1);
        }

        remove_action("do_eat","eat");
        destruct(this_object());
        return 1;
}
