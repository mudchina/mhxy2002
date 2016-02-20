
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name( HIR "绑着一块木头的锈铁片" NOR, ({ "rustysword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把绑着一块木头的锈铁片，看起来象玩具．\n");
		set("value", 1);
		set("no_get",1);
		set("no_drop",1);
		set("material", "steel");
		set("wield_msg", "$N把别在腰间$n拔出握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间。\n");
	}
	init_sword(85);
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