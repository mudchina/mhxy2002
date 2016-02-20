// happ@ys

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon, ob;
       if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("使用〖二郎担山〗必须拿锤。\n");

       if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        if( me->query("family/family_name") != "五庄观" )
                return notify_fail("你非五庄观弟子，不能使用〖二郎担山〗。\n");
        if( me->query_skill("kaishan-chui",1) < 60 )
                return notify_fail("你的开天锤级别不够，至少需要６０级。\n");
        extra = me->query_skill("force")/6 ;
   if ( extra < 30) return notify_fail("你的内力太弱，使不出〖二郎担山〗。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("〖二郎担山〗只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        me->add_temp("apply/damage", extra);
        msg = HIY  "$N双肩一纵，高举手中"+ weapon->name()+"，对$n猛锤下去。" NOR;
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
        me->add_temp("apply/damage", -extra);
        me->start_busy(2);
        return 1;
}
