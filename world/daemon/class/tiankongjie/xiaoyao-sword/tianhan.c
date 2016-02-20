//icejia
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;

   int ap, myexp, yourexp;
        if(me->query("family/family_name") != "天空界")
                return notify_fail("不是天界弟子的也想用天寒？\n");
if(me->is_busy()) return notify_fail("你正忙着呢!\n");
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("天寒只能在战斗中使用.\n");


    if( (int)me->query_skill("xiaoyao-sword",1) <80)
    return notify_fail("你的逍遥剑等级还不够!!\n");
   if( (int)me->query("max_force") <600)
   return notify_fail("你的内力太弱,不足以施展天寒!\n");
  if( (int)me->query("force") <250)
  return notify_fail("你的内力不够了!!!\n");
   ap = (int)me->query_skill("xiaoyao-sword",1)/40+1;
  myexp = (int)me->query("combat_exp");
  yourexp = (int)target->query("combat_exp");
    msg = HIW
"\n$N长袖轻摆,飘然而起,姿态极尽曼妙,如敦隍壁舞,如飞天散花, 令人叹为观止!!\n"
"$n正心旷神怡之际,不防天之寒气忽从空中降下,刹那间罩住$n全身.\n\n" NOR;

    if( random(myexp*ap) > yourexp)
{
    msg += HIR
"\n天寒刺在$n身上,真爆得$n肌肤尽裂.\n" NOR;
        target->receive_damage("kee",((int)target->query("max_kee")/7),me);
        target->receive_wound("kee",((int)target->query("max_kee")/12),me);
       me->start_busy(1+random(1));
        } else {
        msg += HIY
"\n$n将手中兵刃舞得风雨不透,没让天寒迫上一丝一毫!!\n" NOR;
me->start_busy(2+random(1));
        }
me->add("force",-100);
        message_vision(msg, me, target);
        return 1;
}

