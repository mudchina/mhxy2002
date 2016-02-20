// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("木架", ({ "木架", "mujia", "shelf" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", "你掀开木架上的黑布，露出个木架。木架上有一柄剑。
谢王孙静静的站在这柄剑前，伸手握着剑柄，就好像面对着自己心里最尊敬的神祗。\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		
	}
}

