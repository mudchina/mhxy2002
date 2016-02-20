//evileye.c 邪眼术
//create by foc,9-6-01
//特点：极难修炼，在修炼时很容易死掉。

inherit FORCE;

#include <ansi.h>

int valid_enable(string usage)
{ 
    return usage=="force";
}

int valid_learn(object me) 
{ 
    if( (int)me->query("combat_exp",1) < 200000 )
    return notify_fail("开玩笑，现在让你学，万一你控制不了邪眼怎么办？\n爱惜生命吧！罗马不是一天修成的。\n");
    if( (int)me->query("daoxing",1) < 250000 )
    return notify_fail("不行，你的修行不足以控制邪眼。\n");
    if( (int)me->query_skill("force", 1) < 60 )
    return notify_fail("就你这点修为要学邪眼术？玩命哪？\n");
    if( (int)me->query_skill("evileye", 1) > 290 )
    return notify_fail("你的邪眼术已经到了一个前所未有的境界，无法再有任\n何提高了。\n");
    
    return 1;
}

int practice_skill(object me)
{
    if( (int)me->query_skill("force", 1) < 80 )
    return notify_fail("就你这点修为要练邪眼术？玩命哪？\n");
    if( (int)me->query_skill("evileye",1) < 80 )
    return notify_fail("你试着练习邪眼术，但是没有任何进步。\n");
    if( (int)me->query_skill("force",1) < (int)me->query_skill("evileye", 1)+3  && (int)me->query_skill("force", 1) > 70 && (int)me->query_skill("evileye", 1) > 70 )
    me->receive_damage("kee", 500 - (int)me->query_skill("force",1)/2 );
    message_vision(HIR"$N头上的邪眼突然放出奇异的光芒，$N不由得感到一阵巨痛，\n似乎生命开始离$N而去。\n"NOR,me);
    return notify_fail("突然一股鲜血从你的双眼中喷了出来！\n");
    if( (int)me->query("kee") < 200 )
    return notify_fail("你的体力不够。\n");
    if( (int)me->query("shen") < 200 )
    return notify_fail("没足够的精力怎么控制邪眼？\n");
    if( (int)me->query("force") < 50 )
    return notify_fail("你的妖气不够了。");
    me->receive_damage("kee", 60);
    me->receive_damage("sen", 60);
    me->add("force",-20);

    return 1;
}

string exert_function_file(string func)
{
      return CLASS_D("mojie") + "/evileye/" + func;
}   

//以下的内容是给修炼evileye的玩家的奖励。

void skill_improved(object me)
{
    tell_object (me, "哇，你好厉害呀，帅呀！\n");
}
