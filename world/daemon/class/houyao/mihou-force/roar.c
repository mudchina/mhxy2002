// roar.c 黯然销魂吟

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;
        
//        if(!me->is_fighting())
  //              return notify_fail("「吼字诀」只能在战斗中才能使用!\n");
//        if( (string)me->query("family/family_name") !="水帘洞" )
  //                return notify_fail("只有水帘洞弟子才能使用「吼字诀」!\n");

        if( (int)me->query("force") < 150 )
                return notify_fail("你大吼一声，大家吓了一跳。\n");


        skill = me->query_skill("force");

        me->add("force", -150);
        me->receive_damage("kee", 10);

        me->start_busy(3);
        message_vision(
        MAG "$N突然蹦了起来,猴腮一鼓,发出了一声清啸.刹那间,天地变色,神鬼动容!\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me )
                        continue;
 		if( interactive(ob[i]) ) continue;

                if( !ob[i]->is_killing(me) )
                        ob[i]->kill_ob(me);
                if( !me->is_killing(ob[i]) )
                        me->fight_ob(ob[i]);

              damage = 20*skill/(int)me->query("per") - (int)ob[i]->query("max_force") / 20 ; 

                if( damage > 0 ) {
                       ob[i]->receive_damage("sen", damage,me);
                        if( (int)ob[i]->query("force") < skill * 2 )
                                 ob[i]->receive_wound("sen", damage,me);
                tell_object(ob[i], "你忽然觉得一阵寒意扑面而来，心神朦胧中漂移不定。\n");
                        ob[i]->set_temp("last_damage_from",me);
                }

        }

        return 1;
}

