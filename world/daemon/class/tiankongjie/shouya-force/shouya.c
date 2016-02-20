#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage, force;

        if( (int)me->query("force") < 1500 )
                return notify_fail("你的内力不够，如果冒失运功，小心被反噬。\n");
        if( (int)me->query("kee") < 1500)
                return notify_fail("你的力气不够了，没有实力抵抗自己发出的寒气。\n");

        if((int)me->query_skill("shouya-force", 1) <150)
                return notify_fail("你的兽牙魔经级别还不够！\n");

        if(!me->is_fighting())
                return notify_fail("「兽牙烈光弹」只能在战斗中使用！\n");
        skill = me->query_skill("force");
        force = me->query("max_force");
        me->add("force", -1000);
        me->receive_damage("kee", 100);

        me->start_busy(2);
        message_vision(HIW "
$N仰天狞笑，狂吼一声：兽牙烈光弹！！
随即双手张开。元气弹如同暴风骤雨般从$N身体象外飞出！
一时间，天地间扬起一片窒息的气氛！仿佛$N能毁灭一切！天也变成了血红色！
\n"
NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                damage = skill + force/10 - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("kee", damage);
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("kee", damage/2);
                        tell_object(ob[i], HIR"你感到一阵窒息，被无数的元气弹冲击，如同撕裂一般，\n疼痛中你感到了死神的降临！\n"NOR);
                }
                COMBAT_D->report_status(ob[i]);         
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

        return 1;
}


