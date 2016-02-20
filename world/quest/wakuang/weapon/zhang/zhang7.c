#include <weapon.h>
#include <ansi.h>

inherit STAFF;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"无名杖"NOR,({ "wuming zhang", "wuming", "staff", "zhang" }) );
        set_weight(20000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("rigidity", 9);
                set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
                set("sharpness", 9); 
                set("unique", 1);
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_force", 300);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"$N“唰”\n$N抽出一把无名杖，周围的人纳闷；这是什么？\n"NOR);
                set("long", "不懂行的人看来看去竟不知道这是什么。\n");                
                set("unwield_msg", HIY "$N放下手中的$n，周围的人还在纳闷。\n" NOR);                
}
        init_staff(120);
        setup();
}
