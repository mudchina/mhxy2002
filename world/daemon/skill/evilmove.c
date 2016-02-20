//邪影残像术 evilmove.c
//created by foc,22-06-01
inherit SKILL;

#include <ansi.h>

string *dodge_msg = ({
     "$n的身影一散，成为七八个"+BLINK""+HIY"影子"NOR"向四周跑开，$N不知道哪个\n是真哪个是假，无从追赶。\n",
     "$n不退反进，直冲到$N面前，$N刚一攻击，却发现那只是个"+BLINK""+HIB"影子"NOR"。\n而$n早已经到了$N的身后。\n",
     ""+BLINK""+HIC"$n头上邪眼放出奇怪的光"NOR"，一刹那间$N双眼失明，无法继续攻击。\n",
     ""+BLINK""+HIR"$n的全身突然燃起黑色的火焰"NOR"，幻化出千百个人影，$N的攻击失败了。\n",
     "$n身形突然一滞，$N急忙发动攻击，却发现打中的只是$n的"+BLINK""+HIG"衣服"NOR"。\n",
     ""+BLINK""+HIW"$n的身形突然消失了"NOR"，$N顿时不知所以。原来$n正躲在$N的影子里。\n",
});

int valid_enable(string usage)
{ 
    return usage=="dodge"||usage=="move";
}

int valid_learn(object me)
{
        if( (int)me->query_skill("evilmove", 1) > 280 )
        return notify_fail("行啦，你已经够厉害了，别学了，爱惜生命吧！\n");
        if( (int)me->query_skill("evileye", 1) < 1 )
        return notify_fail("你无法学会这样武功，看来是基础不够。\n");
        if( (string)me->query_skill_mapped("force")!= "evileye")
        return notify_fail("你怎么学也学不会这种功夫，难道是基础上有什么问题？\n");
	if( (int)me->query_skill("evileye", 1) < 30 )
	return notify_fail("你的邪眼术都不够，怎么学习这种武功？\n");
        if( (int)me->query_skill("spiritforce", 1) > 0 )
        return notify_fail("你全身充满灵气，要练妖系的武功恐怕不行。\n");
        if( (int)me->query("combat_exp") < 100000 )
        return notify_fail("你战斗经验不足，别让人笑话了。\n");
        if( (int)me->query("daoxing") < 100000 )
        return notify_fail("你修为不够，别在这里捣乱了。\n");
        if( (int)me->query_skill("evileye", 1) < (int)me->query_skill("evilmove", 1) )
{
        me->receive_damage("kee", -300);
        me->receive_damage("sen", -300);
        message_vision(HIR"突然有一股力量在$N的身体里炸裂开来， $N不禁惨叫了一声！\n"NOR,me);
        return notify_fail("看起来你的邪眼术修为不够。\n");
}
        if( (int)me->query_skill("evilmove", 1) > 290 )
{
        me->receive_damage("kee", -3000 );
        me->receive_damage("sen", -3000 );
        message_vision(HIC"$N头上的邪眼突然放出一阵奇怪的光，接着就失去了光彩。\n$N体内疼痛不断加剧，终于晕了过去。\n"NOR,me);
        return notify_fail("显然，你练功练得过头了。\n");
}
        if( (int)me->query_skill("evilmove", 1) < (int)me->query("spi") * 8 || (int)me->query_skill("evilmove", 1) < (int)me->query("int") * 8 )
        return notify_fail("你对邪影残像术的领悟似乎到了极限。再打打基础吧！\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (string)me->query_skill_mapped("force")!= "evileye")
        return notify_fail("你的练习没有任何进步，看来是在气的使用上有不对之处。\n");
	if( (int)me->query("sen") < 200 )
	return notify_fail("你的精神太差了，别玩命练了。\n");
        if( (int)me->query("kee") < 200 )
	return notify_fail("你的体力不足了，别玩命练了。\n");
	if( (int)me->query_skill("evilmove", 1) < 30 )
        return notify_fail("乖乖，才这么点修为就想自己开始练习，可是要闹出人命来的。\n");
        if( (int)me->query_skill("evileye", 1) < (int)me->query_skill("evilmove", 1) )
{
        me->receive_damage("kee", -300);
        me->receive_damage("sen", -300);
        message_vision(HIR"突然有一股力量在$N的身体里炸裂开来， $N不禁惨叫了一声！\n"NOR,me);
        return notify_fail("看起来你的邪眼术修为不够。\n");
}
        if( (int)me->query_skill("evilmove", 1) > 280 )
        return notify_fail("行啦，你已经够厉害了，别练了，爱惜生命吧！\n");
        if( (int)me->query_skill("evilmove", 1) > 290 )
{
        me->receive_damage("kee", -3000 );
        me->receive_damage("sen", -3000 );
        message_vision(HIC"$N头上的邪眼突然放出一阵奇怪的光，接着就失去了光彩。\n$N体内疼痛不断加剧，终于晕了过去。\n"NOR,me);
        return notify_fail("显然，你练功练得过头了。\n");
}
        if( (int)me->query_skill("evilmove", 1) < (int)me->query("spi") * 8 || (int)me->query_skill("evilmove", 1) < (int)me->query("int") * 8 )
        return notify_fail("你对邪影残像术的领悟似乎到了极限。再打打基础吧！\n");
        me->receive_damage("kee", 30);
        me->receive_damage("sen", 30);
        me->receive_damage("force", 1);

	return 1;
}

void skill_improved(object me)
{
    tell_object (me, "哇，你好厉害呀，帅呀！\n");
}

       
