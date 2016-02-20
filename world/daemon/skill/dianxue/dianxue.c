//by ephq
inherit SSERVER;
#include <ansi.h>
#include <xue.h>
#include <dianxue.h>


void remove_xue(object tar);
int perform(object me, object target)
{
	string arg,attack_skill,msg;
	int extra, dif, ap, dp, ap1, dp1, pp, app,dpp,t,power;
	object weapon;
	mapping data;

	extra = me->query_skill("dianxue",1) ;

	if ( extra < 75) return notify_fail("你的[点穴]还不够纯熟，认不准这个穴道！\n");


	if( !target ) target = offensive_target(me);
	if( !target
	||!target->is_character() )
// 	|| target->is_fighting(me))
		return notify_fail("你要对谁用这招。\n");

        if( target->is_busy() )
		return notify_fail("对方正忙着呢，何必乘人之危呢？\n");

        if((int)me->query("force") < 150 ) return notify_fail("你的内力不足！\n");
     	if(!valid_perform(me,target)) return 0;
               me->add("force", -100);


     	
        me->receive_damage("sen", 50);

        arg=xue[random(sizeof(xue))];


	data=type(me);
	if( data["type"]=="none" )
	return notify_fail("你所用的兵器不适合点穴。\n");


	dif=data["dif"]	;

       msg=HIC+"$N屏息凝神，";
       if( dif!=110 ) msg+="内力灌注"+me->query_temp("weapon")->name()+HIC+",";
       msg+="全神贯注的盯住$n的全身穴道，\n"+NOR+MAG+"突然，";
       if( dif!=110 ) msg+="手中"+me->query_temp("weapon")->name()+"的";
       msg+=data["action"]+"$n的"+HBWHT+HIR+arg+NOR+MAG+data["type"]+"去。\n\n"+NOR;

       message_vision(msg,me,target);

       ap=me->query("combat_exp");
       dp=target->query("combat_exp");
       ap1=me->query_skill("force");
       dp1=target->query_skill("force");
       pp=target->query_skill("dodge")+target->query_skill("parry");

       app=ap1*2+extra*40;
       dpp=dp1*2+pp*10;
       if( ((random(app+dpp)*dif/100 > dpp) && random(4)>1) ||( ( random(ap)>(dp*2/3) ) && random(4)>1 ) )
       {
       	msg=WHT+"结果，$n的"+HBWHT+HIR+arg+NOR+WHT"被一下子"+data["type"]+"中了，顿时全身麻痹，动弹不得。\n"+NOR;
       	t=extra/20;
       	if( t>8 ) t=8;
       	if( t<3) t=3;
       target->start_busy(t+1);
       target->set_temp("dianxue/xue1",arg);
       target->set_temp("xue1/name",me->name());
       power=extra+me->query("force_factor")*10+ap1;
       target->set_temp("xue1/power",power);
       target->start_call_out( (: call_other, __FILE__, "remove_xue", target :), t);
       message_vision(msg,me,target);
       }
       else {
       	msg=HIG+"但是，$n早有防备，身行微转，躲了开来，却乘你不备，猛的攻出一招。\n"+NOR;
       message_vision(msg,me,target);
       	me->start_busy(2);
        COMBAT_D->do_attack(target,me, target->query_temp("weapon"));
       	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->fight_ob(target);
        }
	return 1;
}

void remove_xue(object tar)
{
        if(!tar) return;
        if( !tar->query_temp("dianxue/xue1") ) return;
        tell_object(tar, "你的"+HBWHT+HIR+tar->query_temp("dianxue/xue1")+NOR+"终于自行解开了。\n");
        tar->delete_temp("dianxue/xue1");
        tar->stop_busy();
       return;
}
