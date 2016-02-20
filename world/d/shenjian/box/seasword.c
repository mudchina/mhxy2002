#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("海渊剑", ({ "sea sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把可以切金断玉的长剑，竟是用黄金打造而成。\n");
		set("value", 1);
		set("material", "gold");
		set("no_get",1);
		set("no_drop",1);
	}

	init_sword(110);
	set("wield_msg", "$N抽出一把$n握在手中，剑锋上竟隐隐传来海涛之声。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
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