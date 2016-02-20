//by tianlin 2001.8.11修改

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl;
        if(me->query("family/family_name") != "方寸山三星洞" )
                return notify_fail("你不是道家弟子,乱用什么!!\n");
if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail(""HIY"[惊魔一指]"NOR"只能对战斗中的对手使用。\n");
if( objectp(me->query_temp("weapon")) )
return notify_fail("你必须空手才能施用惊魔一指!!\n");
if(target->is_busy())
     return notify_fail(target->query("name")+"已经动弹不得了！\n");
if( (int)me->query_skill("puti-zhi",1) < 100)
    return notify_fail("你的菩提指还不够纯熟!!\n");
    if( (int)me->query("max_force") <1000)
return notify_fail("你的内力还不够强,难以施展惊魔一指!!!\n");
    if( (int)me->query("force") <300)
    return notify_fail("你现在内力不足,无法使出惊魔一指!!\n");
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
lvl = (int)me->query_skill("puti-zhi",1)/30;
    msg = HIC
"\n$N脸色忽转肃穆,右手中指缓缓点出,正是惊天地,泣鬼神的惊魔一指!!\n" NOR;
if(random(myexp)>yourexp/2)
        {
                message_vision(msg + "\n", me, target);
        msg = HIG "$n只觉一股劲力直透肩井穴,登时全身一麻,动弹不得!!\n" NOR;
                message_vision(msg, me, target);
target->start_busy(1+random(lvl));
        }
    else {
            message_vision(msg +"\n", me, target);
           msg = HIY "可是$n似乎看破了$N的企图,险险躲过了这一招!!\n" NOR;
message_vision(msg, me, target);
            me->start_busy(2); }
me->add("force",-150);
//if( living(target) )target->kill_ob(me);
        return 1;
}
