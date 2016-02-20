//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
//by yushu修改2001.2

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIG"七"HIY"星"HIM"剑"NOR, ({"qixing sword", "sword"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把带有七星的剑，看起来非常的华丽．\n");
                set("value", 10000);
                set("material", "crimsonsteel");
                set("wield_msg",
"$N「唰」地一声抽出一把$n握在手中．\n");
                set("unwield_msg",
"$N将手中的$n插入腰间，嘴角露出一丝笑意．\n");

        }
        init_sword(80);
        set("is_monitored",1);
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
       victim->receive_wound("sen",20); 
	return HIG"七"+HIY"星"+HIM"剑"+HIW"灵光一闪扰的"+NOR"$n"+HIW"惊慌失措。\n" NOR;
	}
           

}
