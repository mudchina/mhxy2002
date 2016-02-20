// thousand.c
// by tianlin 2001.5.1

inherit MONEY;

void create()
{
        set_name("[36mÒ»°ÙÔªÈËÃñ±Ò[2;37;0m", ({"rmb", "rmb_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "rmb");
                set("long", "Ò»ÕÅÃæÖµÎªÒ»°ÙÔªµÄ´óÍÅ½áÈËÃñ±Ò¡£\n");
                set("unit", "ÕÅ");
		set("base_value", 100000);
		set("base_unit", "ÕÅ");
		set("base_weight", 3);
	}
	set_amount(1);
}

