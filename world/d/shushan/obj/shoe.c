//shushan2 by yushu@SHXY 2000.12
#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("²½ÔÆÑ¥", ({ "buyun shoes", "shoes" }));
        set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 8);
        }
        setup();
}

