// lingzhi.c 千年朱果
//星星(lywin)2000/4/22
//By tianlin@Mhxy for 2002.1.27.加物件限制

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"万年朱果"NOR, ({"zhu guo", "guo"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "这是一棵武林人士梦寐以求的万年朱果，据说吃一棵可得20法力上限。\n");
                set("value", 10000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        if (this_player()->query("tianlin-guo") >=1 )
        return notify_fail("嘿嘿嘿别做梦了！\n");

        this_player()->add("maximum_mana", 20);
        message_vision("$N吃下一棵万年朱果，只觉得自己的法力变利害了一些 !\n", this_player());
        this_player()->add("tianlin-guo",1);
        destruct(this_object());
        return 1;
}


