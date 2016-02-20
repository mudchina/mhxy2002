//By tianlin@mhxy for 2002.1.17

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
       string str;//谣言的变量
        int success_adj, damage_adj;

        success_adj = 110;//全部降低
        damage_adj = 110;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这招"HIW"剑"HIR"中"HIW"剑"NOR"？\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够，无法御剑！\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("你无法集中精力，别插中自己了！\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("好象没反应，再来一次吧！\n");
                return 1;
        }
       message_vision(HIC"\n$N对着$n"NOR+HIC"大喝一声:"BLINK+HIR"看剑"NOR+HIC"！\n"NOR,me,target);
       message_vision(HIR"\n      劍   劍   劍   劍   劍   劍   劍   劍\n\n\t"HIB"剑   剑   剑   剑   剑   剑   剑\n\n"HIR"      劍   劍   劍   劍   劍   劍   劍   劍\n\n"NOR,me,target);
	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIY "$N"NOR+HIY"剑光四射光彩满天，奇异中化成一道彩虹，\n$N"NOR+HIY"不由的一愣，刹那间，那彩虹又汇成一剑,\n剑气弥漫，剑色迷人，当$N"NOR+HIY"发觉是剑气已侵人心脾，\n剑色已夺去$n"NOR+HIY"的心志，$n"NOR+HIY"奈的想到了，\n这就是传说中的"HIW"剑"HIC"中"HIW"剑"HIY"！\n" NOR,
			//initial message
		HIY "只见这把剑活活的插在了$n"NOR+HIY"的身上！\n" NOR, 
			//success message
		HIY "但是$n"NOR+HIY"身体轻轻一闪，躲了过去。\n" NOR, 
			//fail message
		HIY "但是$N"NOR+HIY"一个不小心，剑没有出去却掉在自己的脚上！\n" NOR, 
			//backfire initial message
		HIY "只见这把剑活活的插在了$n"NOR+HIY"的身上！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=NOR+YEL+target->name()+HIM"被"NOR+CYN+me->name()+HIM"用"HBRED+HIW"神剑山庄"NOR+HIY"绝学"HIC"“"HIW"剑"HIR"中"HIW"剑"HIC"”"NOR+HIM"送去了"HIB"阎罗地府"HIM"，据说"NOR+YEL+target->name()+HIM"是被万剑穿心而死！";
                        message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
                       }
        me->start_busy(2+random(3));
        return 3+random(6);
}


