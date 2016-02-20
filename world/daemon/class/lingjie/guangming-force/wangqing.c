#include <ansi.h>

int exert(object me, object target)
{

        if ( !target
      ||      !userp(target)
      ||      target->is_corpse()
      ||      target==me)
                return notify_fail("你想替谁解除情毒？\n");
        if (!target->query_condition("xiangsi"))
        return notify_fail("没中情毒瞎捣什么乱！\n");
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法运功疗伤！\n");

        if( (int)me->query("force") - (int)me->query("max_force") <  800 )
                return notify_fail("你的真气不够。\n");

    if ( (int)me->query_skill("force") < 120 || (int)me->query_skill("guangming-force",1)<120)
                return notify_fail("你的内功修为不足以替人解除情毒。\n");
        
        message_vision(
                HIG "$N嘴中说道:苦海无涯,有人的地方就有伤心事,忘记情情爱爱,那只是痴心妄想。\n\n"NOR,
                me, target );
    if (random(me->query_skill("guangming-force", 1)-20)>50){
                target->apply_condition("xiangsi",0);
                message_vision(
                HIR "$N的声音直入心腹,$n带着一丝感激,一丝倦意晕了过去。\n"NOR,
                me, target );
                target->unconcious();    }
        else {
                message_vision(
                HIW "$N突然脸色苍白，似乎体力不支，竟呕出一口血来……\n"NOR,
                 me, target );
        }       
 
        target->receive_cuiring("kee", 100 + (int)me->query_skill("force")/2 );
        me->add("force", -600);
        me->set("force_factor", 0);
        return 1;
}
