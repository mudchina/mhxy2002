// counterattack.c
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,skill;
        object weapon;
        skill = me->query_skill("bawang-qiang",1);
if( (string)me->query("class") !="fighter")
       return notify_fail("不知道怎么回事,你好象忘了这招枪法!!\n");
        
if( !target ) target = offensive_target(me);
       
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"［惊艳一枪］"NOR+"只能对战斗中的对手使用。\n");
      
        if (skill <100 ) 
                return notify_fail(" 你的霸王枪的等级还不足以施展出惊艳一枪 。\n");
        if (me->query("force")<800 )
                return notify_fail(" 你的内力不足,如何施展这招绝学? \n");
        weapon = me->query_temp("weapon");
        msg = "$N一声大喝,使出了霸王枪的精髓"+ HIC"惊艳一枪"NOR+"。\n\n";
        message_vision(msg, me, target);
        msg =HIG  "$N手腕一抖,"+ weapon->name() +HIG"幻出漫天枪影,夹着呼啸之声,秋风扫落叶般的攻向$n。"NOR+"\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg +=HIR "结果$p被$P攻了个措手不及！\n" NOR;
                target->start_busy(1+random(2));
        } else {
                msg += "可是$p镇定自若，丝毫不为所动。\n\n" NOR;
        }
             me->add("force",-250);
     message_vision(msg, me, target);
        
        me->delete("env/brief_message");
        me->set_temp("BWQ_perform",8);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 
       me->delete_temp("BWQ_perform");
      //  weapon->move(environment(target));
        me->start_busy(1+random(1));
        return 1;
}
