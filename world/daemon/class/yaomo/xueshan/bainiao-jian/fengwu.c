//By tianlin@mhxy for 2002.1.24

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string str;//加上rumor的变量
	 object weapon=me->query_temp("weapon");  
              
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
              return notify_fail("你要对谁施展这一招"HIY"「"HIR" 鳳"HIM" 舞"HIG" 九"HIC" 天 "HIY"」"NOR"？\n");

        if(!me->is_fighting())
              return notify_fail(""HIY"「"HIR"鳳"HIM"舞"HIG"九"HIC"天"HIY"」"NOR"只能在战斗中使用！\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 400 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("kee") < 200 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("bainiao-jian", 1) < 180)
                return notify_fail("你的百鸟剑法级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("ningxie-force", 1) < 150)
                return notify_fail("你的冰谷凝血功还不够，使用这一招会有困难！\n");

	if(me->query_temp("busy_fengwu")+5>time())
		return notify_fail("你累坏了先休息一下吧。\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIC"$N一招蜻蜓点水手中的"HIR+weapon->name()+HIC"如发疯般的攻向$n,\n"NOR+HIW"只见$n没有来的及招架你这一阵狂攻乱舞，当场目瞪口呆不知所措！\n\n"NOR,me,target);
        message_vision(HBRED+HIW"$N使出了雪山百鳥劍法的精髓鳳舞九天,\n"NOR,me,target);

        message_vision(HIW"
                             "HBRED+HIG"┏━━━━┓"NOR"
                             "HBRED+HIG"┃   "NOR+BLINK+HIR"鳳"NOR+HBRED+HIG"   ┃"NOR"
                             "HBRED+HIG"┗━━━━┛\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIW"
                             "HBRED+HIG"┏━━━━┓"NOR"
                             "HBRED+HIG"┃   "NOR+BLINK+HIM"舞"NOR+HBRED+HIG"   ┃"NOR"
                             "HBRED+HIG"┗━━━━┛\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIW"
                             "HBRED+HIG"┏━━━━┓"NOR"
                             "HBRED+HIG"┃   "NOR+BLINK+HIG"九"NOR+HBRED+HIG"   ┃"NOR"
                             "HBRED+HIG"┗━━━━┛\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIW"
                             "HBRED+HIG"┏━━━━┓"NOR"
                             "HBRED+HIG"┃   "NOR+BLINK+HIC"天"NOR+HBRED+HIG"   ┃"NOR"
                             "HBRED+HIG"┗━━━━┛\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        me->receive_damage("kee", 100);
        me->add("force", -200);
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=NOR+YEL+target->name()+HIM"被"NOR+HIY+me->name()+HIM"用"HIW"大雪山"HIB"绝学"HIY"“"HIR" 鳳"HIM" 舞"HIG" 九"HIC" 天 "HIY"”"HIM"给杀死了!据说"+target->name()+"皮开肉绽难以入目!";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	 target->start_busy(1+random(2));//設定上对方的busy
        me->set_temp("busy_fengwu",time());
        return 1;
}


