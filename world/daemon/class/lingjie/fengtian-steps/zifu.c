//紫缚
//created by focus

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int shu, mepo, tarpo;
        
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");

        shu = me->query_skill("fengtian-steps",1) ;
        if ( shu < 80) return notify_fail("你的[飞天神紫云步]还不够熟练！\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［紫缚］只能对战斗中的对手使用。\n");

        if((int)me->query("force") < 400 ) return notify_fail("你的内力不足，无法使用紫缚！\n");
        if((int)me->query("mana") < 400 ) return notify_fail("你法力不足，无法使用紫缚！\n");
        if((int)me->query("sen") < 400) return notify_fail("你的精力不足，无法使用紫缚！\n");
        if (me->query("family/family_name")!="灵界") return notify_fail("你非灵界弟子，怎能使用紫缚! \n");
        if(me->query_temp("zifu_busy")) return notify_fail("你刚用过紫缚，还事等会再用吧..\n");
        
        mepo = (int)me->query("combat_exp")+(int)me->query_skill("dodge")+(int)me->query_skill("fengtian-steps");
        mepo = mepo + (int)me->query("mana");
        
        tarpo = (int)target->query("combat_exp")+(int)me->query_skill("dodge");
        tarpo = tarpo + (int)target->query("mana");

        if(random(mepo) > tarpo/2)
 {
        message_vision(
        HIM "\n\n$N旋空而起，卷起一股股淡淡的紫云，将$n紧紧的裹住.....\n\n" NOR, me,target);

        target->start_busy(8+random(5));
        me->add("force", -300);
        me->receive_damage("sen", 250);
}
else {
       message_vision(
       HIB "\n$n已有警觉，身体飘然向后退去......\n" NOR, me, target);

       me->start_busy(random(3));
       me->receive_damage("sen",100);
     }
       me->set_temp("zifu_busy",1);
       call_out("zifu_busy",5+random(3),me);
       return 1;
}

void zifu_busy(object me) {
      if (!me) return;
      me->delete_temp("zifu_busy");
}
