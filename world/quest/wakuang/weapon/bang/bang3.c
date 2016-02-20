#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(HIG "青龙棍" NOR, ({ "qinglong sitck", "bang", "qinglong", "stick" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long","这是根又粗又直的铁棒，棒上隐约浮现青龙的花纹。\n");
        set("value", 0);
        set("unique", 1);
        set("rigidity", 1);
        set("sharpness", 1);
        set("material", "blacksteel");
        set("treasure",1);
        set("wield_msg", "只听见「呼」地一声，青光顿现，$N将腰间解下的$n抖得笔直。\n");
        set("unequip_msg", "$N将手中的$n插入腰间。\n");
}
        init_stick(40);
        setup();
}
