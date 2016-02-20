//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIW"»ð¼âÇ¹"NOR, ({"huojian qiang", "qiang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¸Ë»ðÑæ»ð¼âÇ¹,ÍþÁ¦ÎÞ±È¡£\n");
                set("unit", "¸Ë");
               set("owner_name",HIC"ÄÄ ß¸"NOR);
               set("owner_id","nezha santaizi");
        }
}
