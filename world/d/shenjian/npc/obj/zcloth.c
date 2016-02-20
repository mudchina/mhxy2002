// LLY@FYSY 
// cloth.c
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        string *order=({"金色", "蓝色", "白色",
"青色","紫色","黑色"});
        set_name((order[random(6)]) +"锦衣", ({ "cloth", "jcloth"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
        	set("long", "这是一神剑山庄中人的日常着装。\n");
		set("material", "cloth");
		set("armor_prop/armor", 30);
	}
	setup();
}
