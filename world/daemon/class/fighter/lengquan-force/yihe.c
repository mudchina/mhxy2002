#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, time;

	where=environment(me);
	if( where->query("no_fight") )
		return notify_fail("安全区内不能乱吼乱叫！\n");

        if( !me->is_fighting() )
                return notify_fail("“一喝”只能在战斗中使用。\n");
        
   if((int)me->query_skill("lengquan-force",1) < 60)
		return notify_fail("你的冷泉神功还不够，使用这一招会有困难!\n");        

       if( (int)me->query("force") < 300 )
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 100)
		return notify_fail("你的力气不够了。\n");

        skill = me->query_skill("force");
        me->add("force", -150);
       me->receive_damage("kee", 50);

    me->start_busy(2+random(2));
	message_vision(HIW "\n$N气沉丹田，突然将脚一顿，瞠目大喝一声：“喝！！！！！”\n\n"NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
		if(!me->visible(ob[i])) continue;
                time = (int)me->query("cps")+(int)me->query("cor")-((int)ob[i]->query("cps")+(int)ob[i]->query("cor"));
if( time > 10 ) time =10;
if (time<2) time=2;
damage=(int)me->query_skill("lengquan-force",1)/2+(time+8)*(time+8);
if( (int)ob[i]->query_skill("force") < random(skill * 5/2 ))
{
ob[i]->receive_damage("sen", damage, me);
                   ob[i]->start_busy(3+random(time));
                tell_object(ob[i], HIY"你猛然一哆嗦，只觉的手脚发软，一时间呆在当场！\n"NOR);
                COMBAT_D->report_sen_status(ob[i]);		
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
}
        }
        return 1;
}

