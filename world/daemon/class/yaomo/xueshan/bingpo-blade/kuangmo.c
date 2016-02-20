//creat by focus
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
    int extra;
        object weapon;
        object ob;
    string msg;
 //       extra=me->query_skill("bingpo-blade",1);
 //   if(me->query("family/family_name")!="大雪山")
   //             return notify_fail("你非雪山弟子，怎能用狂魔共舞！\n");

    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("你只能对战斗中的对手使用「狂魔共舞」。\n");
    if( (int)me->query_skill("bingpo-blade",1) < 120)
    return notify_fail("你冰魄刀法太低，无法使用「狂魔共舞」。\n");
    
    if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade"
        ||      (string)ob->query("material") != "ice" )
                return notify_fail("你必须先找一把冰做的刀才能施展「狂魔共舞」。\n");
   
        if( (int)me->query("force") < 100 )
    return notify_fail("你的内力不够。\n");
    me->add("force", -120);
    
    if (me->query_temp("BPD_perform_busy")) return notify_fail("绝招用的太多太滥就不灵了。\n");
    me->delete("env/brief_message");
        target->delete("env/brief_message");
    
    message_vision(HIR"$N冷哼一声，身形倏地凌空翻滚，瞬间劈出三刀,"+
    HIW"匹练也似的刀光环绕翻掠，形成一波波的，透明的光之波涛！$n只觉得心跳都停止了！\n"NOR,me,target);
                   
         target->start_busy(2+random(2));
        me->set_temp("BPD_perform", 6);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        
        me->set_temp("BPD_perform", 5);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        
        me->set_temp("BPD_perform", 3);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
       

        
        me->delete_temp("BPD_perform");
        me->recive_damage("kee",100);
        me->recive_damage("sen",100);
        me->add("force",-200);
        
        if (! target->is_fighting(me))
          {
            if ( living(target))
              {
                 if( userp(target) ) target->fight_ob(me);
                     else target->kill_ob (me);
              }
           }
        me->start_busy(2+random(2));
        
    return 1;
}
