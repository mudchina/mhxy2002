// long_kui.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIG "九龙盘顶冠" NOR, ({"long kui","kui"}));
        set_weight(1000);
        set("long", "据说这顶法冠有着九条龙所凝聚的法力．\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "个");
                set("value", 100000);
                set("armor_prop/armor", 30);
        }
        setup();
}

