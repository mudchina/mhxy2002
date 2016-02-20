// liejiuquan.c,【灵光裂蹴拳】
// created by foc,26-08-01 
//说明：传说中的正道的极限武功。目前只有仙水练成。只有人类可学习。
//命中高，伤害力中上，pfm很厉害

inherit SKILL;
#include <ansi.h> 

mapping *action = ({
  ([
    "action":
"$N突然身形一闪，来到了$n的背后。$N力灌右脚，脚上带着旋转\n"
"的"+BLINK""+HIM"紫红色"NOR+"灵气，朝着$n的$l横踢过去。\n",
    "force":            120,
    "dodge":            -20,
    "parry":            -10,
    "damage_type":      "踢伤",
  ]),
  ([
    "action":
"$N冷笑一声，凌空跃起，左脚电射向$n。$n正要招架，$N却一个旋\n"
"身，右脚自上而下劈向$n，这一击带着极强的气，威力着实不小\n",
    "force":            150,
    "dodge":            -25,
    "parry":             -5,
    "damage_type":      "踢伤",
  ]),
  ([
    "action":
"$N朝$n面前一跃，同时左脚踢向$n的头部，接着攻势一变，以左脚\n"
"为重心，一个旋身，右脚在瞬间向$n攻出了二十连踢\n",
    "force":            190,
    "dodge":            -30,
    "parry":              0,
    "damage_type":      "踢伤",
  ]),
  ([
    "action":
"$N飞起右脚扫向$n的腰部，接着改扫为侧踢击向$n的头部,$n还没反\n"
"应过来，$N已经小跳而起，同时身体后仰，左脚自下而上踢向$n的\n"
"下巴，脚尖凝聚着"+BLINK""+HIM"紫红色"NOR+"的灵气，好个倒勾踢\n",
    "force":            110,
    "dodge":             -5,
    "parry":             -5,
    "damage_type":      "踢伤",
  ]),
  ([
    "action":
"$N右手一抬，一个"+BLINK""+HIM"紫红色灵气球"NOR+"立刻形成，\n"
"接着右手一挥，灵气球立刻向$n飞过去。不过好象那力度和角度\n"
"都差了点。$n正在奇怪，$N的身影突然在那灵气球前出现，右脚带\n"
"着雷霆万钧之势踢在球上，那球立刻流星般地朝$N电射过来\n",
    "force":            200,
    "dodge":            -10,
    "parry":            -30,
    "damage_type":      "射伤",
  ]),
  ([
    "action":
"$N双手一展，两个"+BLINK""+HIM"紫红色灵气球"NOR+"立刻形成，\n"
"接着双手一挥，灵气球立刻向$n飞过去。一前一后，速度非常快。\n"
"$N的身影突然在后面的灵气球前出现，右脚带着雷霆万钧之势踢在\n"
"球上，接着一个旋身，左脚以更大力量扫在前面的灵气球上。后面\n"
"的灵气球直线攻向$n的$l，而前面的灵气球却旋转着以曲线袭向$n\n"
"的后背",
    "force":            350,
    "dodge":            -20,
    "parry":            -20,
    "damage_type":      "射伤",
  ]),
  ([
    "action":
"$N全身放出"+BLINK""+HIM"紫红色"NOR+"的灵气，强大的气流几乎将\n"
"$n吹走。突然，$N的灵气一变，成为了"+BLINK""+HIY"金黄色的气流"NOR+"，四周的空气好象\n"
"被扯了过去一样。接着$N运力击出一记右勾拳，一个巨大的龙卷风立刻形\n"
"成，朝着$n席卷过去，巨大的力量在地上划出了一道深深的裂沟\n",
    "force":            250,
    "dodge":             -5,
    "parry":            -30,
    "damage_type":      "气流割伤",
  ]),
});

