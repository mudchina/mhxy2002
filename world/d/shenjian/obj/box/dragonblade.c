//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIR "伏龙宝刀" NOR, ({ "fulongblade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
set("no_get",1);
		set("no_drop",1);
		set("long", "这是一把锋利的宝刀，龙皮的刀壳上篆刻着一行小字--宝刃伏龙。\n");
		set("material", "steel");set("value", 1);
		set("wield_msg", "$N两指微弹，$n带着龙吟般的呼啸划破长空，飘然跃入$N手中！\n");
		set("unwield_msg", "$N的$n已悄然入鞘。\n");
	}
	init_blade(80);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	pro = (int) victim->query_temp("apply/armor_vs_fire");
	dam = (int) me->query("force");
	if(dam > pro)
	{
	victim->receive_wound("kee",5);
	return HIB "伏龙宝刀的刀口喷出一股蓝色的火焰，燎烤着$n的全身。\n" NOR;
	}
}

void init()
{
	add_action("do_make","remake");
}
int do_make()
{
	object me;
	object obj;
	me=this_player();
	obj=new(__DIR__"box");
	obj->move(me);
	if(query("equipped")) unequip();
	tell_object(me,"你将手中的"+query("name")+"又拆开，组成个箱子。\n");
        destruct(this_object());
	return 1;
}          