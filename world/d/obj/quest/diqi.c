//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name(HIB"地契"NOR, ({"di qi", "qi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "张弟宝的帐簿.\n");
                set("unit", "件");
                set("owner_name","张弟宝");
            set("owner_id","zhang dibao");
        }
}
