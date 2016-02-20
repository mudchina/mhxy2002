// mixian.c 迷香筒 3/29/1997,qingyun.

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void init()
{
        add_action("do_aim","aim");
        add_action("do_pun","pun");
}

void create()
{
        set_name("迷香筒", ({ "mi xian", "mi", "xian" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("bullet", 3);
                set("value", 50000);
                set("material", "steel");
                set("long", "这是一把专门用来喷迷香的筒子。\n");
                set("wield_msg", BLU"$N从口袋里偷偷的拿出$n握在手中。\n"NOR);
                set("unequip_msg", BLU"$N将手中的$n放回口袋中。\n"NOR);
        }
        init_sword(100);
        setup();
}

int do_aim(string arg)
{
        object me, obj;
        
        me = this_player();

        if( !arg )
                return notify_fail("你想喷谁？\n");

        if( this_object()->query("bullet") <=0)
                return notify_fail("筒里已没有迷香了。\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == me)
                return notify_fail(RED"有病??想喷自已呀!!!。\n"NOR);

        message_vision(BLU "\n$N看见$n没注意，偷偷拿出迷香筒的对准$n，点上火, 心里在偷偷的奸笑着。\n\n" NOR, 
                        me, obj);

        this_object()->set_temp("target", arg);

        return 1;
}

int do_pun()
{
        object me, obj;
        string arg;

        me = this_player();

        if( !(arg = this_object()->query_temp("target")) ) 
                return notify_fail("你还没有对准你的目标！\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("你想要害的人已跑了。\n");

        message_vision(BLU "\n$N对准$n的鼻子, 只见白烟从筒口冒出！！！\n只见$n还没有反应过来, 就软软的倒下了！\n\n" NOR,
                        me, obj);

        this_object()->add("bullet", -1);
        obj->unconcious();

        return 1;
}