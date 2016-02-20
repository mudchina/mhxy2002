//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIB"挑战书"NOR, ({"tiaozhan shu", "shu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一张挑战书。\n");
                set("unit", "张");
               set("owner_name",HIY"范青屏"NOR);
               set("owner_id","fan qingping");
        }
}
