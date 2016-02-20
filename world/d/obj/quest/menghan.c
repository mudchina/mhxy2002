//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIM "蒙汗药" NOR, ({"menghan yao", "yao"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "普通江湖人用的蒙汗药。\n");
                set("unit", "包");
               set("owner_name","花忍");
               set("owner_id","hua ren");
        }
}


