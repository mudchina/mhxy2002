//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
    set_name(YEL"开山锤"NOR, ({ "kaishan chui","chui","hammer" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "巨大的开山锤。\n");
                set("value", 300000);
                set("material", "iron");
                set("wield_msg", "$N拿出一个$n，握在手中晃了几下。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(80);
        setup();
}
