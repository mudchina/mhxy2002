//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIY"·ï»ËÇÙ"NOR, ({"fenghuang sword", "fenghuang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»×ðÓñµñ¿Ì³ÉµÄ·ï»ËÇÙ¡£\n");
                set("unit", "°Ñ");
                set("owner_name","¿×È¸¹«Ö÷");
                set("owner_id","kongque gongzhu");
        }
}

