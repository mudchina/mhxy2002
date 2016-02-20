// icejia
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        if((int)me->query_skill("mtl-force", 1) <100)
                return notify_fail("你的曼佗罗心法还不够熟练！\n");
        extra = me->query_skill("unarmed");
        if ( extra < 200) return notify_fail("你的飘云掌还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［穿云掌］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);

        weapon = me->query_temp("weapon");
        msg = HIC  "$N脚踩丁字，横掌而立。双手缓缓抬起，暗自运起曼佗罗心经，\n" NOR;
        msg += HIB "顿时一股云气从$N的身体散出来。
$n对着这突然改变的环境不由得目瞪口呆，愣在当场！
$N乘机绵绵不断连续功出五招。\n" NOR;
                  message_vision(msg,me,target);
        message_vision(HIM"\n$N的双掌由下向上推起，人随掌行，跃向空中。\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"\n$N借着漫天云雾，在空中两个来回，又对着$n劈出了两掌。\n"NOR,me,target);

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      message_vision(HIW"\n$N借着更浓的云雾，从空中直落而下扑向$n，幻出漫天掌影压向$n！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"\n$N轻盈的落在一旁，然而脸在飘渺的云雾中显得更加冷酷了。\n"NOR,me,target);
me->start_busy(4);
me->add("force", -350);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);

        return 1;
}

