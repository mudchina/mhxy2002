// coin.c
// by tianlin 2001.5.1

inherit MONEY;

void create()
{
	set_name("[33mÇ®[2;37;0m", ({"coin", "coins", "coin_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "ÕâÊÇÁ÷Í¨ÖĞµ¥Î»×îĞ¡µÄ»õ±Ò£¬Ô¼ÒªÒ»°ÙÎÄÇ®²ÅÖµµÃÒ»Á½Òø×Ó¡£\n");
		set("unit", "Ğ©");
		set("base_value", 1);
		set("base_unit", "ÎÄ");
		set("base_weight", 1);
	}
	set_amount(1);
}

