//18slash.c 十六连斩
//created by foc,04-7-01
//特点说明：瞬间的十六连剑攻击。
//如果敌人没有busy，那么在同等情况下最多中四招。

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    object weapon;
    int myexp, urexp, mysk, ursk, damage, n;
    if( !target ) target = offensive_target(me);
    if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
    return notify_fail("你要对谁使用「十六连斩」？\n");
    if(!me->is_fighting(target))
    return notify_fail("只能在战斗中使用「十六连斩」。\n");
    if((int)me->query_skill("sword",1)<120 || (int)me->query_skill("evilsword",1)<60)
    return notify_fail("你试着使用十六连斩，但好象基础不够。\n");
    if((int)me->query("max_force")<1000 || (int)me->query("force")<700)
    return notify_fail("你的妖力目前不足以使用这招。\n");
    if((int)me->query("combat_exp")<1000000 || (int)me->query("daoxing")<300000)
    return notify_fail("你的修为尚不足以使用这招。\n");
    if((int)me->query_skill("evileye",1)<120)
    return notify_fail("你的邪眼术尚不足以控制力量的使用。\n");
    if( me->query_skill_mapped("force")!="evileye" )
    return notify_fail("你必须使用邪眼术来发动连击。\n");
    if(me->query_temp("16slash_busy"))
    return notify_fail("你的力量尚未回复，没办法用这招。\n");
    else
{
    weapon = me->query_temp("weapon");
    myexp=(int)me->query("combat_exp");
    urexp=(int)target->query("combat_exp");
    mysk=(int)me->query_skill("evileye",1)+(int)me->query_skill("evilsword",1);
    ursk=(int)target->query_skill("dodge",1)+(int)target->query_skill("parry",1);
    damage=mysk+random((int)me->query("kar"));
    n=0;
    me->add("force",-700);
    message_vision(HIC "$N头上的邪眼突然光芒大盛，接着全身燃起黑色的火焰。\n" NOR,me,target);
    message_vision(HIR "$N带着全身的火焰，左手按在"+weapon->query("name")+HIR"上面，朝着$n冲了过去，\n接着使出了妖剑术的必杀技——十六连斩！\n" NOR,me,target);
    message_vision(MAG "$N双手握剑，朝着$n迎面劈出一剑！\n" NOR,me,target);
{//1
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "$n被这凌厉的剑气定住，动弹不得，被$N劈中了。\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "但是$n挡住了这一击，没有受伤。\n" NOR,me,target);
}
}
    message_vision(MAG "$N剑势一变，反手撩向$n！\n" NOR,me,target);
{//2
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，当胸中了一剑！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过被$n躲了过去。\n" NOR,me,target);
}
}
    message_vision(MAG "$N回手一剑，斩向$n腰间！\n" NOR,me,target);
{//3
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，腰部中了一剑！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过被$n躲了过去。\n" NOR,me,target);
}
}
    message_vision(MAG "$N力贯"+weapon->query("name")+MAG"，全力刺向$n！\n" NOR,me,target);
{//4
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，被刺中一剑！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过被$n躲了过去。\n" NOR,me,target);
}
}
    message_vision(MAG "$N大喝一声，改刺为横劈，想把$n斩成两段！\n" NOR,me,target);
{//5
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，腰部又中了一剑！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过被$n躲了过去。\n" NOR,me,target);
}
}
    message_vision(MAG "$N将身子一侧，运剑反撩向$n的头部！\n" NOR,me,target);
{//6
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，脑袋被砍得血肉横飞！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过被$n挡住了。\n" NOR,me,target);
}
}
    message_vision(MAG "$N临空跃起，全力削向$n的肩膀！\n" NOR,me,target);
{//7
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，左肩被砍出一道深及见骨的伤口！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过$n身子一侧，躲了开去。\n" NOR,me,target);
}
}
    message_vision(MAG "$N接着一个倒旋，手中"+weapon->query("name")+MAG"带着锐利的剑气像车轮般卷向$n！\n" NOR,me,target);
{//8
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，当胸被划出一道长及小腹的伤口！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过被$n挡住了。\n" NOR,me,target);
}
}
    message_vision(MAG "$N落地后一个旋身，双手握剑斩向$n的双脚！\n" NOR,me,target);
{//9
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，双脚似乎被砍断了！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "但是$n一个小跳，躲过了这招。\n" NOR,me,target);
}
}
    message_vision(MAG "$N趁此机会，双手紧握"+weapon->query("name")+MAG"，一个倒提剑，放出一股锐利的妖气袭向$n！\n" NOR,me,target);
{//10
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n在空中不知所措，被那妖气冲出一道深深的伤口！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过$n在空中一个翻身，躲了开去。\n" NOR,me,target);
}
}
    message_vision(MAG "$N趁$n还未落地，将剑往地上一插，一道气柱立刻冲向$n！\n" NOR,me,target);
{//11
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，被那气柱撞到，身体里传来一阵骨骼碎裂的声音！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "但是$n右脚在那气柱上轻轻一点，借力躲开了。\n" NOR,me,target);
}
}
    message_vision(MAG "$N接着刚才释放气柱的反作用力，身体朝着$n电射而去，运剑一劈！\n" NOR,me,target);
{//12
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n实在躲闪不及，小腹中了一剑！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过被$n挡住了。\n" NOR,me,target);
}
}
    message_vision(MAG "$N接着一劈的势头，一个旋身划出一道半圆切向$n！\n" NOR,me,target);
{//13
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n手足无措，胸部又中了一剑！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过被$n全力挡住了。\n" NOR,me,target);
}
}
    message_vision(MAG "$N反过身来，又是一切！\n" NOR,me,target);
{//14
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n的胸口被划出一个十字，鲜血四射！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过$n一个后仰身，剑锋贴面而过，好陷！\n" NOR,me,target);
}
}
    message_vision(MAG "$N大喝一声，双足临空一点，全身的力量集中在剑上，\n带着无比的杀意冲向$n，当头再一劈！\n" NOR,me,target);
{//15
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，脑袋被砍得血肉横飞！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过$n身子一侧，挡住了这一击。\n" NOR,me,target);
}
}
    message_vision(MAG "$N与$n擦肩而过的瞬间，反手一剑，斩向$n的后颈！\n" NOR,me,target);
{//16
    if(target->is_busy() || random(myexp)>=random(myexp+urexp))
{
    message_vision(GRN "结果$n躲闪不及，一股鲜血顿时就喷了出来！\n" NOR,me,target);
    target->receive_damage("kee",damage/2);
    target->receive_wound("kee",damage/2);
    COMBAT_D->report_status(target,0);
    n +=1;
}
    else
{
    message_vision(GRN "不过$n来了个乌龟缩头，总算是躲过这一击。\n" NOR,me,target);
}
}
    if(n>0)
{
    message_vision(HIW "$n全身一共中了"+chinese_number(n)+HIW"剑，鲜血不停地流出来。\n" NOR,me,target);
    me->start_busy(n);
}
    if(n=0)
{
    message_vision(HIW "$n在这一连番的攻击中居然毫发无损！\n" NOR,me,target);
    me->start_busy(3);
}
    me->set_temp("16slash_busy",1);
    call_out("remove_effect",n+120,me);
}

    return 1;
}

int remove_effect(object me)
{
    me->delete_temp("16slash_busy");
    tell_object (me, "你突然感到自己的妖力回复了，又可以使用特技了。\n");
}
