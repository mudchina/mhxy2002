//By tianlin@mhxy for 2001.12.13
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
        object weapon;
        int i,j,k,u,damage;
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(""YEL"你要对谁使用"WHT"真武七绝阵？\n"NOR);
		if(me->query("family/family_name")!="武当派")
                return notify_fail("非武当派不能用「真武七绝阵」！\n");
        if((int)me->query("max_mana") < 700 )
                return notify_fail("你的法力太差尽了。\n");
        if((int)me->query("mana") < 300 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("wudang-xianfa", 1) < 100)
        	return notify_fail("你的武当仙法等级不够，不能使用这一招！\n");
	k=(int)me->query_skill("sword");
       j=(int)target->query_skill("dodge");
                  if(k<50)        
                return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");
u=1+k/50;
if (u>6) u=6;
me->delete("env/brief_message");
	target->delete("env/brief_message");
message_vision(BRED+WHT"\n$N仰天大喝了一声："NOR,me,target);
message_vision("\n\n\t"BRED+HIW"真"NOR"\n\t\t"BBLU+HIY"武"NOR"\n\t\t\t"BBLU+HIW"七"NOR"\n\t\t\t\t"HBRED+HIY"绝"NOR"\n\t\t\t\t\t"HBRED+HIC"阵"NOR"\n"NOR,me,target);
message_vision(HIW"只见$N默默念起真武剑阵的心法要领,仿佛$n看见千军万马的阵型.\n"NOR+HIC"简直就是无人能及!"NOR,me,target);
for (i=0;i<=u;i++)
{
if (random(k+j)>j) {
           message_vision(CYN"\n$n一个不慎，唉上了一剑.\n"NOR,me,target);
damage=100+random(100);
target->receive_damage("kee",damage);
target->receive_wound("kee",damage/3);
	    COMBAT_D->report_status(target);
me->receive_damage("sen", 10);
me->add("mana", -20);
}
             else {
           message_vision(YEL"\n$n左跳右闪，好不容易避开了一轮剑雨\n"NOR,me,target);
me->receive_damage("sen", 10);
me->add("mana", -20);
}
}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
       me->start_busy(1+random(1));
       target->start_busy(1+random(2));
       return 2+random(3);
}
