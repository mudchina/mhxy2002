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
                return notify_fail("你要对谁施展这一招「鬼门大开」？\n");
//                        if(me->query("family/family_name") != "阎罗地府")
//                return notify_fail(HIG"「鬼门大开」"+NOR"是冥界不传之密！\n");

        if(!me->is_fighting())
                 return notify_fail("「鬼门大开」只能在战斗中使用！\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

//        if((int)me->query_skill("zhuihun-sword", 1) < 100)
//                return notify_fail("你的追魂剑级别还不够，使用这一招会有困难！\n");

//        if((int)me->query_skill("kusang-bang", 1) < 100)
//                return notify_fail("你的苦丧棒级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("hellfire-whip", 1) < 120)
                return notify_fail("你的烈火鞭级别还不够，使用这一招会有困难！\n");

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

message_vision(HIR"\n$N一掌打在胸口上，一口鲜血喷向空中，猛然举起双手。\n"NOR+ HIC"$N嘴里念叨着：“地狱里熊熊烈火燃烧起来！冥王请开启地狱之门。”\n "NOR, me);

//      me->set("HellZhen", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n冥王说道：『鬼门大开』\n"+ HIC"地下冒出了许多的幽灵，在围着$N和$n徘徊，正准备吸人阳气。\n"NOR,target,me);

//      me->set("HellZhen", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n冥王说道：『小鬼勾魂』\n"+ HIC"远方飞来许多鬼火，象流星般在$n和$N的身旁经过,鬼火越来越多。\n"NOR,target,me);

//      me->set("HellZhen", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n冥王说道：『无常索命』\n"+ HIC"白黑二无常突然出现在$N和$n的面前，立刻战斗起来。\n"NOR,target,me);

//      me->set("HellZhen", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n冥王说道：『阎罗再现』\n"+ HIC"阎罗王在地底下怒喝到：$N竟敢惊动本王，那命来！\n"NOR,target,me);

//      me->set("HellZhen", 6);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n冥王说道：『六道轮回』\n"+ HIC"地藏王菩萨在空中大怒到：何方神怪，在此撒野那命来！\n"NOR,target,me);

//      me->set("HellZhen", 6);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n冥王说道：众儿郎回府！\n"NOR,target,me);
//      me->delete("HellZhen");

        if( i ) me->set("env/brief_message", 1);
        if( j ) target->set("env/brief_message", 1);

       me->receive_damage("kee", 0);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(2));
        return 1;
}