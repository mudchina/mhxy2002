#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int lv;
        lv = me->query_skill("moondance",1);

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用桂花飘香？\n");

        if( me->query("gender") == "男性")
                return notify_fail(HIY "男性不能使用这项技能？\n" NOR);

        if((int)me->query_skill("moonforce",1) < 50)
                return notify_fail(HIY "你的圆月心法修为不够。\n" NOR);

        if( lv < 80)
                return notify_fail(HIY "你的冷雪凝香舞不够熟练。\n" NOR);

        if((int)me->query("force") < 400)
                return notify_fail(HIY "你现在内力不足。\n" HIY);

        if( target->is_busy() )
        return notify_fail(target->name() + "现在不能动弹！\n");

       msg = HIY"$N妍然一笑，暗运真气，对着$n跳起舞来，$n顿\n"
       HIY"时一楞，$N身体飞速旋转着，顿时划成了一条美丽的圆弧，\n"
       HIY"$N软若无骨的骄躯如桂花一般洒向天空。\n"NOR;


       if(random(me->query("combat_exp")) > target->query("combat_exp")/2)
   
{                msg += HIW "结果$p被$P围个水泄不通！\n" NOR;
                target->start_busy(lv/50);
                me->add("force", -100);
                me->start_busy(1);
        } else {
                msg += HIG "$p只是一个箭步，便闪开了。\n" NOR;
                me->add("force", -100);
                me->start_busy(1);
        }
        message_vision(msg, me, target);

        return 1;
}
