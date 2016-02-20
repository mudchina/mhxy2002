//  ÑıÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.15
//  /d/qujing/xuanyuan/obj/heart.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("[31m±È¸ÉµÄºìĞÄ[m", ({"bigan heart","heart"}));
        set_weight(1000);
                set("unit", "¸ö");
                set("heart",1);
                set("value", 50);
                setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
     object me=this_player();
     if(!arg && arg != "heart" )
     return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");

    if(me->is_busy())
    return notify_fail("ÄãÕıÃ¦×ÅÄØ£¡\n");
    message_vision(HIY"ÄãÒ»¹¾Âµ¾Í°Ñ±È¸ÉµÄĞÄ³ÔÁËÏÂÈ¥¡£\n"NOR,me);
    me->add("mana",200);
    destruct(this_object());
    return 1;
}
