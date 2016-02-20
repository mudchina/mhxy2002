#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("你只能现出自己的金身身。\n");
        if( (int)me->query_skill("evil-force",1) < 50 )
                return notify_fail("你的魔功修为不足,现金身会有生命威险. \n");
        if( (int)me->query("force") < 700 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("kee") < 150 )
                return notify_fail("你的气血不足。\n");
        if( (int)me->query("sen") < 150 )
                return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("evil-force",1);

        if ( skill>=300 ) skill=300;

        me->add("force", -300);
        me->receive_damage("kee", 130);
        me->receive_damage("sen", 130);

        message_vision(
HIY"$N魔气大盛，映堂金光一闪，竟现出魔神金身，顿时天地为之变色。\n"NOR, me);



        me->add_temp("apply/armor", skill/5);
        me->add_temp("apply/attack", skill/5);
        me->add_temp("apply/strength", skill/5);

        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :),skill);
        if( me->is_fighting() ) me->start_busy(5);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/strength", -amount);
        me->delete_temp("powerup");
        tell_object(me, "你的魔功运行一周天完毕，身体也渐渐复原了。\n");
        return;
}
