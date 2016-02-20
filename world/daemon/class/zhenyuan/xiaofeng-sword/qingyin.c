#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 string msg;
 object ob;
 object weapon2;
 int skill, ap, myexp, yourexp;

 me->clean_up_enemy();
 target = me->select_opponent();

  skill = (int)me->query_skill("sanqing-jian",1);

 if( !(me->is_fighting() ))
  return notify_fail("「清饮小酌」只能在战斗中使用。\n");

 if (!objectp(weapon2 = target->query_temp("weapon")))
  return notify_fail("对方没有使兵器, 你用不了「清饮小酌」。\n");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("双剑术必须和紫郢青索两剑配合才能发挥威力!\n");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("晓风残月剑法还得五庄观观主亲自指点才是!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("三清剑法还得五庄观观主亲自指点才是!\n");
      if((int)me->query_skill("sanqing-jian",1) < 210)
      return notify_fail("你的三清剑等级还不够!\n");
      if((int)me->query_skill("xiaofeng-sword",1) < 210)
      return notify_fail("你的晓风残月剑等级还不够!\n");
      if((int)me->query_skill("sword",1) < 210)
      return notify_fail("你的基本功还不够!\n");
 if( (int)me->query("max_force") < 1200)
 return notify_fail("你的内力太弱,不能用清饮小酌!\n");
 if( (int)me->query("force") < 500)
 return notify_fail("你的内力不够了!!\n");

     msg = HIC
"\n$N一招「清饮小酌」,左剑剑柄上提,剑尖下指,犹如提壶酌酒!\n"
"右剑却是剑尖上翻,竟是指向自已的口唇,宛似举杯自饮一般.\n\n" NOR;

 ap = skill/60+1;
 myexp = (int)me->query("combat_exp");
 yourexp = (int)me->query("combat_exp");
 if( random(myexp*ap) > yourexp)
 {
  if(userp(me))
   me->add("force",-50);
  msg += CYN
"\n$n只觉右肩一凉,顿时半条手臂转动不灵,接着虎口一震,手中";
  msg += weapon2->name();
  msg += "脱手而出!!\n" NOR;

  target->start_busy(2);
  weapon2->move(environment(me));
        }
 else
 {
  if(userp(me))
   me->add("force",-30);
  msg += HIG
"\n可是$n似乎看出此招奥妙,肩头微闪,躲开了这神妙无方的一剑!!\n" NOR;
  me->start_busy(1+random(1));
 }
 message_vision(msg, me, target);
                                       
 return 1;
} 


