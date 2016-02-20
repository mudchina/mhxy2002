// yunblade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(MAG"瀚海云烟"NOR, ({ "yunblade" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1);
	
		set("no_get",1);
		set("no_drop",1);	set("material", "iron");
		set("long", "这是一把银光雪亮的长刀，刀刃间隐隐有血光流动，
锋利无匹，映面生寒。\n");
		set("wield_msg", "只听「铮」的一声，$n脱鞘飞出，自行跃入$N
掌中。瞬时天际间风云变色，电闪雷鸣，弥漫着一片无边杀意。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_blade(100);
	setup();
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