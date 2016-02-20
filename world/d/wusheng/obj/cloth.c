// wusheng-cloth.c ¾Å²ÊÆ®ÔÆË¿ÅÛ

#include <ansi.h>
#include <armor.h>

inherit F_UNIQUE;
inherit EQUIP;

void create()
{
        set_name(HIM"¾Å²ÊÆ®ÔÆË¿ÅÛ"NOR, ({"jiucai pao", "pao", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¼þ±¡Èçæ¿¾ê£¬ÇáÈç²õË¿£¬¶ø·º³ö¾Å²ÊÔÆÉ«µÄË¿ÅÛ¡£\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);
                set("unit", "¼þ");
                set("value", 10000);
                set("material", "crimsonsteel");
                set("armor_prop/armor", 70);
                set("armor_prop/dodge", 15);
                set("armor_prop/spells", 10);
             }
}
