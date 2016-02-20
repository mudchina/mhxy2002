#include <ansi.h>
inherit SSERVER;
int exert(object me, object target)
{
        string msg;
        int lvl, ap, dp;

        if( !target ) target = offensive_target(me);
        if((int)me->query_skill("force") < 80 )
                return notify_fail("你的内功修为不够高！\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse() )
        
                return notify_fail("你要对谁施展这个捍星诀？\n");

        if(target->query_temp("in_hanxing"))
        return notify_fail("你现在并不需要施展捍星诀。\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("kee") < 50 )
                return notify_fail("你的精神没有办法有效集中！\n");

        me->add("force", -300);
        me->receive_damage("kee", 50);

        if( random(me->query("max_force")) < 30 ) {
                write("你失败了！\n");
                return 1;
        }

        msg = HIC "$N口中念念有词，一道光芒从$N头顶射出，缭绕在$n周围！\n\n" ;

        ap = me->query_skill("force");
        ap = ( ap * ap /100 * ap/30 ) * (int)me->query("kee") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
        msg +="光芒化成一身软甲，保护住$n的全身！\n";
        lvl = (int)me->query_skill("force")/4;
                target->set_temp("in_hanxing",1);
                target->add_temp("apply/armor",lvl);
                seteuid(ROOT_UID);
                target->start_call_out( (: call_other, __FILE__, "remove_hanxing",target, lvl :),
                random(lvl*3)+lvl);
        } else
                msg += "但是马上就消失了。\n";
        if(me == target) 
        {
        msg = replace_string(msg, "$n","$N");
        message_vision(msg+NOR,me);
        }
        else
        message_vision(msg+NOR, me, target);
        me->start_busy(1);
        return 1;
}

void remove_hanxing(object me, int lvl)
{
   me->delete_temp("in_hanxing");
   me->add_temp("apply/armor",-lvl);
   message_vision(HIY "\n\n$N周身的光甲发出耀眼的一闪就消失了。\n\n" NOR, me);
}

