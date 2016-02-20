// 闪避术.c

inherit SKILL;

string *dodge_msg = ({
        "$n向左一闪躲了过去。\n",
        "$n向右一闪闭了过去。\n",
        "$n一个左跨步，一个右跨步，已然站在了$N的身后。\n",
        "$n向后几个纵身，已在数丈开外。\n",
        "$n一个旋身正好与$N站了个背对背。\n",
        "$n侧身一个空翻单手支地，向空中腾起。\n",
        "$n一俯身，双掌推地贴地向后倒飞，闪了过去。\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 0 )
        return notify_fail("你的内力不够，没有办法修行闪避术。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能参透闪避术了。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}


