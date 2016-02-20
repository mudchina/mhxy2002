//jinsheng by yushu 2001.2
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage, qi,ap, dp,qixue,eff_qi,max_qi,qi_pcg;

        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail(HIW"你只能在战斗中使用。\n"NOR);


       qi=me->query("eff_kee");
       if (qi>=500)
           return notify_fail(HIY"还未到山穷水尽的地步，没必要拼命。\n"NOR);

        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("不是蜀山的不能用「御剑今生」！\n");
        
        if(me->query("shushan/jinsheng_perform")!=1)
                return notify_fail("你还没领会「御剑今生」！\n");

        if((int)me->query("max_force") < 1500 )
                return notify_fail("你的内功太差。\n");

        if((int)me->query("max_mana") < 1500 )
                return notify_fail("你的法力太差。\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("mana") < 500 )
                return notify_fail("你的法力不足！\n");

        if((int)me->query_skill("xianfeng-spells", 1) < 150)
                return notify_fail("你的仙风云体术等级不够，不能使用这一招！\n");
        
        if((int)me->query_skill("sword", 1) < 150)
                return notify_fail("你的基本剑法等级不够，不能使用这一招！\n");

        me->set("kee", 0);
        me->set("eff_kee",0);
        me->set("sen",0);
        me->set("eff_sen",0);
        me->set("force",0);
        me->set("mana",0);

        message_vision(HIB"\n$N眼见不敌，想起了访宁桥上那首诗，心中默念：",me,target);
        message_vision(HIG"\n\n所有的这一切都只有等待来生了......",me,target);
        message_vision(HIB"\n\n$N一念及此，身形与"+weapon->name()+NOR+HIB"化为一体直射$n～～～～～ \n\n"NOR,me,target);

        ap = me->query_skill("sword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  
        if(random(2)+(random(ap + dp) <  dp) ) {
        message_vision(HIB"\n\n$n一见情势不妙，拼命向后纵越，竟然在狼狈不堪之际侥幸地躲过了这拼命的一式！！！\n\n"NOR,me,target);
        target->start_busy(5+random(3));
         } else {
	 target->die();
        message_vision(HIB"\n\n$n不料$N如此决绝，竟然呆立当场，瞬间一道蓝光已在$n身上当胸穿过！！！\n\n"NOR,target,me);
        }
        message_vision(HIR"\n\n半空中传来一声长叹：天绝我～～～～～ \n\n"NOR,me);
        me->unconcious();
        return 1;
}

