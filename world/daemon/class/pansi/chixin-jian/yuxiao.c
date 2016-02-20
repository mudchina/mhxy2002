//by swagger skyer
//by 03/01/2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg , str;
 int extra,lvl,lv;
 int i;
 object weapon;
 
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
        return notify_fail("雨消情愁只能对战斗中的对手使用。\n");
 if (me->query_temp("fenghuang_busy")) return notify_fail("树上的桃花都掉光了!\n");
                    if( (int)me->query("force") <= 1000 )
        return notify_fail("你内力不够，不能使用雨消情愁！\n");

 extra = me->query_skill("chixin-jian",1) / 2;
 me->add_temp("apply/attack", extra);
 me->add_temp("apply/damage", extra);
 msg = HIW  "空气中飘浮着一种淡淡的忧伤......\n\n                           刹那间,粉红色的"HIM""BLINK"桃花"NOR""HIW"飘落在$N和$n的周围!" NOR;
        message_vision(msg, me, target);
 msg =  HIC "\n\n$N轻拈剑诀,眉目间似有万千哀怨：“"HIR"在我的生活中，只有仇恨！只有杀人和被杀！"HIC"”\n" NOR;
        message_vision(msg, me, target);
 msg =  HIC "\n$N话音未落,眼神中己透出一丝杀机！"HIC"”\n" NOR;
        message_vision(msg, me, target);
 msg =  HIW"\n                『"HIM"桃 花 过 处  "HIC""BLINK"☆"NOR""HIM"  寸 草 不 生"HIM"』\n" NOR;
        message_vision(msg, me, target);
lvl=extra/20;
if(lvl>4) lvl =4;
for(i=0;i<=lvl;i++)
 {
 msg = HIY "$N刺出一剑！\n" NOR;
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
 message_vision(msg,me,target);
           if (target->query("eff_kee")<0 || !living(target) )  
                       {str="听说"+target->name()+"被"+me->name()+"用盘丝洞绝学"HIY"雨消情愁"HIM"送去了阎罗地府，"+target->name()+"临死前脸上还挂着两行清泪！"NOR;
             message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
}
}
 me->add_temp("apply/attack", -extra);
 me->add_temp("apply/damage", -extra);
 me->add("force", -200);
 msg =  HIY "\n$N剑势一收，幽幽叹道：“那年的"HIM""BLINK"桃花"NOR""HIY"开的......很美......”\n" NOR;
        message_vision(msg, me, target);
me->start_busy(1);
 me->set_temp("fenghuang_busy",1);
 call_out("remove_effect",3+random(8),me);
return 1;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("fenghuang_busy");
}


