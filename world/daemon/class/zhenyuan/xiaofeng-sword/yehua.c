// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int myexp,yourexp,lvl,ap;
   object weapon, ob;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
       return notify_fail("「西窗夜话」只能在战斗使用。\n");
        weapon = me->query_temp("weapon");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("晓风残月剑法还得五庄观观主亲自指点才是!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("三清剑法还得五庄观观主亲自指点才是!\n");
      if((int)me->query_skill("sword",1) < 180)      return notify_fail("你的基本功还不够!\n");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("双剑术必须和紫郢青索两剑配合才能发挥威力!\n");
   if( (int)target->query("force") < 400)
    return notify_fail(target->query("name")+"已经真气涣散了!!\n");
   if((int)me->query("max_force") < 1500)
    return notify_fail("你的内力太弱,不足以施展「西窗夜话」。\n");
   if((int)me->query("force") < 500)
    return notify_fail("你的内力不够了!\n");
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
 	lvl = (int)me->query_skill("sanqing-jian",1)/30;
 	ap = (int)me->query_skill("xiaofeng-sword",1)*3;
 msg = HIC

"\n只见$N白衣飘飘,寒光闪闪,剑光便如两条银蛇般绕着$n的全身游走不定!\n"
"奇在双剑同是一招「西窗夜话」,却是左剑缓刺$n气海穴,右剑急射$n脑后玉枕穴!\n\n" NOR;
        if( random(myexp * lvl) > yourexp )
        {
      msg += HIR
"\n双剑合璧,威力立时大得惊人,$n不及招架,嗤嗤两声,身上两剑齐中.\n"
"$n只觉丹田一麻,大吼一声,全身真气狂泄而出!!!\n\n" NOR;
        target->add("force",-ap);
        target->start_busy(1+random(1));
        }
   else {
   msg += HIY
"\n只听「叮」地一声长响,$n后退两步,脸上不由变色.\n"
"原来那声长响是由四十余下兵刃相交之声组成,,适才攻势之急,由此可见一斑!!\n\n" NOR;
            me->add("force",-150);
            me->start_busy(1+random(1));
}
message_vision(msg, me, target);
        return 1;
}
