// jiu.c
inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}
void create()
{
        set_name(HIC "玄冰碧火酒" NOR, ({"xuanbingbihuo jiu", "jiu"}));
        set("unit", "壶");
        set("long", "这是一壶珍贵之极的玄冰碧火酒, 据说能解百毒。\n");
        setup();
}
int do_drink(string arg)
{
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="jiu")
        {
             this_player()->set_temp("nopoison", 1);
             this_player()->set("eff_sen",this_player()->query("max_sen"));
             this_player()->set("sen",this_player()->query("max_sen"));
             this_player()->set("eff_kee",this_player()->query("max_kee"));
             this_player()->set("kee",this_player()->query("max_kee"));
             tell_object(this_player(), HIG "你只觉一股清香沁入心肺,顿时灵台一片空明,神意清爽！\n" NOR );
             destruct(this_object());
        }
        return 1;
}