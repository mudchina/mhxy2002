#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object *inv, obj;
        int i,y, mypot,tapot,mystr,tastr,myexp,taexp,mylvl,talvl;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
return notify_fail("你要对谁施展这一招「惊天吼地」？\n");

        if(!me->is_fighting())
 return notify_fail("「惊天吼地」只能在战斗中使用！\n");

	      if((string)me->query("family/family_name") != "将军府" )
 return notify_fail("不经历沙场，怎能惊九天之吼地？\n");
 if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

     if((int)me->query("force") < 350 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 150 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
if((int)me->query_skill("jinglei-mace", 1) < 50)
 return notify_fail("你的惊雷鞭级别还不够，使用这一招会有困难！\n");

message_vision(HIW"\n半空中忽然打了道利闪，直向$n击去！\n"NOR, me, target);
me->start_busy(2+random(2));

        mystr=(int)me->query("str");
        tastr=(int)target->query("str");
myexp=(int)me->query("combat_exp")/20;
        taexp=(int)target->query("combat_exp")/30;
        mylvl=(int)me->query_skill("spear")*(int)me->query_skill("bawang-qiang");
        talvl=(int)target->query_skill("parry")*(int)target->query_skill("dodge");
        
        mypot=mystr*mylvl+myexp;
        tapot=tastr*talvl+taexp;
        
        y=random(3);
      
      if( random(mypot) >random(tapot)) {

message_vision(HIY"$N躲闪不及，被击个正着！\n"NOR, target);
   target->receive_damage("kee", 50 + random((int)me->query("max_force")/40+(int)me->query("force_factor")));
        COMBAT_D->report_status(target);
if (random(2)) {
SPELL_D->attacking_cast(
me,
target,
100,
80,
"kee",
HIR "狂雷夹带着火光，向$n呼啸不止。\n" NOR,
HIR "$n被雷火击中，一身焦黑！\n" NOR, 
HIG "$n的衣服已被燃着，所幸人却无恙。\n" NOR, 
HIB "$n袍袖一挥，将雷火尽数卷回！\n" NOR, 
RED "$n被雷火反击，自己烧了个灰眉土脸！\n" NOR
);
if( userp(target) ) target->fight_ob(me);
 else if( !target->is_killing(me) ) target->kill_ob(me);
}
}
else{
 me->add("force", -200);
  me->receive_damage("sen", 100);
 message_vision(HIC"却被$N躲开了！\n"NOR, target);
 me->start_busy(2+random(2));
return 1+random(5);
}
}
