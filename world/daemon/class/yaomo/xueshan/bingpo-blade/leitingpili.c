// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        int d=me->query_skill("xiaoyaoyou",1)/1;
        int j=me->query_skill("bingpo-blade",1)/1;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［雷霆霹雳］只能对战斗中的对手使用。\n");                

        if( (int)me->query_skill("ningxie-force", 1) < 100 )
                return notify_fail("你的内功还不够纯熟，不能使用雷霆霹雳！\n");    
        if( (int)me->query_skill("bingpo-blade", 1) < 100 )
                return notify_fail("你的刀法还不够熟练，不能使用雷霆霹雳！\n");
        if(me->query_skill_mapped("force") != "ningxie-force")
                return notify_fail("你的内功不能配合发出绝招！\n");

                if(me->query_temp("no_leitingpili"))
                        return notify_fail("这招不能经常用! \n");
        if((int)me->query("force") < 400 )
                return notify_fail("你现在内力不足,发不出雷霆霹雳！\n");      
        weapon = me->query_temp("weapon");
        extra = me->query_skill("bingpo-blade",100);
        me->add_temp("apply/attack", (d+j)/1);  
        me->add_temp("apply/damage", (j)/1);
        me->add("force", -200);
        me->add_temp("apply/dodge", d);
        message_vision(HIR  "$N手中的"+ weapon->name() +HIR"幻出漫天刀云，"+weapon->name() +HIR"划破刀云，雷霆霹雳般的击向$n！\n" NOR,me, target);//by tianlin 2001.8.9.缺少\n,已加入
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -(d+j)/1);
        me->add_temp("apply/damage", -(j)/1);
        me->add_temp("apply/dodge", -d);
        me->set_temp("no_leitingpili",1);
                call_out("leitingpili_ok",2+random(2),me);


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

void leitingpili_ok(object me)
{ if (!me) return;
      me->delete_temp("no_leitingpili");
}