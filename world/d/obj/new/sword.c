// xiaohunjian.c 
//create by lixin
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"销魂" NOR+HIC "剑" NOR, ({"xiaohun sword", "sword", "jian"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "销魂剑，剑销魂。\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", MAG "$N「唰」的一声抽出一柄$n"+MAG "握在手中，眼出射出了逼人的寒意，真让人销魂在无形之中。\n" NOR);
                set("unwield_msg",MAG "$N将手中的$n"+MAG "插回剑鞘，天地之间的杀气才渐渐消失。\n");
               set("value", 300000); 
               set("weapon_prop/cor", 1);
}
        init_sword(120);
        setup();
}
