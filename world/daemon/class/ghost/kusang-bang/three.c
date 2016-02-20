//modified by vikee
//2000.9
//by tianlin 2001.9.2.局部修改
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int i,j;
	        
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「"HIY"神"NOR+HIR"·"NOR+HIW"人"NOR+HIR"·"NOR+HIM"鬼"NOR"」？\n");

        if(!me->is_fighting())
                return notify_fail("「"HIY"神"NOR+HIR"·"NOR+HIW"人"NOR+HIR"·"NOR+HIM"鬼"NOR"」只能在战斗中使用！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail(HIC"你的内力不够！\n"NOR);

        if((int)me->query("kee") < 300 )
                return notify_fail(HIR"你的气血不足，没法子施用外功！\n"NOR);

        if(me->query_temp("no_gthree"))  //在此处设置标志位 
             return notify_fail("绝招使多了就不灵了！"); 

        if((int)me->query_skill("zhuihun-sword", 1) < 50)
                return notify_fail("你的"HIY"追魂剑"NOR"级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("kusang-bang", 1) < 50)
                return notify_fail("你的"HIC"苦丧棒"NOR"级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("hellfire-whip", 1) < 50)
                return notify_fail("你的"HIR"烈火鞭"NOR"级别还不够，使用这一招会有困难！\n");

        weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
	}

	me->delete("env/brief_message");
	target->delete("env/brief_message");
//by tianlin 2001.9.2.修改
	message_vision(HIR"$N双手划一大圆，猛然托天而举，伴着天上雷鸣电闪，祭出了"NOR"「"HIY"神"NOR+HIR"·"NOR+HIW"人"NOR+HIR"·"NOR+HIM"鬼"NOR"」"NOR+HIR"三招 !\n"NOR, me);
       message_vision(HIY"$N口念:·魔 鬼·饿 鬼·小 鬼·猛 鬼·恶鬼·处 处 鬼 缠 身。\n"NOR, me);
       me->set("HellZhen", 6);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
       message_vision(HIW"$N口念:·邪 神·巫 神·衰 神·魔 神·鬼 神· 招 招 有 神。\n"NOR, me);
	me->set("HellZhen", 7);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
       message_vision(HIM"$N口念:·罪 人·恶 人·坏 人·兽 人·毒 人· 式 式 存 人。\n"NOR, me);
	me->set("HellZhen", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete("HellZhen");

       if( i ) me->set("env/brief_message", 1);
       if( j ) target->set("env/brief_message", 1);

	me->receive_damage("kee", 100);
	me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);
	return 1;
}
