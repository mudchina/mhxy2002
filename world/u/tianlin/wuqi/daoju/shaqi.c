
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
        set_name(RED"杀气丸"NOR, ({"shaqi wan","wan","shaqi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个可以长杀气的神奇药丸。\n");
                set("value", 3000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        if((int)this_player()->query("bellicosity") > 900 )//by tianlin@mhxy for 2002.2.25加入限制
        return notify_fail("别吃了,杀气够高的了！\n");

this_player()->add("bellicosity",100);
        message_vision("$N吃下一颗"RED"杀气丸"NOR"顿时感到自己不对劲了!\n", this_player());
            destruct(this_object());
        return 1;
}


