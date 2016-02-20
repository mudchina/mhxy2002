// segokee.c  圣光气
//created by foc,29-6-01
//特点说明：最强的斗气，在所有气的质中是最高的，也是最厉害的。

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int practice_skill(object me)
{
    if((int)me->query_skill("force",1) < 250)
    return notify_fail("你试着修炼圣光气，但是没有任何进步，似乎是基础不够。\n");
    if((int)me->query("max_force")<2000)
    return notify_fail("不行，你的气不足以开始修炼圣光气。\n");
    if(me->query_skill("moonforce",1)     
                || me->query_skill("ningxie-force",1)
                || me->query_skill("lengquan-force",1)
                || me->query_skill("zhenyuan-force",1)
                || me->query_skill("huntian-qigong",1)
                || me->query_skill("tonsillit",1)
                || me->query_skill("dragonforce",1)
                || me->query_skill("huomoforce",1)
                || me->query_skill("wuxiangforce",1)
                || me->query_skill("lotusforce",1)
                || me->query_skill("zixia-shengong",1)    
                || me->query_skill("evileye",1))
    return notify_fail("你身上的气不纯，不能修炼圣光气。\n");
    if((int)me->query("combat_exp")<2300000)
    return notify_fail("你的战斗经验不足，恐怕不能很好地控制气的流动。\n");
    if((int)me->query("daoxing")<1000000)
    return notify_fail("你的修为不足，恐怕不能很好地控制气的流动。\n");
    if((int)me->query_skill("segokee",1)>151)
    return notify_fail("你的圣光气已经练到了能够修炼的极限，以后的进步只能看你的运气了。\n");
    if((int)me->query("kee")<200)
    return notify_fail("你现在体力不足，爱惜生命吧！\n");
    if((int)me->query("sen")<200)
    return notify_fail("你已经太累了，爱惜生命吧！\n");
    if((int)me->query("force")<200)
    return notify_fail("你刚开始修炼圣光气，却发现自己的气不够了，只好停了下来。\n");
    me->receive_damage("kee",100);
    me->receive_damage("sen",100);
    me->add("force",-10);
    return 1;
}
/*
int valid_learn(object me) 
{
        return notify_fail("练成圣光气的人本就很少，加上各人的气都不相同，没办法通过学习来进步。\n");
}
*/
string exert_function_file(string func)
{
        return CLASS_D("mojie") + "/segokee/" + func;
}

void skill_improved(object me)
{
    if((int)me->query_skill("segokee",1)==10)
{
    message_vision(HIY "$N试着放出自己的圣光气，但刚放出一点，就诱发了地震。\n看起来，$N的圣光气到了一个新的境界。\n" NOR,me);
    message("channel:rumor", HIM + "【西游报道组】欧巴桑A：哇，不好啦，地震啦！\n"NOR,users());
    message("channel:rumor", HIM + "【西游报道组】欧巴桑B：听说地震的起因是"+me->query("name")+"在修炼圣光气的时候……\n"NOR,users());
    me->add("str",1);
    me->add("spi",1);
    me->add("con",1);
    me->add("cor",1);
    me->add("per",1);
    me->add("cps",1);
    me->add("int",1);
    me->add("kar",-5);
}
}