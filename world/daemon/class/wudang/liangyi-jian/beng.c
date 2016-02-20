//by nina
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{
        int mypot,tapot;
        object weapon, weapon2;
        string msg;
        me->clean_up_enemy();
        target = me->select_opponent(); 
        if( !me->is_fighting() )
                return notify_fail("两仪剑法的「崩」字决只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query("force") < 500 )
                return notify_fail("你的真气不够！\n");

        if(me->query("family/family_name") != "方寸山三星洞" )
                return notify_fail("你是哪儿偷学来的武功，也想用「崩」字决?\n");

        
        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("对方没有用兵刃，你用不了「崩」字诀。\n");

        if( (int)me->query_skill("liangyi-jian",1) < 100 )
                return notify_fail("你的两仪剑法还不到家，无法使用「崩」字决！\n");

        msg = HIC "$N稳住身形，吐气开声，使出两仪剑法中的“崩”字决\n" NOR;
        message_vision(msg, me);

        mypot=(int)me->query_skill("sword");
        mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

        if ( random( mypot + tapot ) > tapot ) 
                {
                        msg = HIW"$n只觉得虎口剧痛，手中";
                        msg += weapon2->name();
                        msg += "顿时把捏不住脱手飞了出去！\n" NOR;
                        me->add("force", -200);
                        target->start_busy(4);
                        weapon2->move(environment(me));
                }

        else    {
                        me->add("force",-100);
                        msg = HIY"可是$n看出了$N的企图，立刻手上加劲，将" + weapon2->name() + "奋力向外一挡，\n双方兵刃的碰在一起,“铛”的发出一声巨响！\n"NOR;
                        me->start_busy(2);
                }
        message_vision(msg, me, target);
        return 1;
}