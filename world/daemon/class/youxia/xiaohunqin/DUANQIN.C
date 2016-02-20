
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void duanqin_ok(object);

int perform(object me, object target)
{
    mapping duanqin= ([
       "damage": 1000,
       "dodge" : -30,
       "parry" : -30,
       "damage_type" :  "内伤",
       "action" :  HIM"$w"+HIM"在空中飞转了一阵,突然向$n"HIM"的$l飞去"NOR,
    ]);

      object weapon=me->query_temp("weapon");
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if (me->query_temp("no_duanqin") )
          return notify_fail("你现在状态不佳，不能使用飞琴。\n");      
      if (me->query_skill("wuji-force",1)<50)
          return notify_fail("你的内功太差，琴飞不出去。\n");
      if (me->query_skill("xiaohunqin",1)<50) 
          return notify_fail("你的销魂琴那么烂，当心把琴插自己身上。\n");
      if (me->query("force")<100)
           return notify_fail("你内力不继，难以驾御飞琴。\n");
     
      me->add("force", -100);
          me->start_busy(2);
      me->set("actions",duanqin);
       message_vision(HIM"$N手中"+weapon->query("name")+HIM"在空中飞转了一阵,突然向$n"HIM"的飞去！"NOR,me,target);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                weapon->unequip();
                weapon->move(environment(target));
                weapon->set("name","断成两截的"+weapon->query("name"));
                weapon->set("no_get",1);
                weapon->set("long","一件断成两截的"+weapon->query("name"));
      me->set_temp("no_duanqin",1);
      call_out("duanqin_ok",10,me);
      me->reset_action();
      return 1;
}

void duanqin_ok(object me) {
      if (!me) return;
      me->delete_temp("no_duanqin");
}         

