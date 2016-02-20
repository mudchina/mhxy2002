// 行天战衣 by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"行天战衣"NOR, ({"xingtian zhanyi","zhanyi","xingtian","yi","cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("armor_prop/armor", 120);
                set("spells", 200);
        }
        setup();
}
