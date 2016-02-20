//Cracked by Roath
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int mysen,tarsen,myspi,tarspi,myskill,tarskill,chance;
        if( !target ) target = offensive_target(me);
        if(me->query("family/family_name") != "阎罗地府" )
                return notify_fail("你可伤不了别人的心！\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招"+HIR"「伤心神剑」"NOR+"？\n");
    
        if(!me->is_fighting())
                return notify_fail(HIR"「伤心神剑」"NOR+"只能在战斗中使用！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("zhuihun-sword", 1) < 100)
                return notify_fail("你的追魂剑级别还不够，不能化剑于无形！\n");

        if((int)me->query("renru") !=1)
                return notify_fail("你还没有领悟"+WHT"忍辱神功"NOR+"的要领！\n");

        if((int)me->query("shanzijing") !=1)
                return notify_fail("你还没学会"+WHT"山字经"NOR+"！\n");
        myskill= (int)me->query_skill("zhuihun-sword",1);
        tarskill=(int)target->query_skill("dodge",1);  
        mysen=(int)me->query("sen");
        tarsen=(int)target->query("sen");   
        myspi=(int)target->query("spi");
        tarspi=(int)target->query("spi");

        weapon=me->query_temp("weapon");
      message_vision(HIB"$N断喝一声：以天下英雄为弓，以天下美女为箭！这正是一招\n\n"NOR+ HIB"  》》》》"+HIR"——————>>\n"+HIR"             『伤      心      小      箭』"NOR+HIB"！\n\n"NOR,me);
      message_vision(HIB"$N手中的"+weapon->name()+HIB"化为一支锐不可挡的箭暴射出去，正对$n"NOR+HIB"的心房。\n" NOR,me,target);        
      if (random(myskill*myspi)>random(tarskill*tarspi/2))
     {
      message_vision(HIB"结果这一箭正中$n"NOR+HIB"的前胸，伤透了$n"NOR+HIB"的心。\n"NOR,me,target);
      target->receive_damage("kee", mysen*2/3, me);
      target->receive_wound("kee", mysen*2/3, me);
       target->receive_damage("sen", mysen*2/3, me);
      COMBAT_D->report_status(target);
      me->receive_damage("kee", 100);
      me->add("force", -100);
      me->start_busy(1+random(2));
      return 1;
      }
      else
      {
       message_vision(HIC"没想到$n"+HIC"胸膛突尔出现了一个洞，箭正从洞中穿出，把$N吓了一跳。\n"NOR,me,target);
       me->start_busy(2+random(3));
       return 1;
      }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }      
    //    return 1;
}
