// 陸小鳳 朝鳳刀   cfblade.c        created 17-06-2001 海上飘(piao)


#include <weapon.h>
#include <ansi.h>


inherit BLADE;

void create()
{
        set_name(CYN"朝鳳刀"NOR, ({ "chaofeng blade", "blade", "chaofeng" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "陆小凤的宝刀，刀柄处装饰着一只栩栩如生凤凰。\n");
                set("unit", "把");
	    set("wield_msg", "$N从刀鞘抽出一柄$n横握在手中，叹道：四条眉毛的刀果然不错。\n");
	    set("unwield_msg", "$N放下手中$n插入刀鞘，叹道：四条眉毛的刀果然不错。\n");
                set("value", 40000);
                set("material","wood");
        }
        init_blade(160);
        setup();
}

