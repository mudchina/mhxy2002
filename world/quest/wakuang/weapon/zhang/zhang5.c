#include <weapon.h>
#include <ansi.h>

inherit STAFF;
inherit F_UNIQUE;

void create()
{
        set_name("小乘禅杖",({ "xiaocheng chanzhang", "changzhang", "zhang", "staff" }) );
        set_weight(20000);
    if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("rigidity", 9);
                set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
                set("sharpness", 9); 
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5); 
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"$N“唰”的一声抽出一把小乘禅杖。\n"NOR);
                set("long", "这是一柄四尺来长的古剑。\n");                
                set("unwield_msg", HIY "$N放下手中的$n。\n" NOR);                
}
        init_staff(80);
        setup();
}
