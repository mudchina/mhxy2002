// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小红鱼", ({ "yu1" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条小红鱼\n");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);
		set("no_put",1);
	
		set("unit", "条");
		set("value", 350);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
