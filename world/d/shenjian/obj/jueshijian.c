//By tianlin@mhxy for 2001.10.7

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE; 
inherit SWORD;

void create()
{
    set_name(HIR"绝"NOR+HIW"世好"NOR+HIC"剑"NOR, ({ YEL"jueshihao jian"NOR,"jueshihao jian","jian" ,"baojian" ,"sword" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 123311);
        	set("no_sell", "1");
        	set("no_give", "1");
        	set("no_put", "1");
	       set("replace_file", "/d/obj/weapon/sword/qinghong");
        	set("armor_prop/armor", 50);
        	set("armor_prop/personality", 50);
        	set("material", "iron");
              set("rumor_msg",1);
        	set("long", "它是神剑山庄的镇山宝剑,也是世上少有的宝剑,一般人是拿不动它的。\n");
        	set("wield_msg",HIY"$N猛地拔出$n"NOR+HIY"来，顺势转了两圈。\n"NOR);
        	set("unwield_msg", HIG"$N慢慢把手中的$n"NOR+HIG"放了下来。\n"NOR);
	}
    	init_sword(200);
	setup();
}
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "一道紫气闪过，$n被突如其来的霞光收走了！\n");
    destruct(me);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_fire");
        dam = (int) me->query("force");
        if(dam > pro)
        {
        victim->receive_wound("kee",50);
        victim->receive_wound("sen",50);
        return HIR"绝"NOR+HIW"世好"NOR+HIC"剑"NOR+HBRED+HIW"突然发出无数剑气,结果"NOR+BLINK+MAG"『$n"NOR+MAG+BLINK"』"NOR+HBRED+HIW"正好被这些剑气所伤。\n" NOR;
        }
}


