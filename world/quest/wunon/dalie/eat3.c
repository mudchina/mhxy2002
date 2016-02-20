// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鸭肉", ({ "liewu3" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块鸭肉\n");
		set("unit", "块");
		set("value", 450);
		set("food_remaining", 3);
		set("food_supply", 60);
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);
	
	}
}
