// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIW  "苍穹神剑" NOR, ({ "cang qiong" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄没有剑头的长剑\n");
		set("value", 1);
		set("rigidity",2000);	
         	set("no_get",1);
		set("no_drop",1);
		set("material", "steel");
		set("max_enchant",7);
		set("for_create_weapon",1);
	}
	init_sword(50);
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