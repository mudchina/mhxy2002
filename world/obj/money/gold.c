// gold.c
// By tianlin 2001.5.1

inherit MONEY;

void create()
{
	set_name("[1;33m»Æ½ð[2;37;0m", ({"gold", "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "gold");
		set("long", "»Æ³Î³ÎµÄ½ð×Ó£¬ÈË¼ûÈË°®µÄ½ð×Ó£¬°¡¡«¡«½ð×Ó£¡\n");
		set("unit", "Ð©");
		set("base_value", 10000 );
		set("base_unit", "Á½");
		set("base_weight", 37);
	}
	set_amount(1);
}

