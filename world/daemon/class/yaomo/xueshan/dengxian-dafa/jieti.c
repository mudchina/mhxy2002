//modified by vikee
//2000.10

// jieti.c 天魔解体大法。
//by tianlin 2001.8.10

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int success, ap, dp;

       /*  if( (string)me->query("class") != "yaomo" )
                return notify_fail("只有妖魔才能施展天魔解体大法。\n");  */
//这句话有的雪山判师去wdd也能使用jieti
//所以我给cut这句话,我加了一句，只能是雪山的才能使用解体大法

        if(me->query("family/family_name") != "大雪山" )
                return notify_fail("只有是雪山的，才有资格使用"HIR"天魔解体大法"NOR"！\n"); 

        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || target->is_corpse()
        || target==me)
                return notify_fail("你要对谁施展"HIR"天魔解体大法"NOR"？\n");

//by tianlin 2001.8.10降低使用要求,加上使用的级别

	 if((string)target->query("family/family_name") == "大雪山" )
		return notify_fail("你不能对同门使用"HIR"天魔解体大法"NOR".\n");//by tianlin for 不能对同门派//的使用jieti 

        if((int)me->query_skill("dengxian-dafa", 1) < 120)
                return notify_fail("你的登仙大法级别太低，别去送死了！\n");

        if((int)me->query("mana") < 1500 || (int)me->query("max_mana") < 1500 )
                return notify_fail("你的法力不够，不能有效施展"HIR"天魔解体大法"NOR"！\n");

        if((int)me->query("force") < 1500 || (int)me->query("max_force") < 1500 )
                return notify_fail("你的内力不够，不能有效施展"HIR"天魔解体大法"NOR"！\n");

        if((int)me->query("sen") < 100 || (int)me->query("sen") < (int)me->query("max_sen")/2 )
                return notify_fail("你无法集中精力施展"HIR"天魔解体大法"NOR"！\n");

        if( (int)me->query("daoxing") < (int)target->query("daoxing")/4  )
                return notify_fail("对方比你强太多了，还是别送死吧！\n");
        //here, we do not allow that a too weak player trys this on 
        //a much stronger player. this is to prevent statistically possible 
        //but unreasonable results from happenning. 

        if( random(me->query("max_mana")) < 100 ) { //here is modified by vikee 
                write("你失败了！\n");
                return 1;
        }

        msg = HIC
"$N口中念了几句咒文，双手捧住脑袋，仰天发出一声悲嘶！\n\n\n
  "+HIR+"天                  魔                   解                   体\n\n\n" NOR;

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("daoxing");
        ap = 4*ap; //this is for 拼命 so easier.
        dp = target->query("daoxing");
        if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( ap < random(dp) ) success = 0;
//here we compared max_mana.
//if the attacher has half of the max_mana of the target, 
//he has 50% chance to kill his target, which is reasonable.

        if(success == 1 ){//now both die.
                msg +=  HIR "结果$n被血雾罩住，顿时发出一声惨叫！\n而$N也身子一瘫，倒在地上。\n\n\n" NOR;
                message_vision(msg, me, target);

                target->kill_ob(me);
                me->kill_ob(target);
                //to produce killing messages.

                me->add_maximum_mana(-100);
                me->add_maximum_force(-50);
                me->save();
                //successed, attacker lost 100 max_fali and 50 max_neili.
                
     target->receive_damage("sen",target->query("max_sen")+1,me);
                target->receive_wound("sen", (int)target->query("max_sen")+1, me);
     target->receive_damage("kee",target->query("max_kee")+1,me);
                target->receive_wound("kee", (int)target->query("max_kee")+1, me);
                COMBAT_D->report_status(target);
  target->heart_beat();
                //target die here.

        me->receive_damage("sen", (int)me->query("max_sen")+1, target);
                me->receive_wound("sen", (int)me->query("max_sen")+1, target);
        me->receive_damage("kee", (int)me->query("max_kee")+1, target);
                me->receive_wound("kee", (int)me->query("max_kee")+1, target);
                COMBAT_D->report_status(me);
  me->heart_beat();
                //attacker die here.

        }
            
        else {
                msg +=  HIR "结果血雾被$n法力反激，反而罩住了$N！\n$N长叹一声，身子一瘫，倒在地上。\n" NOR;
                message_vision(msg, me, target);

                target->kill_ob(me);
                me->kill_ob(target);
                //to produce killing messages.

                me->add_maximum_mana(-50);
                me->add_maximum_force(-25);
                me->save();
                //failed, attacker lost 50 max_fali and 25 max_neili.
                
        me->receive_damage("sen", (int)me->query("max_sen")+1, target);
                me->receive_wound("sen", (int)me->query("max_sen")+1, target);
        me->receive_damage("kee", (int)me->query("max_kee")+1, target);
                me->receive_wound("kee", (int)me->query("max_kee")+1, target);
                COMBAT_D->report_status(me);
    me->heart_beat();
                //attacker die here.
        } 

        return 3+random(5);
}


