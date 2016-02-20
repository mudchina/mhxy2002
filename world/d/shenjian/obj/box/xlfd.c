
#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name(RED "小李飞刀" NOR, ({ "flying blade" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一把人见人怕的小李飞刀\n");
		set("unit", "堆");
		set("value", 1000);
		set("base_unit", "把");
		set("base_weight", 1);
		set("no_get",1);
		set("no_drop",1);
		set("base_value", 1);
		set("wield_msg","$N不知从哪里突然间拽出一把薄薄的$n握在手里．\n");
	}
	set_amount(1);
	init_throwing(100);
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