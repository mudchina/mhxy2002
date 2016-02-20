#include <weapon.h>
#include <ansi.h>

inherit FORK;
inherit F_UNIQUE;

void create()
{
        set_name("神龙叉",({ "dragon fork", "fork", "cha" }) );
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("rigidity", 9);
                set("sharpness", 9); 
                set("no_get", 1);
                set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5); 
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"$N“哗啦啦”的抽出一把神龙叉。\n"NOR);
                set("long", "这是一根古色古香的钢叉。\n");                
                set("unwield_msg", HIW "神龙叉幻作一道白光，「唰」地飞入腰间。\n" NOR);                
}
        init_fork(80);
        setup();
}
