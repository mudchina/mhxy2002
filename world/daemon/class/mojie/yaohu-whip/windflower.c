//windflower.c,风华圆舞阵
//created by foc,30-6-01
//特点说明：防御力与攻击力兼具的pfm……威力？fear自己试试。

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
     int damage, mywx, yourwx, yourskill, number, num, t;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("你要对谁使用「风华圆舞阵」？\n");
     if(!me->is_fighting(target))
     return notify_fail("只能在战斗中使用「风华圆舞阵」。\n");
     if(me->query_temp("WF_busy"))
     return notify_fail("你不是刚刚用过了吗？\n");
     if((int)me->query_skill("yaohu-whip",1)<100)
     return notify_fail("你的妖狐鞭法等级不够，玩不出来这招。\n");
     if((int)me->query_skill("throwing",1)<100)
     return notify_fail("使用这招必须有足够的暗器技术。\n");
     if((int)me->query_skill("whip",1)<100)
     return notify_fail("你的基本鞭法还不够纯熟。\n");
/*
     if( me->query_skill_mapped("force")!="yaohu-force" )
     return notify_fail("你现在使用的气不对。\n");
*/
     if((int)me->query("combat_exp")<800000)
     return notify_fail("以你现在的武学恐怕使出来也打不中对手。\n");
     if((int)me->query("daoxing")<200000)
     return notify_fail("你的修为太低了，就算用出来了，也没什么威力。\n");
     if((int)me->query("max_force")<1500 || (int)me->query("force")<400)
     return notify_fail("你的妖力不足，怎么用这招？\n");
     if((int)me->query("max_mana")<1000 || (int)me->query("mana")<200)
     return notify_fail("使用这招需要一些法力，但是你的法力显然不足。\n");
     else
{
     damage = (int)me->query_skill("whip",1) + (int)me->query_skill("yaohu-whip",1) + (int)me->query_skill("throwing",1) + (int)me->query_skill("yaohu-force",1) + (int)me->query_skill("force",1);
     yourskill = (int)target->query_skill("parry",1) + (int)target->query_skill("dodge",1) + (int)target->query_skill("force",1);
     if(yourskill<1) yourskill=1;
     mywx=(int)me->query("combat_exp");
     yourwx=(int)target->query("combat_exp");
     message_vision(HIG "$N将手中长鞭一抛，那长鞭居然围绕着$N旋转起来。\n强大的妖气形成了如刀般的气流，四射而开。\n" NOR,me,target);
     me->add("force",-100);
     if(mywx>yourwx*5)
{
     message_vision(GRN "结果$n惨叫一声，身上已经被划出了几十道深可见骨的伤口。\n" NOR,me,target);
     tell_object (target, "看起来，对手太厉害了，快逃命吧！\n");
     target->receive_damage("kee",damage/2);
     target->receive_damage("sen",damage/2);
     target->receive_wound("kee",damage/25);
     target->receive_wound("sen",damage/25);
     COMBAT_D->report_status(target, 0);
     me->start_busy(2);
     return notify_fail("对手太弱了，没必要用这么强的招式。\n");
}
     if(random((int)target->query_skill("yaohu-force",1)/3*2)>(int)me->query_skill("yaohu-force",1) || random((int)target->query_skill("force",1)/3*2)>(int)me->query_skill("yaohu-force",1))
{
     message_vision(GRN "$n急忙提高自己的气，抵挡住了$N如刀般的妖气。\n" NOR,me,target);
     target->add("force",-100);
     tell_object (me, "你突然想到作战必须谨慎，决定中止使用绝招。\n");
     tell_object (target, "对方突然停止了绝技的使用。看来对方很谨慎。\n");
     return notify_fail("对手的状态不错，不过下次他也许就没这么好运气了。\n");
}
     if((int)me->query_skill("yaohu-force",1)<random((int)target->query_skill("segokee",1)*4) && (int)target->query_skill("segokee",1)>0)
{
     message_vision(HIY "但是$n的全身放出了金黄色的圣光气，$N的妖气攻击没有起到任何作用。\n");
     target->add("force",-50);
}
     message_vision(HIM "$N从头发里拿出一粒种子，运上妖力。那种子立刻变成了一朵漂亮的红蔷薇。\n" NOR,me,target);
     me->add("force",-50);
     message_vision(HIR "$N将那蔷薇一甩，无数的花瓣从那蔷薇上分出来，好象无穷无尽一般。\n" NOR,me,target);
     message_vision(GRN "$N大喝一声：“风华圆舞阵！”浑身的妖气发生了变化！\n" NOR,me,target);
     message_vision(RED "$N的全身放出红色的妖气，那长鞭经这妖气之后，旋转加剧，最后变成了围绕着$N的\n白色气流，声势惊人。那些蔷薇花瓣立刻随之旋转着四射而开，\n带着如刀般的锐利妖气袭向$n！\n" NOR,me,target);
     me->add("force",-200);
{
     if(target->is_busy() || random(mywx)>random(mywx+yourwx/5))
{
    number=damage-(yourskill/3*2)+(damage/yourskill)*100+random(damage/20)+random(10);
    number -= yourskill/10;
    message_vision(GRN "结果$n躲闪不及，身上中了"+chinese_number(number)+"处妖气化的蔷薇花瓣！\n" NOR,me,target);
     target->receive_damage("kee",number*3);
     target->receive_damage("sen",number);
     target->receive_wound("kee",number*2);
     target->receive_wound("sen",number);
     COMBAT_D->report_status(target,0);
}
     else
{
     number=damage-(yourskill/2);
     num=random(number/100+3)+random(11);
     message_vision(GRN "但是$n连跳带滚，总算躲了过去。不过还是中了"+chinese_number(num)+"处妖气化的蔷薇花瓣。\n" NOR,me,target);
     target->receive_damage("kee",num);
     target->receive_damage("sen",num);
     target->receive_wound("kee",num);
     target->receive_wound("sen",num);
     COMBAT_D->report_status(target,0);
}
     me->add_temp("apply/dodge",damage/2);
     me->add_temp("apply/parry",damage/2);
     me->add_temp("apply/attack",damage*damage/2);
     me->set_temp("WF_busy",1);
     call_out("remove_effect",10+random(5),me);
     message_vision(HIW "$N将妖气一收，花瓣突地都消失不见了。\n" NOR,me,target);
     me->start_busy(2);
}
}
     return 1;
}

void remove_effect(object me, int damage)
{
  damage=(int)me->query_skill("whip",1)+(int)me->query_skill("yaohu-whip",1)+(int)me->query_skill("throwing",1)+(int)me->query_skill("yaohu-force",1)+(int)me->query_skill("force",1);
  if (!me) return;
  me->delete_temp("WF_busy");
  me->add_temp("apply/attack",-damage*damage/2);
  me->add_temp("apply/dodge",-damage/2);
  me->add_temp("apply/parry",-damage/2);
  message_vision(HIG "$N感觉到自己使用特技的力量恢复了。\n" NOR,me);
}    
