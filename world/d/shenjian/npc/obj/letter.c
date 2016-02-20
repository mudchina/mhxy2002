// LLY@FYSY 
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name("书信", ({ "letter" }));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
                set("for_sjwoman",1);
		set("long",
			"一封谢晓峰给神剑山庄的家书，里面涉及到一些推荐你入庄的事情。\n");
	set("value", 0);
		


	}
	setup();
}


