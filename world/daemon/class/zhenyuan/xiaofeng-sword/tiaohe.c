// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

void remove_effect(object me, int amount);

string msg;
int perform(object me, object target)
{
        int skill;
        object ob;

        skill = me->query_skill("sanqing-jian",1);

   if( skill > 250 ) {
     skill=250;
   }
  if( (int)me->query("force") < skill*2 )
  return notify_fail("你的内力不够。\n");
  if( (int)me->query_temp("tiaohe") )
  return notify_fail("你已经在运功中了。\n");
  if( !target ) target = offensive_target(me);
 if( !target
 ||      !target->is_character()
 ||      !me->is_fighting(target) )
 return notify_fail("「池边调鹤」只能在战斗中使用。\n");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("晓风残月剑法还得五庄观观主亲自指点才是!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("三清剑法还得五庄观观主亲自指点才是!\n");
      if((int)me->query_skill("sword",1) < 180)
      return notify_fail("你的基本功还不够!\n");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("双剑术必须和紫郢青索两剑配合才能发挥威力!\n");

        me->add("force", -skill);

         msg = HIR
"\n$N双剑忽地转快,两道剑光织成一道光网,正是一招攻守兼备的「池边调鹤」!\n"
"刹那间剑气纵横,神光离合,逼得$n不敢近身半步.\n\n" NOR;
        msg += HIG
"\n过得半响,忽听$N一声清啸,身形冲天而起,剑光顿时四散而去.\n"
"只见两道淡青色的光芒托住$N的双脚,$N感到身法轻快不少!\n\n" NOR;
     message_vision(msg, me, target);
   me->add_temp("apply/dodge",skill/3);
   me->add_temp("apply/attack",skill/3);
        me->set_temp("tiaohe", 1);

me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);


        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("tiaohe");
   // mon 3/1/98. move this to after powerup is done.
        tell_object(me, HIG"你体内真气运行一周天完毕,青芒渐渐褪去.\n"NOR);
}

