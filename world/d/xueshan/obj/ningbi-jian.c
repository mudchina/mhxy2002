// By tianlin 2001.5.1

#include <weapon.h>

//inherit SWORD;
inherit "/d/xueshan/obj/anqi-jian.c";

void create()
{
        set_name("[1;34mÄı±Ì½£[2;37;0m", ({"ningbi sword", "sword"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("long", "Ò»°Ñµ­À¶É«µÄÏ¸½££¬½£Éí¼¸ºõÍ¸Ã÷£¬½£·æ´¦ÉÁ×Åµãµãº®¹â£¬ËÆºõÎ¹ÁË¾ç¶¾¡£\n");
                set("orilong","Ò»°Ñµ­À¶É«µÄÏ¸½££¬½£Éí¼¸ºõÍ¸Ã÷£¬½£·æ´¦ÉÁ×Åµãµãº®¹â£¬ËÆºõÎ¹ÁË¾ç¶¾¡£\n");
                set("value", 30000);
                set("material", "crimsonsteel");
                set("wield_msg", "$NÀäĞ¦Ò»Éù£¬´Ó±³ºó°Î³öÁË$n¡£\n");
                set("unwield_msg", "$N½«ÊÖÖĞµÄ$n²å»ØÇÊÖĞ£¬×ì½Ç¶àÁËÒ»Ë¿Ğ¦Òâ¡£\n");
                set("weapon_prop/int", 1);
                set("anqi/max", 20);
                set("anqi/now", 0);

        }
        init_sword(90);
        setup();
}

