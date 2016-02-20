// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int ap, bp, cp, myexp, yourexp;
        object weapon, ob;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("「花前月下」只能在战斗中使用.\n");
weapon = me->query_temp("weapon");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("双剑术必须和紫郢青索两剑配合才能发挥威力!\n");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("晓风残月剑法还得五庄观观主亲自指点才是!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("三清剑法还得五庄观观主亲自指点才是!\n");
      ap = (int)me->query_skill("xiaofeng-sword",1);
      if((int)me->query_skill("sanqing-jian",1) < 210)
      return notify_fail("你的三清剑等级还不够!\n");
      if((int)me->query_skill("xiaofeng-sword",1) < 210)
      return notify_fail("你的晓风残月剑等级还不够!\n");
      if((int)me->query_skill("sword",1) < 210)
      return notify_fail("你的基本功还不够!\n");
      if((int)me->query("force") < 500)
      return notify_fail("你的内力不够了!\n");   
      if((int)me->query("max_force") < 1200)
      return notify_fail("你的内力太弱了!\n");
    msg = HIC
"\n$N一声清吟,剑法忽然变得迅捷异常,当真剑光似电,剑气如神,正是「玉女素心剑法」!!\n" NOR;
message_vision(msg, me, target);
  me->delete("env/brief_message");
   target->delete("env/brief_message");
   me->set_temp("XFS_perform",9);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
me->delete_temp("XFS_perform");
   me->add("force",-100);  
   me->start_busy(1);

        return 1;
}
