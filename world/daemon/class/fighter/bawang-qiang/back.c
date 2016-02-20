// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
  string msg=" ";
        object weapon;
  int damage, ap, dp, point;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
        return notify_fail("你要对谁施展「回马枪」？\n");


        if(!me->is_fighting())
             return notify_fail("「回马枪」只能在战斗中使用！\n");

    if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

  if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");

      if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

  i=(int)me->query_skill("bawang-qiang",1)+(int)me->query_kar();

    if( i < 20)
            return notify_fail("你的霸王枪级别还不够，使用这一招人家轻易就会看出来。\n");

msg=(HIY"\n$N见势头对自己不利转身拖枪就跑，一边跑还一边大叫：臭贼，你家爷爷不与你斗了！\n\n"NOR);

        ap = me->query_skill("bawang-qiang");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_force") / 10 +
random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_force") / 10 +
random((int)target->query("eff_sen") / 5);
         damage +=(int)me->query("force_factor")-random((int)target->query("force_factor"));
                if( damage > 0 ) {
     damage +=random((damage*(int)me->query_skill("bawang-qiang"))/100);
  msg += HIR "$n大喝一声：哪里走！说罢飞身就追。\n$N见$n上当，突然回首大喝一声：回马枪！\n$n高呼：不好，上当了…但却没有躲开，身上一处受了重伤。\n" NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
                        me->improve_skill("bawang-qiang", 1, 1);
                }
       else {
 msg += HIR "$n仰天大笑：小儿，你这种身手还想骗我？\n$n说罢飞身上前，趁$N不备时发动了进攻。\n结果$N却没料道此招被识破，身上受了一处重伤。\n" NOR;
        COMBAT_D->do_attack(target, me, target->query_temp("weapon"));

 /*    damage -= (int)target->query("force_factor");
     damage -=random((-damage*(int)target->query_skill("dodge"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/4, target);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/4, target);
                        me->improve_skill("bingpo-blade", 1, 1);
*/
       }
             }
   else
   msg +=HIC "$n大喝一声：哪里走！说罢飞身就追。\n$N见$n上当，突然回首大喝一声：回马枪！\n$n高呼：不好，上当了…于是飞身躲了过去。\n"NOR;

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->kill_ob(target);
        }
point=me->query("force_factor")+150;
me->add("force",-point);
me->add("sen",random(100));

        me->start_busy(1+random(3));
        return 1;
}
