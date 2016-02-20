// huayu.c 漫天花雨

#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
        string msg;
   string desc_msg="";
        int sword_level;
        string str;
	object weapon;
	int damage, num, lvl, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「"HIM"漫天花雨"NOR"」只能对战斗中的对手使用。\n");

        lvl = (int)me->query_skill("tanzhishentong", 1);
        if (lvl < 100) return notify_fail("你的弹指神通不够娴熟，无法使用 「"HIM"漫天花雨"NOR"」。\n");


        if ( (int)me->query("force") < 500)
                return notify_fail("你的内力不够，无法使用「"HIM"漫天花雨"NOR"」。\n");

        sword_level=(random(11));
   if ( sword_level <= 1 ) desc_msg = "" ; else
       desc_msg = chinese_number(sword_level);
  if ( sword_level > 9 ) desc_msg = "百";

message_vision(HIC"\n$N手从怀里抓出喑器，使出一招"HIM"「漫天花雨」"HIC"运用指力将暗器漫天地弹了出去！\n"NOR,me,target); 
message_vision(HIW"        ★"HIM"漫"HIW"★                                        ★"HIM"天"HIW"★\n\n"NOR,me,target); 
msg = HIW "                ★"HIM"花"HIW"★                        ★"HIM"雨"HIW"★\n\n"NOR;
        damage = lvl * 2 + (int)me->query_skill("unarmed", 1);
	damage += random(damage / 3);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
                msg += HIR"\n$n躲闪不及，“噗噗”地几声，被"+desc_msg+"十多道暗器击中！\n"NOR;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage / 3);
                p = (int)target->query("kee") * 100 / (int)target->query("max_kee");
                msg += RED "\n$n只觉得眼前一花，漫天的暗器打了他一身！\n"NOR;
        } 


        else {
                msg += HIC"$n吓得赶忙抱头团身，万分狼狈地向旁边一滚，方才堪堪地躲了过去。\n" NOR;
	}
                     if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"被"+""HIW""+me->name()+""HIM""+"用楚留香的绝招『"HIW"漫天花雨"HIM"』杀死了。听说尸体上打满了"+desc_msg+"十多处暗器！";
        message("channel:rumor",HIM"【"HIW"空穴来风"HIM"】某人："+str+"\n"NOR,users());
                       }

        message_vision(msg, me, target);
        me->add("force", -300);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));  ;
	me->start_busy(2);

	return 1;
}
