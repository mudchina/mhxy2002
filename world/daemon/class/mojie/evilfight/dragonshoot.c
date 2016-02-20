//邪王炎杀黑龙波, dragonshoot.c
//created by foc,19-6-01
//说明：看过原著的都应该知道它的厉害吧？

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
       int myexp, yourexp, mydx, yourdx, myskill, yourskill;
       int chance, myto, yourto, success, damage, skill;
       skill=(int)me->query_skill("evileye",1);
damage=(int)me->query_skill("evilfight",1)+(int)me->query_skill("force",1)+(int)me->query_skill("unarmed",1)+(int)me->query_skill("evilfight",1);       
       if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      target->is_corpse())
       return notify_fail("你要用黑龙波干掉谁？\n");
       if( target==me ) return notify_fail("黑龙波不能以这种方式施加到自己身上。\n");
       if(me->query_temp("dragonshoot_busy"))
       return notify_fail("你的妖气还没有集中到足够的程度，无法再次使用黑龙波。\n");
       if( (int)me->query_skill("evileye", 1 ) < 120 )
       return notify_fail("以你现在的邪眼术修为没办法召唤黑龙。\n");
       if( (int)me->query_skill("evilfight", 1 ) < 120 )
       return notify_fail("以你现在的炎杀拳修为没办法操纵黑龙。\n");
       if( (int)me->query("combat_exp") < 1200000 )
       return notify_fail("开玩笑，就你这点战斗经验，玩火呀？\n");
       if( (int)me->query("daoxing") < 500000 )
       return notify_fail("开玩笑，就你这点道行，玩过家家呀？\n");
       if( (int)me->query("max_force") < 1200 || (int)me->query("force") < 1200 )
       return notify_fail("使用黑龙波需要持续放出强大的妖气，你的妖气不够。\n");
       if( (int)me->query("max_mana") < 600 || (int)me->query("mana") < 200 )
       return notify_fail("使用黑龙波需要一定的法力，你的法力不够。\n");
       if( (int)me->query("kee") < 300 || (int)me->query("sen") < 300 )
       return notify_fail("你现在的身体状况不佳，别玩命了。\n");
       if (me->query_skill_mapped("force")!="evileye")
       return notify_fail("你必须使用邪眼术来召唤黑龙。\n");
       else
{
       message_vision(HIC "$N头上的邪眼放出强烈的光芒，接着$N的浑身燃起黑色的火焰。\n四周顿时变得像地狱一般炎热！\n" NOR,me);
       message_vision(HIR"无数的火焰从$N的身上迸射而出，四处肆掠。\n"NOR,me);
       if( (int)me->query_skill("evileye", 1) < (int)target->query_skill("segokee", 1)*3)
{
       message_vision(HIY "$n的全身放出金黄色的圣光气，$N的放出的火焰被完全防住，没有产生任何作用！\n" NOR,me,target);
       me->start_busy(3);
       tell_object (me, "看起来你的对手很强，不可乱来。\n");
       tell_object (target, "你的对手见你如此厉害，不禁目瞪口呆！\n");
       target->add("force",-50);
       target->kill_ob(me);
       me->kill_ob(target);
       return notify_fail("你的妖气还没有强大到可以贯穿圣光气的程度。\n");
}
       if( random((int)me->query_skill("evileye",1)) < random((int)target->query_skill("evileye",1)/2))
{
       message_vision(HIC "$n头上的邪眼放出耀眼的光芒，$N的放出的火焰只能围绕在$n的四周旋转，没有产生任何作用！\n" NOR,me,target);
       me->start_busy(3);
       tell_object (me, "看起来你的对手也会邪眼术。下次也许能成功。\n");       
       tell_object (target, "你的对手见你也会邪眼术，不禁吃了一惊！\n");
       target->add("force",-50);
       target->kill_ob(me);
       me->kill_ob(target);
       return notify_fail("为了谨慎起见，你将妖气收回体内。\n");
}
       else
{
       target->receive_damage("kee",damage/5);
       target->receive_damage("sen",damage/5);
       me->add("force",-100);
       if( (int)target->query("combat_exp")+(int)target->query("daoxing") < (int)me->query("combat_exp")/3+(int)me->query("daoxing")/3 && !target->is_corpse() && !target->is_ghost())
{
       target->receive_wound("kee",damage/20);
       target->receive_wound("sen",damage/20);
       me->start_busy(5);
       message_vision(HIM "结果$n立刻被火焰卷上了天，惨叫声不断从空中传来。\n" NOR,me,target);
       COMBAT_D->report_status(target, 0);
       me->kill_ob(target);
       tell_object (me,"看来对手目前太弱了，没必要出这么强的招式。\n");
       tell_object (target,"显然，你太弱了，快逃命吧。\n");
       target->start_busy(random(4));
       target->kill_ob(me);
}
       else
{       
       message_vision(HIC "$N身上的妖气越来越强了。突然，所有的火焰集中在$N的右手上，形成了\n一个怪异的球形空间。接着只听见$N大喝一声：“看招，邪王炎杀黑龙波！”\n一头巨大的火焰形成的黑龙咆哮一声，从那球形空间里奔涌而出，张着大嘴朝\n着$n直飞过去，似乎要把$n整个吞掉！\n" NOR,me,target);
       target->kill_ob(me);
       me->kill_ob(target);
       if( random((int)me->query_skill("evileye", 1)) < random((int)target->query_skill("segokee", 1)*4) && (int)target->query_skill("segokee",1) > 0)
{
       message_vision(HIY "$n的全身放出金黄色的圣光气，黑龙波被完全防住，没有产生任何作用！\n" NOR,me,target);
       me->start_busy(3);
       tell_object (me, "看起来你的对手很强，不可乱来。\n");
       tell_object (target, "你的对手见你如此厉害，不禁目瞪口呆！\n");
       target->add("force",-100);
       return notify_fail("你的妖气还没有强大到可以贯穿圣光气的程度。\n");
}
       if( random((int)me->query_skill("evileye", 1)) < random((int)target->query_skill("evileye", 1)/2) && (int)target->query_skill("evileye",1) >0 )
{
       message_vision(HIC "$n头上的邪眼突然放出光芒，随着$n一声冷笑，$N召唤出来\n的黑龙居然被$n造出来的一个同样的球形空间吸了进去！\n" NOR,me,target);
       target->add("force",-100);
       target->start_busy(1);
       tell_object (me, "你的黑龙波消失了，看来对手也会邪眼术。\n");
       tell_object (target, "看来对手好象比你弱，趁现在赶快攻击吧！\n");
       me->start_busy(4);
       return notify_fail("你体内的妖气一时没法集中，变得手忙脚乱。\n");
}
       if( (int)me->query_skill("evileye", 1) <  random((int)target->query_skill("force",1)/3+(int)target->query("max_force")/200 ))
{
       message_vision(HIC "但是$n集中全身的气，把$N召唤出来的黑龙一拳打散了。\n" NOR,me,target);
       me->start_busy(4);
       tell_object (me, "看来对手现在状态不错，下次他也许就没这么厉害了。\n");
       tell_object (target, "虽说你击散了黑龙波，不过你的手却是疼地厉害。\n");
       target->start_busy(1);
       target->receive_damage("kee",damage/6);
       target->add("force", -200);
       return notify_fail("你体内的妖气一时没法集中，变得手忙脚乱。\n");
}
       else
{ 
       myexp = (int)me->query("combat_exp");
       yourexp = (int)target->query("combat_exp");
       mydx = (int)me->query("daoxing");
       yourdx = (int)target->query("daoxing");
       myskill = (int)me->query_skill("evilfight", 1)+(int)me->query_skill("evileye", 1)+(int)me->query_skill("force", 1)+(int)me->query_skill("dodge", 1)+(int)me->query_skill("unarmed", 1);
       yourskill = (int)target->query_skill("force",  1)*2+(int)target->query_skill("dodge", 1)*2+(int)target->query_skill("parry", 1)*2;
       myto=mydx+myexp+myskill;
       yourto=yourexp+yourdx+yourskill;
       chance =(myto/yourto)*100-10;
       if( chance >= 10) success=1;
       if( chance < 10) success=0;
       if( success=1)
{
       if( chance >=90 || chance=100 )
{
       message_vision(HIR "结果$n躲闪不及，被$N召唤出来的黑龙吞了进去！只听见$n惨叫了一声，四肢立刻就化为了灰烬。\n" NOR,me,target);
       target->set("kee",-20000);
       target->set("sen",-20000);
       target->start_busy(2);
       COMBAT_D->report_status(target, 0);
       message("channel:rumor", HIM + "【西游报道组】欧巴桑A：听说"+
       target->query("name")+"被"+me->query("name")+"用邪王炎杀拳的最强奥义干晕了！\n"NOR,users());
}
       if( chance >=70 && chance < 90)
{
       message_vision(HIR "$n急忙拼出全力，抵挡住$N召唤出来的黑龙，只见$n的双手立刻就炭化了。\n不过，最后$n还是被黑龙缠住，受伤严重！\n" NOR,me,target);
       target->receive_wound("kee", damage/10);
       target->receive_wound("sen", damage/10);
       target->receive_damage("kee", damage/4);
       target->receive_damage("sen", damage/4);
       COMBAT_D->report_status(target, 0);       me->start_busy(4+random((int)me->query_skill("evileye",1)/50));
}
       if( chance >=40 && chance < 70)
{
       message_vision(HIR "$n集中全身的力量，终于将黑龙引开了，不过好象受伤不轻！" NOR,me,target);
       target->receive_wound("kee",damage/20);
       target->receive_wound("sen",damage/20);
       target->receive_damage("kee", damage/3);
       target->receive_damage("sen", damage/3);
       COMBAT_D->report_status(target, 0);
       target->start_busy(random(2));
       me->start_busy(2+random(2));
}
       if( chance >=20 && chance < 40 )
{
       message_vision(HIR "$n急忙向一旁一跳，但仍然被黑龙擦了一下，受了些轻伤。\n" NOR,me,target);
       target->receive_wound("kee", damage/30);
       target->reveive_wound("sen", damage/30);
       target->receive_damage("sen", damage/5);
       target->receive_damage("kee", damage/5);
       COMBAT_D->report_status(target, 0);
       target->start_busy(1);
       me->start_busy(3);
}
      if( chance <20 )
{
      message_vision(HIG "但是$n施展轻功，轻易躲了开去，只被烧掉了一点皮。\n" NOR,me,target);
      target->receive_damage("kee",100);
      target->receive_damage("sen",100);
      COMBAT_D->report_status(target, 0);
      me->start_busy(2);
}
}
      if( success=0 )
{
      message_vision(HIG "但是$n轻轻一闪，完全躲过了$N召唤出来的黑龙的攻击。\n" NOR,me,target);
      message_vision(GRN "$n见$N居然轻松躲过了这么厉害的攻击，不禁大吃一惊，手忙脚乱！\n" NOR,me,target);
      target->start_busy(1);
      me->start_busy(3);
}       
       me->receive_damage("kee",200);
       me->receive_damage("sen",200);
       me->add("force", -1000);
       me->add("mana", -200);
       message_vision(HIG "$N召唤出来的黑龙长啸一声，破空而去！\n" NOR,me);
       message_vision(RED "$N看着黑龙在空中消失，吸了一口气，开始慢慢回复自己的妖力。\n" NOR,me);
       tell_object (me, "你感到使用了黑龙波后，身体有些不支。\n");
       COMBAT_D->report_status(me, 0);
}
                        }
               }
         }
       me->set_temp("dragonshoot_busy",1);
       call_out("remove_effect",100+random(5),me);

       return 1;
}
void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("dragonshoot_busy");
  message_vision(HIW "$N右手上的龙纹再度出现，看起来$N又可以用黑龙波了。\n" NOR,me);
}
