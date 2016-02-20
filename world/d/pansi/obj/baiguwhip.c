//[4;53m[1;31mBy tianlin@mhxy for 2001.10.1[2;37;0m
//°ËÔÂÊ®ÎåÖÆ×÷
#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE; 

inherit WHIP;

void create()
{
        set_name(HBRED+HIW"°×¹Ç±Þ"NOR, ({"baigu whip", "whip", "bian", "baigu"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {

        set("long","ÕâÊÇÒ»ÌõÓÃ°×¹ÇÖ¯ÆðÀ´µÄÒ»¸ö±Þ×Ó¡£\n");
        set("unit", "Ìõ");
        set("replace_file", "/d/obj/weapon/whip/pibian");
        set("value", 120000);
        set("no_sell", 1);
	 set("no_break", 1);
        set("armor_prop/spells", 25);
        set("armor_prop/armor", 20);
        set("armor_prop/intelligence", 10);
	 set("wield_msg", HIW"$N×óÊÖÇáÑï£¬Ò»Ìõ°×É«µÄ°×¹Ç±ÞÍ»È»Ã¼·ÉÉ«Îè.\n"NOR);
	 set("unwield_msg", HIY"$N°ÑÊÖÖÐ$n[1;33m²ø»ØÑü¼ä£®\n"NOR);
	 set("weapon_prop/courage", 5);
        }
        init_whip(140);
        set("is_monitored",1);
        set("rumor_msg",1);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_fire");
        dam = (int) me->query("force");
        if(dam > pro)
        {
        victim->receive_wound("kee",100);
        victim->receive_wound("sen",100);
        return HBRED+HIW"°×¹Ç±Þ"NOR+HBBLU+HIY"Í»È»·¢³öÒ»µÀ´ÌÑÛµÄ¹âÃ¢,Ö±´Ì"NOR+BLINK+HIW"¡º$n[1;37m¡»"NOR+HBBLU+HIY"µÄË«ÑÛ¡£\n" NOR;
        }
}
