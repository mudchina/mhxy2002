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
                return notify_fail("你要对谁施展这一招「龙枪百裂」？\n");

        if(!me->is_fighting())
                return notify_fail("「龙枪百裂」只能在战斗中使用！\n");

	      if((string)me->query("family/family_name") != "将军府" )
		return notify_fail("使用龙枪百裂需要驰骋沙场的胆气，现在的你哪里使的出来。\n");
        if((int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够！\n");

     if((int)me->query("force") < 350 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 150 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("bawang-qiang", 1) < 50)
                return notify_fail("你的霸王枪级别还不够，使用这一招会有困难！\n");

message_vision(HIW"\n$N一抖手中长枪，幻出满天枪影，犹如无数飞龙般向$n击去！\n"NOR, me, target);
 me->start_busy(1+random(2));

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

        message_vision(HIR"$N躲闪不及，被打个正着！\n"NOR, target);
   target->receive_damage("kee", 50 + random((int)me->query("max_force")/40+(int)me->query("force_factor")));
        COMBAT_D->report_status(target);
        if (y=1) {
//       if(target->query_temp("armor")||target->query_temp("weapon")) {
                if (target->query_temp("weapon")) {
                obj=target->query_temp("weapon");
                obj->unequip();
                obj->set("value", 0);
                message_vision(HIW "只听见「啪」地一声，$N手中的" + obj->name()+ "已被一招击的粉碎！\n" NOR, target);
                obj->set("name", "碎裂的" + obj->query("name"));
                obj->set("weapon_prop", 0);
                obj->set("armor_prop", 0);
                obj->move(environment(target));
                call_out("remove_broken_cloth",random(300)+60,obj);}
                }
        return 1+random(5);
           }
     else {
        message_vision(HIC"却被$N躲开了！\n"NOR, target);

       me->add("force", -200);
     me->receive_damage("sen", 100);

        target->kill_ob(me);

 me->start_busy(2+random(2));
        return 1+random(5);
}
}

void remove_broken_cloth(object obj)
{
  if(obj && environment(obj)) {
    tell_object(environment(obj),
      "一阵微风吹过，"+obj->name()+"化为片片尘土，消失不见了。\n");
    destruct(obj);
  }
}
