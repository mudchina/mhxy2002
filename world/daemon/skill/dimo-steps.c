inherit SKILL;
string *dodge_msg = ({
        "$n全身化出千百个身影,躲闪开了$N这一招。\n",
        "$n气聚丹田，身形急缩，躲开$N那致命一击。\n",
        "$n真气荡漾，清啸连连，滑出丈外。\n",
        "$n双脚轻踏九曲，身形无比美妙地荡开数尺。\n",
        "$n身形化实为虚,躲开了$N这一招。\n",
        "$n腾空一跃，双脚凌空虚踏，躲开数尺。\n",
        "$n身形晃动，全身化作无数虚影掠出丈外。\n",
        "$n猛吸一口气，身形以一个无比怪异的姿势扭曲着弹开数尺。\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力太差了，不能练人魔连环八步。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不足，不能练人魔连环八步。\n");
        me->receive_damage("kee", 30);
        me->add("force",-5);
        return 1;
}
