//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name(HIR"肚兜"NOR, ({"du dou", "dou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "红孩儿穿的肚兜。\n");
                set("unit", "件");
               set("owner_name","红孩儿");
               set("owner_id","Honghai er");
        }
}
