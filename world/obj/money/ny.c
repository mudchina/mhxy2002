// gold.c

inherit ITEM;
string *names = ({
	"状元及第",
	"笔锭如意",
	"八宝联春",
});
void create()
{
	set_name(names[random(sizeof(names))], ({"happy_new_year"}));
//	set_name("黄金", ({"gold", "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个足赤的小金锞子,只有过年时才能见到。\n");
		set("unit", "个");
//		set("base_value", 9999);
//		set("base_unit", "两");
//		set("base_weight", 37);
	}
	setup();
//	set_amount(1);
}

