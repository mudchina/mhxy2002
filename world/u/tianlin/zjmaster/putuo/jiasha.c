//By tianlin@mhxy for 2002.1.23

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"棉袍袈裟"NOR, ({ "mianpao jiasha","jia sha", "jiasha" }) );
        set("long", "此乃我祖如来所造,据所此袈裟可以增强自己的法力。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 100);
                set("armor_prop/spells", 100);
                set("armor_prop/dodge", 50);
                set("value", 50000);
        }
        setup();
}


