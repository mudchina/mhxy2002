#include <weapon.h>
#include <ansi.h>

inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name("精钢禅杖",({ "jinggang chanzhang", "chanzhang", "zhang", "staff" }) );
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
                set("long", "这是把禅杖，杖身铮亮耀眼。\n");
                set("wield_msg", HIC "只听见「嗡」地一声，亮光闪现，$N解下的$n抖得笔直。\n" NOR);
                set("unwield_msg", HIC "放下手中的$n。\n" NOR);
                set("unequip_msg", HIC "放下手中的$n。\n" NOR);
}
        init_staff(60);
        setup();
}
