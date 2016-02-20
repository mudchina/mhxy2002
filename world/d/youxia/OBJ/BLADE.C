// 百战宝刀  baizhan.c        created 17-06-2001 海上飘(piao)


#include <weapon.h>
#include <ansi.h>


inherit BLADE;

void create()
{
        set_name(CYN"百战宝刀"NOR, ({ "baizhen blade", "blade", "baizhan" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一把由铬钢制成的宝刀，刀柄刻有“百战”二字。\n");
                set("unit", "把");
	    set("wield_msg", "$N抽出一柄$n横握在手中，顿时威风凛凛。\n");
	    set("unwield_msg", "$N放下手中$n，依然威风凛凛。\n");
                set("value", 40000);
                set("material","wood");
        }
        init_blade(160);
        setup();
}

