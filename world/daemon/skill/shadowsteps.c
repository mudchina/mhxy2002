// shadowsteps.c


inherit SKILL;


string *dodge_msg = ({
	"$n一招「随影随形」身形一变,已绕到一个本来绝对不可能绕到的地方。\n",

                        	"只见$n纵身上前,居然如「附骨之蛆」不退反进,贴身上来。\n",
                        
	"$n使出「无影无踪」，竟然不见了踪迹。\n",

	                        "$n左足一点，一招「扑溯迷离」身影居然化为两个,不停旋转,让人无法辨别。\n",
	
});

    
int valid_enable(string usage)
{
        return (usage=="dodge");
}

     string query_dodge_msg(string limb)
    
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
    

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练迷踪幻影步法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 12;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("shenjian") + "/shadowsteps/" + action;
}

