//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <task.h>
#include <ansi.h>

void create()
{
        set_name(HIG"ËãÅÌ"NOR, ({"suan pan", "pan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ÌúËãÅÌÓÃµÄËãÕËËãÅÌ¡£\n");
                set("unit", "¸ö");
               set("owner_name",HIW"ÌúËãÅÌ"NOR);
               set("owner_id","tie suanpan");
        }
}
