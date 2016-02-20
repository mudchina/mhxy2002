#include <ansi.h>

inherit SSERVER;

void remove_zhang(object me);

int cast(object me, object target)
{
        int skill,addkee;

        if( target != me ) 
                return notify_fail("你只能对自己用这个法术。\n");

        if( (int)me->query("force") < 700 )     
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("mana") < 700 )
		return notify_fail("你的法力不足。\n");
	if( (int)me->query("max_force") < 500 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("max_mana") < 500 )
		return notify_fail("你的法力不足。\n");	
	if( (int)me->query("sen") < 200 )
                return notify_fail("你的精神无法集中！\n");	
        if( (int)me->query_temp("powerzhang") ) 
                return notify_fail("你已在变化中了。\n");
        if (me->is_busy() || me->query_temp("pending/exercising")
        	|| me->query_temp("doing_xiudao")|| me->query_temp("pending/meditating"))
              return notify_fail("你现在正忙着呢，等会儿再说吧。\n");          

        skill = (me->query_skill("dragonforce",1)+me->query_skill("seashentong",1)+2)/2;
	if(skill<50)
        addkee= (int)me->query("max_kee")/5;
	else if(skill<100)
        addkee= (int)me->query("max_kee")*2/5;
	else if(skill<150)
        addkee= (int)me->query("max_kee")*3/5;
        else if(skill<200)
        addkee= (int)me->query("max_kee")*4/5;
	else
        addkee= (int)me->query("max_kee");
	
	me->add("kee", addkee);
        me->add("eff_kee", addkee);
        me->receive_damage("sen", 100);
        me->add("force", -500);
        me->add("mana",  -500);
        
        message_vision(HIW"$N捻个诀，使出法天象地的神通，把腰一躬，喝声长。\n顿时变成个身高数丈，腰阔十围的巨人。\n"NOR, me);

        me->set_temp("powerzhang", 1);
        me->start_busy(2+random(3));
   me->start_call_out( (: call_other, __FILE__, "remove_zhang", me :),skill*3/4);

        return 1;
}

void remove_zhang(object me)
{
        me->set("kee",(int)me->query("max_kee"));
        me->set("eff_kee",(int)me->query("max_kee"));
	me->delete_temp("powerzhang");
        message_vision(HIW"$N念句咒语收了法身，自然返本归原。\n"NOR, me);
	return;
}
