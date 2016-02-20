//jiz.

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int mypot,tapot,time;

        if( !target ) target = offensive_target(me);

        if( !target

        ||      !target->is_character()

        ||      !me->is_fighting(target) )
               return notify_fail("「若有所失」只有在战斗中才能使用。\n");
        if(me->query("family/family_name")!="方寸山三星洞")
               return notify_fail("非方寸山三星洞不能用「若有所失」！\n");
        if( (int)me->query_skill("qianjun-bang", 1) < 150 )
                return notify_fail("你的修为不够深，还使不出这一招！\n");
        if( target->is_busy() )
                return notify_fail(target->name()+"看来你的动作难以使对方迷茫。\n");

       message_vision(WHT"$N手中兵器荡出层层烟雾，朦朦胧胧，将$n罩了起来。
 $n仿佛看到了自己的过去，陷入了无限的回忆中去！\n\n"NOR,me, target);

        mypot=(int)me->query_skill("stick");
    mypot=mypot*mypot*mypot/3 + random( (int)me->query("combat_exp"));

        tapot=(int)target->query_skill("parry");
        tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));

     time=(int)me->query_skill("qianjun-bang", 1) /4;
        if ( time > 10 ) time = 10;
        if ( time < 3  ) time = 3;

        if ( random( mypot + tapot ) > tapot ) {
                       message_vision(HIC"$N呆呆的站立着，一种若有所失的感觉涌上心头，顿时忘了自己还在战斗中！\n"NOR,target);
         target->start_busy(3+random(time));
          me->start_busy(random(2));

        }else {
        message_vision(HIC"不料$N很快从回忆中解脱出来，重新投入战斗！\n"NOR,target,
me);
               me->start_busy(1+random(3));
        }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
        return 1;
}
