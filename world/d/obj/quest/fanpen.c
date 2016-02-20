//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIY"金饭盆"NOR, ({"jinfan pen", "pen"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个金制的盆子。\n");
                set("unit", "个");
               set("owner_name",HIR"猪八戒"NOR);
               set("owner_id","zhu bajie");
        }
}
