// 阿克修斯 by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIG "阿克修斯" NOR, ({ "ake xiusi", "xiusi","ake" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件赛亚女性穿戴的衣物。\n");
                set("unit", "条");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}
