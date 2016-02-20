#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{

        set_name(RED"血刀"NOR, ({ "xuedao","blade","dao" }));
        set_weight(15000);
     if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("rigidity", 5);
                set("sharpness", 3);
                set("long", "一柄软软的缅刀，刀身不住颤动，宛如活蛇一般。引光望去，刀锋全是暗红之色。，
血光隐隐,极是可怖.\n");
                set("value", 0);
                set("unique", 1);
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 2);
                set("material", "steel"); 
                set("wield_force", 120);
                set("wield_maxforce", 1000);
                set("wield_str", 26);
                set("wield_msg", RED"只听「唰」的一声，血刀脱鞘飞出，$N手中似是握住一条赤蛇泛着红光，弥漫着一片血气。！\n"NOR);            
                set("unwield_msg", RED"只见$N随手一挥,血刀象一条赤蛇飞舞入鞘。\n"NOR);
                set("treasure",1);
}
        init_blade(60);
        setup();
}
