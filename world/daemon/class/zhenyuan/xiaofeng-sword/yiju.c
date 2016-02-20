// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl;
   object weapon, ob;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
       return notify_fail("「小园艺菊」只能在战斗中使用。\n");
        weapon = me->query_temp("weapon");
   if((int)me->query("max_force") < 1200)
   return notify_fail("你的内力太弱了!\n");
   if((int)me->query("force") < 500)
   return notify_fail("你的内力不够了!\n");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("晓风残月剑法还得五庄观观主亲自指点才是!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("三清剑法还得五庄观观主亲自指点才是!\n");
      if((int)me->query_skill("sword",1) < 210)      return notify_fail("你的基本功还不够!\n");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("双剑术必须和紫郢青索两剑配合才能发挥威力!\n");

   if( target->is_busy() )
    return notify_fail(target->query("name")+"已经全身酸软,动弹不得了!\n");
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
 	lvl = (int)me->query_skill("sanqing-jian",1)/40;
 msg = HIC

"\n$N左剑轻扬,飘身而进,姿态翩然若仙,剑锋向着$n的下盘连点数点!\n"
"右剑却无声无息的绕到$n背后,忽地反转倒刺,正是一招小园艺菊!!\n\n" NOR;
        if( random(myexp * lvl) > yourexp )
        {
      msg += HIG
"\n只听嗤嗤数响,$n下盘,小腹处的几处穴道已同时被剑尖所封!!\n"
"$n只觉全身一麻,登时动弹不得..\n\n" NOR;
                target->start_busy(3+random(3));
        }
   else {
  msg += CYN
"\n只听得叮叮叮叮十二声急响,纵是琵琶高手的繁弦轮指也无此急促!!\n"
"$n手中的兵刃始终没闲着,终于将这一十二下急攻挡了过来.\n\n" NOR;
                        me->start_busy(2);
}
message_vision(msg, me, target);
        return 1;
}
