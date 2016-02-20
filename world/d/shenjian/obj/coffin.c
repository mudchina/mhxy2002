// LLY@FYSY 
inherit ITEM;
void create()
{
	set_name("长长的方方的东西", ({ "长长的方方的东西","棺材", "guancai", "coffin" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
                set("long", "你心里忽然有了种说不出的寒意，从心头一直冷到足底。
这块黑市掀起，露出的是口棺材，崭新的棺材上，彷佛有八九个字。
你只看见了三个字：“谢晓峰……”\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		
	}
}
