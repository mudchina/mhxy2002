// LLY@FYSY 
// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name( HIC "天下" + MAG "无双" NOR, ({ "deitysword" ,"sword"}) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "剑鞘是乌里的，虽然已陈旧，却仍保存得很完整，杏黄色的剑穗色彩已消褪了，形式古雅的剑锷却还在发着光。\n");
		set("value", 120000);
		set("material", "steel");
	}
	init_sword(80);
	set("wield_msg", "$N的全身忽然发出一阵逼人的剑气，在手中凝聚成一把$n。\n");
	set("unwield_msg", "$n化为一团剑气消失在$N手中。\n");
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam ,pro;
        pro = (int)victim->query("force");
	dam = (int) me->query("force");
	if(dam > random(pro) )
	{
	victim->start_busy(1);
	return HIC "天下无双散发出逼人剑气，使得$n为之气窒，动弹不得！\n" NOR;
	}
}