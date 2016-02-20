//EDIT BY LUCAS
#include <ansi.h>;
#include <armor.h>;
inherit EQUIP;


void create()
{
        set_name(HIW"龙皮甲"NOR, ({"long pijia", "pijia"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", HIW"这是当年敖顺进驻西海之时,屠掉盘踞在此的恶龙的战利品.\n"NOR);
                set("material", "cloth");
                set("armor_type", "cloth");
                set_weight(10); 
                set("armor_prop/armor", 10);
                set("armor_prop/force", 10); 
                set("armor_prop/dodge", 10); 
                set("no_put", 1); 
                set("wear_msg", HIY"$N穿上$n，"HIY"突然觉得热血澎湃，一股热气从丹田弥漫至全身。\n"NOR);  
                set("unequip_msg", HIC"$N脱下$n."HIC"只觉全身清凉无比，一阵凉爽。\n"NOR); 
        }
        setup();
}


