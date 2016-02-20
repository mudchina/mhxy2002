// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//sixiang.c 【四象阵】
#include <ansi.h>

inherit SSERVER;

void npc_attack(object invoker, object target, string npc, object where);

int cast(object me, object target)
{
   string msg;
   string npc_dir = "/d/xuyi/npc/";
   object where;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("你想摆阵拿谁？\n");

   if((string)me->query("family/family_name") != "盱眙山" )
     return notify_fail("你又不是盱眙山弟子，请不动四大神将。\n");

   if((string)target->query("family/family_name") == "盱眙山" )
     return notify_fail("同门相斗也要请四大神将？\n");

   if((int)me->query_skill("fumozhou", 1) < 20)
         return notify_fail("你的伏魔咒修为不深，摆不出四象阵。\n");
   
   if((int)me->query("mana") < 200 )
     return notify_fail("你的法力不够，没办法摆四象阵。\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("你现在神智不清，逃跑好过摆阵！\n");

   me->add("mana", -200);
   me->receive_damage("sen", 10);

   if( random(me->query("max_mana")) < 50 ) 
   {
     write("咦？这一次好像不灵。\n");
     return 1;
   }

   msg = HIC "$N大喝一声：四神将，结阵！\n"+
          "风云骤起，四大神将从云中走了出来，按地、水、火、风四个方位结成阵势！\n"+"将$n团团围住！\n\n" NOR;   
   message_vision(msg, me, target);
   msg = "$n对着$N高声骂道：你敢结阵困我，我宰了你！\n" NOR;   
   message_vision(msg, me, target);
   target->kill_ob(me);
   
   where=environment(target);
   call_out("npc_attack", 2, me, target, npc_dir+"zhao", where);
   call_out("npc_attack", 3, me, target, npc_dir+"qian", where);
   call_out("npc_attack", 5, me, target, npc_dir+"sun", where);
   call_out("npc_attack", 6, me, target, npc_dir+"wang", where);
   me->start_busy(2+random(2));
   return 3+random(10);
}

void npc_attack(object invoker, object target, string npc, object where)
{
   object attacker;

        if(!invoker || !target) return;

   if( environment(invoker) != environment(target) ) return;
   if( environment(target) != where) return;

   seteuid(getuid());
   attacker = new(npc);
   attacker->move(environment(invoker));

   COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));
   
   // give the killing credit to the invoker.
   // so this would be counted as PK if the invoker is user.
   // mon 4/11/98
   if(target->query_temp("last_damage_from")==attacker)
       target->set_temp("last_damage_from", invoker);
   
   if(target->query_temp("last_fainted_from")==attacker)
       target->set_temp("last_fainted_from", invoker->query("id"));

   destruct(attacker);
}


