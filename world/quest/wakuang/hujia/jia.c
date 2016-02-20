#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(YEL"甲"NOR, ({ "jia" }) );
        set_weight(20000);
        set("unit", "件");
        set("material", "steel");
        set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
        set("value", 2500);
        set("armor_prop/armor", 10);
        set("unique", 1);
        setup();
}
