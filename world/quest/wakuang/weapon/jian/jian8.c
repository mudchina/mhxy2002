#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"玄铁重剑"NOR,({ "xuantie jian", "xuantie", "jian", "sword"}) );
        set_weight(70000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 10);
                set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
                set("sharpness", 1);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -12);
                set("treasure",1);
                set("wield_force", 1500);
                set("wield_maxforce", 2100);
                set("wield_str", 32);
                set("wield_msg", HIY"$N嗡的一声从背后抽出玄铁重剑，但见寒气逼人，杀雾迷茫，
方圆之内轰然雷声滚滚，肃杀万分。\n"NOR);
                set("long", "此剑长七尺，黝黑黝黑由万年玄铁所铸，沉重无比，无锋无刃，
却杀气森然，实乃天下第一神兵。\n");                
                set("unwield_msg", BLU "$N将玄铁剑插回肩后，杀气顿减。\n" NOR);               
}
        init_sword(160);
        setup();
}
