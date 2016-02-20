// edit by lucas
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Ğ·Èâ", ({ "xierou", "rou" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿éÃÀÎ¶µÄĞ·Èâ¡£\n");
                set("unit", "¿é");
                set("food_remaining", 8);
                set("food_supply", 30);
        }
        setup();
}

