//不动明王手印
//created by focus 2001.2.10
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        int ap,dp,att,damage;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招不动明王手印？\n");

        if(!me->is_fighting())
                return notify_fail("不动明王手印只能在战斗中使用！\n");
        
        if(me->query("family/family_name")!= "灵界")
                return notify_fail("你非灵界神灵，怎能使用不动明王手印？\n");

        if((int)me->query("force") < 600 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("guangming-shouyin", 1) < 50)
                return notify_fail("你的不动明王手印级别还不够，使用这一招会有困难！\n");
 
        if(me->query_temp("shouyin_busy")) return notify_fail("你刚颂过真言本尊咒，还是等会再颂吧..\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        
        message_vision(HIW"\n$N心持真言本尊咒，嘴里默颂：忿恚所恼妖魔众，火今仍未息耶？汝身游空无障碍，\n"NOR+
                       HIM"汝心为烦恼缚！习风缠根无自在，烦恼火炽损众生，损恼他人终自害，如是因果不环理，\n"NOR+
                       HIC"异熟果报谁能脱...\n"NOR, me);

        ap=(int)me->query("combat_exp")+(int)me->query_skill("unarmed")+(int)me->query_skill("guangming-shouyin")/3;
        dp=(int)target->query("combat_exp")+(int)me->query_skill("parry");
        att=(int)me->query("spi")+random((int)me->query_skill("spells")/10);

        if (random(ap)>dp*2/5)
{
        damage=random(att*30);

        message_vision(MAG"$N纳气于丹田，手上连结金刚界的“不金刚轮”、胎藏界的“世尊陀罗尼观自在”、\n"+"诸经诸尊的“千手根本印”击向$n...\n"NOR+HIR"将$n击出丈远.....\n"NOR,me,target);

        me->start_busy(2);
        target->receive_damage("kee",damage);
        target->receive_wound("kee",damage*2/3);
        target->start_busy(random(2));
        me->receive_damage("kee",100);
        me->add("force",-200);
//        me->set_temp("pfm_shouyin",1);
}
        else 
{
        message_vision(HIW"\n$n大惊之下，身形连连闪动，脱出手印的包围，却也惊出一身冷汗\n"NOR,me,target);
        me->start_busy(1+random(3));
        target->start_busy(random(2));
}

      me->set_temp("shouyin_busy",1);
      call_out("remove_effect",4+random(3),me);
return 1;
}

void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("shouyin_busy");
}
