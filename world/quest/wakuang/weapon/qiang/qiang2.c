#include <weapon.h>

inherit SPEAR;
inherit F_UNIQUE;
void create()
{
        set_name("��ǹ", ({ "tie qiang", "qiang", "spear" }) );
        set_weight(10000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰ��ֳ��������ǹ��������������͸���׹⣬��������ޱȡ�\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "blacksteel");
                set("weapon_prop/dodge", 2);
                set("treasure",1);
                set("wield_msg", "ֻ�������ˡ���һ�����׹���֣�$N��������µ�$n���ñ�ֱ��\n");
                set("unequip_msg", "$N�����е�$n�������䡣\n");
}
        init_spear(30);
        setup();
}