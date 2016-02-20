//佛光谱照 by yushu 2001.2
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object *inv, obj;
        object weapon;
        int i,y, mypot,tapot,mystr,tastr,myexp,taexp,mylvl,talvl;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「佛光谱照」？\n");


        if(!me->is_fighting())
                return notify_fail("「佛光谱照」只能在战斗中使用！\n");

        if((string)me->query("family/family_name") != "南海普陀山" )
                return notify_fail("你还没有四大皆空、超脱世俗怎能佛光普照？\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

       if((int)me->query_skill("lunhui-zhang", 1) < 150)
                return notify_fail("你的轮回杖级别还不够，使用这一招会有困难！\n");

message_vision(HIY"\n$N口中念动《金刚经》：\n"NOR,me,target);
message_vision(HIY"\n生死炽燃，苦恼无量，发大乘心，普济一切。\n"NOR,me,target);
message_vision(HIY"\n愿代众生，受无量苦，令诸众生，毕竟大乐。\n"NOR,me,target);
message_vision(HIW"\n高举手中的"+weapon->query("name")+HIW"砸向$n。\n"NOR,me,target);
         me->start_busy(2);
         mystr=(int)me->query("str");
         tastr=(int)target->query("str");
         myexp=(int)me->query("combat_exp")/20;
         taexp=(int)target->query("combat_exp")/30;
         mylvl=(int)me->query_skill("staff")*(int)me->query_skill("lunhui-zhang");
         talvl=(int)target->query_skill("parry")*(int)target->query_skill("dodge");
         mypot=mystr*mylvl+myexp;
         tapot=tastr*talvl+taexp;
         y=random(3);
         if( random(mypot) >random(tapot)) {
          message_vision(HIR"$N躲闪不及，被打个正着！\n"NOR, target);
          target->receive_damage("kee", 60 + random((int)me->query("max_force")/40+(int)me->query("force_factor")));
          target->receive_damage("sen", 60 + random((int)me->query("max_mana")/40+(int)me->query("mana_factor")));
          COMBAT_D->report_status(target);
          COMBAT_D->report_sen_status(target);
          if (y=1) {
                if (target->query_temp("weapon")) {
                obj=target->query_temp("weapon");
                obj->unequip();
                obj->set("value", 0);
                message_vision(HIW "只听见「啪」地一声，$N手中的" + obj->name()+HIW"已被一招击的粉碎！\n" NOR, target);
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
