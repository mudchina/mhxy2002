// 妙手回春
// 97/9/30  by Aug

inherit SKILL;




int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("literate", 1) < 40 )
		return notify_fail("你的文学修养不足，不能领悟妙手回春的精髓。\n");
		
	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法使用银针。\n");

	return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}



