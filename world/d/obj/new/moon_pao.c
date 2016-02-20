// baihu_pifeng.c

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;
void create()
{
        set_name(HIC "傲月冷日袍" NOR, ({"moon pao","pao"}));
        set_weight(1000);
        set("long", "这件披风，表面没什么奇怪的，仔细一看，竟然发着淡青色的光茫。\n");

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value",100000);
                set("armor_prop/armor", 60);

        }
        setup();
}

