
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void feijian_ok(object);
void postfeijian(object,object,object,int);

int perform(object me, object target)
{
    mapping feijian= ([
       "damage": 100,
       "dodge" : -10,
       "parry" : -10,
       "damage_type" : "刺伤",
       "action" :  HIY"\n$w"+HIY"在空中一闪，毒蛇般向$n的$l刺去\n",
       "post_action" : (: postfeijian :)
    ]);

      object weapon=me->query_temp("weapon");
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if (me->query_temp("no_feijian") )
          return notify_fail("你现在状态不佳，不能使用飞叉。\n");      
      if (me->query_skill("zhuanlong-force",1)<100)
          return notify_fail("你的内功太差，叉飞出去肯定飞不回来。\n");
      if (me->query_skill("yueya-fork",1)<100) 
          return notify_fail("你的叉法那么烂，当心把插自己身上。\n");
      if (me->query("force")<100)
           return notify_fail("你内力不继，难以驾御飞叉。\n");
     
      me->add("force", -100);
      me->set("actions",feijian);
    message_vision(HIC"\n$N突然清啸一声，掌中"+weapon->query("name")+HIW"脱手而出，直向$n飞去！\n"NOR,me,target);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      me->set_temp("no_feijian",1);
      call_out("feijian_ok",2+random(2),me);
      me->reset_action();
      return 1;
}

void feijian_ok(object me) {
      if (!me) return;
      me->delete_temp("no_feijian");
}         

void postfeijian(object me,object victim,object weapon, int damage) {
      if (damage>0 || damage==RESULT_DODGE)
         message_vision(HIC"$N用劲一带，"+weapon->query("name")+HIW"在空中打了个转，又回到手中。\n"NOR,me);
}
