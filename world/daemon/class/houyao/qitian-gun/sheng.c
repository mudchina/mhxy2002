#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,mystr,yourstr,lvl,lv;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("【圣字诀】只能对战斗中的对手使用。\n");
        if( me->query_skill("qitian-gun",1) < 80 )
                return notify_fail("你的齐天棍级别不够使用【圣字诀】\n");
           weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "stick"  )
                return notify_fail("你必须在使用兵器时才能使[雷霆一击」！\n");
        weapon = target->query_temp("weapon");
        if(!objectp(weapon)) return notify_fail("你的对手没有用兵器！\n");
        myexp = (int) me->query("combat_exp")/1000;
        mystr = (int) me->query("str");
        yourexp = (int) target->query("combat_exp")/1000;
        yourstr = (int) target->query("str");
        lv  = (int) me->query_skill("stick") ;
        lvl = (int) target->query_skill("dodge")+1;
        msg = YEL "$N一挥手，$n的兵器不知怎么就落在了地下！ \n" NOR;
if(objectp(weapon) )
{
        if( random(myexp * lv * mystr) > (yourexp * yourstr *lvl)/3 )
        {
                weapon->unequip();              
                weapon->move(environment(target));
                message_vision(msg, me, target);
                target->start_busy(2);
        }
        else 
        {
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
        }
                me->start_busy(2);
}
        return 1;
}

