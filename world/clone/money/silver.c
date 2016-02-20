// silver.c
// By tianlin 2001.5.1

inherit MONEY;

void create()
{
	set_name("[1;37mÒø×Ó[2;37;0m", ({"silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "°×»¨»¨µÄÒø×Ó£¬ÈË¼ûÈË°®µÄÒø×Ó¡£\n");
		set("unit", "Ğ©");
		set("base_value", 100);
		set("base_unit", "Á½");
		set("base_weight", 37);
	}
	set_amount(1);
}

