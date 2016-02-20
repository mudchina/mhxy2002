// 无影剑绝招：幻影迷踪剑
// design by lsj 2001.9.4
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int mep,tap,chance;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「幻影迷踪剑」？\n");

        if(!me->is_fighting())
                return notify_fail("「幻影迷踪剑」只能在战斗中使用！\n");

        if(me->query("family/family_name")!="武圣门")
                return notify_fail("不是武圣门的不能用「幻影迷踪剑」！\n");
        if((int)me->query("max_force") < 800 )
                return notify_fail("你的内力修为不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没办法定下心来！\n");

        if((int)me->query_skill("mizongbu", 1) < 150)
                return notify_fail("你的迷踪步修为还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("feisheng", 1) < 150)
                return notify_fail("你的飞升大法等级不够，不能使用这一招！\n");

        if((int)me->query_skill("wuying", 1) < 150)
                return notify_fail("你的无影剑修为还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("sword", 1) < 150)
                return notify_fail("你的基本剑法修为还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("你的基本轻功修为还不够，使用这一招会有困难！\n");
        if (target->is_busy())
                return notify_fail("对方已经手忙脚乱了，放手进攻吧！\n");

        msg = HIG"\n$N的步法忽然加快，身影变的飘渺虚无起来，接连幻化出七个人影逼向$n！\n"NOR;
        mep=(int)me->query("combat_exp")+(int)me->query("daoxing");
        tap=(int)target->query("combat_exp")+(int)target->query("daoxing");
        chance = (int)(random( mep + tap ) / tap * 100);
        if( chance > 35 ) 
        {
                target->start_busy(5);
                me->start_busy(1);
                msg += HIY"结果$n"NOR+HIY"被幻影迷了个晕头转向！\n"NOR;
        COMBAT_D->report_status(target);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        }
        else 
        {
                me->start_busy(2);
                msg += HIW"$n"NOR+HIW"强定心神，看出了破绽，$N无奈只能退出三丈之外。\n"NOR;
                msg += HIY"结果$n"NOR+HIY"没有被幻影所迷惑！\n"NOR;
        }
        message_vision(msg, me, target);
        me->add("force",-150);
        me->add("sen",-50);
        return 1;
}
