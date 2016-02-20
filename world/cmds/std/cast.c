//modified by vikee
//2000.10
//cast.c

#include <ansi.h>
#include <skill.h>
#include "/cmds/std/valid_kill.h";

inherit F_CLEAN_UP;

void destruct_flag(object me);

int main(object me, string arg)
{
	string spells, spl, trg;
	object target;
	
	seteuid(getuid());

    if ((int)me->query_temp("in_qingwang")==1)
		return notify_fail(MAG"你眼前出现那个熟悉的身影，搅的你心烦气燥，似离情，剪不断，理还乱。\n"NOR);
	  if(me->query_temp("fu_no_cast"))
            return notify_fail("你的法术被暂时封住了！\n");

	if((int)me->query_temp("no_cast")==1)
	        return notify_fail("你现在不能用魔法！\n");

	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能念咒文。)\n");

	if( !wizardp(me) && environment(me)->query("no_magic") )
		return notify_fail("这里不准念咒文。\n");

	if( !arg ) return notify_fail("指令格式：cast <法术> [on <目标>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("这里没有 " + trg + "。\n");
		
		if(!valid_kill(me,target,0)) return 0;

		if( userp(me) && userp(target) && 
		    target->query_temp("netdead") )
		   return notify_fail("对方正在断线中，不能对其施法。\n");
	} else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");

	if( stringp(spells = me->query_skill_mapped("spells")) ) {
	        int nocast;
		notify_fail("你所学的法术中没有这种功能。\n");
		nocast=(int)SKILL_D(spells)->cast_spell(me, spl, target);
		if (!nocast) 
		  nocast=(int)SKILL_D("spells")->cast_spell(me, spl, target);
                if (nocast) {
                  me->set_temp("no_cast", 1);
		  call_out("destruct_flag", nocast, me);
		  return 1;
		}
		return 0;
		}
		
	return notify_fail("你请先用 enable 指令选择你要使用的咒文系。\n");
}

void destruct_flag(object me)
{
     if (me)
     	me->delete_temp("no_cast");
}

int help (object me)
{
        write(@HELP
指令格式：cast <咒文名称> [on <施咒对象>]
 
施法，你必需要指定<咒文名称>，<施咒对象>则可有可无。
在你使用某一个咒文之前，你必须先用 enable 指令来指定你要使用的咒文系。
 
注：如果你改变自己的咒文系，你原本蓄积的法力并不能直接转换过去，必须
    从 0 开始。
 
HELP
        );
        return 1;
}
