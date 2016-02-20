#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIG "黄铜杖" NOR, ({ "huangtong zhang", "zhang", "staff", "huangtong" }) );
        set_weight(10000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是把黄灿灿的杖。\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "blacksteel");
                set("treasure",1);
                set("wield_msg", "只听见「呼」地一声，黄光顿现，$N将$n从腰间解下。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
}
        init_staff(40);
        setup();
}