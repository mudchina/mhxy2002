#include <weapon.h>
#include <ansi.h>

inherit SPEAR;
inherit F_UNIQUE;
void create()
{
        set_name("碧血枪",({ "bixie qiang", "bixie", "spear", "qiang" }) );
        set_weight(10000);
    if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("treasure",1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("unique", 1);
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 1);        
                set("material", "steel");
                set("long", "这是把碧血枪，枪身上隐隐的透出碧玉之光，当真锋利无比。\n");
                set("wield_msg", HIC "只听见「嗡」地一声，壁光闪现，$N将腰间解下的$n抖得笔直。\n" NOR);
                set("unwield_msg", HIC "碧血枪幻作一道碧玉之光，「唰」地飞入腰间。\n" NOR);
                set("unequip_msg", HIC "碧血枪幻作一道碧玉之光，「唰」地飞入腰间。\n" NOR);
}
        init_spear(60);
        setup();
}
