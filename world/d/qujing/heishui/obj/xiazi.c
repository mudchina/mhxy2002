#include <ansi.h>
inherit ITEM; 
int do_open(string arg);

void create()
{
        set_name("翡翠玉匣", ({"box", "yu xia"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
"这是一个全以翡翠雕成，兼以蓝田白玉装饰的玉匣，是黑水妖龙
送信用的豪华信箱，里面应该有一封信，你可以打开(open)看看。\n");
                set("unit", "只");
                set("open_count", 1);
                set("weight", 1000);
        }
}

void init()
{
        add_action("do_open","open");
} 

int do_open(string arg)
{
        object ob, me = this_player(); 
        if (!arg || (arg != "box" && arg != "xiazi"))
                return notify_fail("你要开什么？\n");
        if (query("open_count") > 0)
        {
                message_vision(HIW
"$N打开翡翠玉匣，从中取出一张信帖。\n" NOR, this_player());
                add("open_count", -1);
                ob = new("/d/qujing/heishui/obj/tie");
                ob -> move(me);
                return 1;
        }
        else return notify_fail("翡翠玉匣已经被别人打开过了。\n");
}

