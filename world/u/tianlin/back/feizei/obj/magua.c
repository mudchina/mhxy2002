#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"小马褂"NOR, ({"xiao magua", "cloth", "magua"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "上古十二神甲之：小马褂。\n");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("armor_prop/armor", 50);
             }
        setup();
}
