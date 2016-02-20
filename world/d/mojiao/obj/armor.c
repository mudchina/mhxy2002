#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(HIY "连环锁子黄金甲" NOR, ({"golden armor", "jia"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
                set("value", 100000);
                set("armor_prop/armor", 85);
        }
        setup();
}
