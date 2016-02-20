#pragma save_binary
 
// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIC "真武剑" NOR, ({ "zhenwu sword","zhenwu","jian","sword" }) );
	set_weight(7000);
        set("owner","张三丰");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "这是武当镇山之宝的真武宝剑。\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        set("task",1); 
        set("no_put_in",1); 
	}
init_sword(160);
	setup();
}
