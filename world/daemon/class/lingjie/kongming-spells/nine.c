//九字真言 created by focus 2001.2.15

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   int damage,ap,dp,att,chance;
   string msg;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("你要对谁用「九字真言」？\n");

   if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［九字真言］只能对战斗中的对手使用。\n");
   
   if(me->query("family/family_name")!="灵界")
     return notify_fail("你非灵界弟子，无法使用[九字真言]\n");

   if((int)me->query_skill("kongming-spells", 1) < 100 )
     return notify_fail("你的空明心法还需要修炼！\n");

   if((int)me->query("mana") < 600+random((int)me->query("sen") ))
     return notify_fail("你的法力不够，无法使用「九字真言」！\n");

   if((int)me->query("force") < 600 )
     return notify_fail("你的内力不够，无法使用「九字真言」。\n");

   if((int)me->query("sen") < 400 )
     return notify_fail("你现在神智不清！\n");

   if((int)me->query("kee") < 400 )
     return notify_fail("你现在体力不够！\n");

   message_vision(HIC"$N双手飞快的在身前结扣着空明手结，[临、兵、斗者、皆、阵、列、于、前]，刹时天崩地裂，$N化成一道明亮的白光，飞向$n..！\n\n" NOR, me, target);

   att=(int)me->query("cps")+(int)me->query("ker");
   ap= me->query_skill("spells")+me->query_skill("kongming-spells")+me->query("daoxing")/2;
   ap =  ap*random(ap)/100;
   dp = target->query_skill("dodge")+target->query_skill("spells")+target->query("daoxing")/2;


   chance = (int)(random(ap + dp) * 120 / dp);

   if( chance > 20 ) 
   {
        damage=att*40 ;
        message_vision(HIM"耀眼的闪光正正的击中$n，将$n击出丈远，鲜血呖呖撒空而出！\n\n" NOR, me, target);

     me->add("mana",-300);
     me->add("force",-300);
     me->receive_damage("sen",100);
     me->receive_damage("kee",100);
     target->receive_damage("kee",damage);
     target->receive_wound("kee", damage);
     me->start_busy(1+random(2));
     target->start_busy(1);
}
     else if ( chance > 10 ) 
     {
     damage=att*26;
     
     message_vision(HIB"$n被刺眼的闪光包围，瞬间$n感觉身体被抽空般，嘴角渗出一缕血丝...\n\n"NOR, me, target);
        
     me->add("mana",-150);
     me->add("force",-150);
     me->receive_damage("sen",150);
     me->receive_damage("kee",150);
     target->receive_damage("kee",damage);
     target->receive_wound("kee", damage);
     me->start_busy(1+random(2));
     target->start_busy(1);
     } 
   else
     message_vision(HIW"$n垂目静立，恍惚之间，已身在丈外。\n\n"NOR, me, target);
     me->start_busy(2);
     me->add("mana",-100);
     me->add("force",-100);
     me->receive_damage("sen",100);
     me->receive_damage("kee",100);

     return 1;
}
