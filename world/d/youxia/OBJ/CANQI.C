// created 17-06-2001 海上飘(piao)

inherit ITEM;
void create()
{
	set_name("一局未完的残棋", ({ "canqi"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "局");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
			}
}
