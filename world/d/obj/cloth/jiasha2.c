//Cracked by Roath
// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("[1;31mÎå[32m²Ê[35mÖ¯[33m½ğ[37môÂ[36môÄ[m", ({"wucai jiasha", "jia sha"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
     set("long", "´ËÄËÌÆÍõËù´ÍÖ®ôÂôÄ£®\n");
                set("material", "cloth");
                set("no_drop",1);
                set("no_sell",1);
//                  set("value", 300);
                  set("value", 20000000);
                set("unit", "¼ş");
                set("armor_prop/armor", 10);
        }
        setup();
}

int query_autoload() { return 1; }