int valid_learn(object me)
{
    if(me->query("race")=="魔族")
    return notify_fail("这种武功只能由人类来继承。\n");
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
    return notify_fail("练习灵光裂蹴拳必须空手。\n");
    if( (int)me->query_skill("liejiuquan", 1 ) < 30 )
{ 
    if( (int)me->query_skill("cuixin-zhang",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");    
    if( (int)me->query_skill("changquan",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("puti-zhi",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("yinfeng-zhua",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("jinghun-zhang",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("dragonfight",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("moyun-shou",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("wuxing-quan",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("jienan-zhi",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("fumozhang",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
}
    
       if( (int)me->query_skill("spiritforce", 1) < 60 && (int)me->query_skill("segokee",1)<0)
       return notify_fail("你的灵气修为还不够，不能学习灵光裂蹴拳。\n");
       if( (int)me->query_skill("liejiuquan", 1) > 302 )
       return notify_fail("你的拳法修为已经到了无人到过的穷极境界，没办法提高了。\n");
       if( (int)me->query_skill("liejiuquan", 1) > (int)me->query_skill("spiritforce", 1 ) && (int)me->query_skill("segokee",1)<1)
{
        me->add("kee", -4000 );
        me->add("sen", -4000 );
        message_vision(HIR"$N正在学习灵光裂蹴拳，身体里的灵气突然爆发开来，$N惨叫了一声！ \n"NOR,me);
}
       return 1;
}

int valid_enable(string usage)
{ 
    return usage=="unarmed"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

int practice_skill(object me)
{
            if( (int)me->query_skill("liejiuquan", 1 ) < 60 )
{ 
    if( (int)me->query_skill("cuixin-zhang",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");    
    if( (int)me->query_skill("changquan",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("puti-zhi",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("yinfeng-zhua",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("jinghun-zhang",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("dragonfight",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("moyun-shou",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("wuxing-quan",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("jienan-zhi",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
    if( (int)me->query_skill("fumozhang",1) < 100 )
    return notify_fail("灵光裂蹴拳必须以其他拳法做基础，没有到达必要的修为之前是\n不可能就这么学习的。\n");
}
        if( (int)me->query_skill("liejiuquan", 1) > 302 )
        return notify_fail("你的拳法修为已经到了无人到过的穷极境界，没办法提高了。\n");
        if( (int)me->query_skill("spiritforce", 1) < 100 && (int)me->query_skill("segokee",1)<1)
        return notify_fail("你试着练习这种拳法，但是显然你的灵气不够。\n");       
        if((int)me->query_skill("spiritforce", 1) < (int)me->query_skill("liejiuquan", 1 ) && (int)me->query_skill("segokee",1)<1)
{
        me->add("kee", -4000 );
        me->add("sen", -4000 );
        message_vision(HIR"$N正在练习灵光裂蹴拳，身体里的灵气突然爆发开来，$N惨叫了一声！ \n"NOR,me);
}
        if( (int)me->query("sen") < 200)
        return notify_fail("你的精神无法控制气的流动了，休息一下再练吧。\n");
        if( (int)me->query("kee") < 200 )
        return notify_fail("你现在浑身疼痛难忍，休息一下再练吧。\n");
        if( (int)me->query("force") < 350 )
        return notify_fail("你的灵气不够了。\n");

        me->receive_damage("kee", 70);
        me->add("force", -30);

        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("mojie") + "/liejiuquan/" + func;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("liejiuquan", 1)==100 )
{
        me->add("kar", -2 );
        me->add("spi", 1 );
        message_vision(HIY"$N的全身突然放出强大的灵气，看来$N的修为到了一个新的阶段。\n
但是$N的身体内一阵剧痛，似乎有什么东西被夺走了一样。\n"NOR,me);
}
        if( (int)me->query_skill("liejiuquan", 1)==200 )
{
        me->add("kar", -5 );
        me->add("spi", 2 );
        me->add("str", 1 );
        me->add("max_force", 300 );
        me->add("combat_exp", 500000 );
        me->add("daoxing", 500000 );
        message_vision(HIY"$N的拳法修为到了一个新的境界，身体里剧痛难忍，似乎有什么东西被夺走了一样，\n但$N的确感到自己变厉害了。\n"NOR,me);
}
        if( (int)me->query_skill("liejiuquan", 1)==300 )
{
        me->add("kar", -10 );
        me->add("combat_exp", 1000000 );
        me->add("daoxing", 500000 );
        me->add("spi", 2 );
        me->add("str", 1 );
        me->add("cps", 1 );
        me->add("con", 1 );
        me->add("cor", 1 );        
        message_vision(HIY"巨大的痛苦从$N的身体里爆发出来，$N像发了疯一般对周围的东西拳打脚踢。\n剧烈的灵气震荡肆虐开来，地面裂成了两半。\n"NOR,me);
        me->start_busy(10);
        me->set("live_forever", 0 );
        me->set("live_forever_announced", 0 );
        write ("你感到自己变厉害了，不过好象某些东西被夺走了。\n");
        message("channel:rumor", HIY + "【西游大事】如来佛祖：听说"+
     me->query("name")+"的灵光裂蹴拳修为已经到了一个相当的境界。哇！不会来抢我的位置吧！\n"NOR,users());
}

}