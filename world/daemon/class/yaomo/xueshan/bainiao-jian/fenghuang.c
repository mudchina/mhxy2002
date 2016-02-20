//write by swagger
//描述策划 by skyer
//2002/2/20
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg , str;
int extra;
 object weapon;
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
  return notify_fail("凤凰之舞只能对战斗中的对手使用。\n");
 if(me->query("family/family_name")!="大雪山")
 return notify_fail("“凤凰之舞”只有雪山本门中人才可以用！\n");
      if (me->query_skill("bainiao-jian",1)<100) 
          return notify_fail("你的百鸟剑法那么烂，舞给谁看？\n");
      if (me->query_skill("xiaoyaoyou",1)<100) 
          return notify_fail("你的逍遥游那么烂，舞给谁看？\n");
        if( me->query("force_factor") > 50)                return notify_fail("「凤凰之舞」绝技重招不重力。加力出招怎能剑走轻灵？\n");
weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "sword" )
 return notify_fail("你手上无剑，不能使用凤凰之舞！\n");
 if( (int)me->query("force") <= 1500 )
 return notify_fail("你内力不够，不能使用凤凰之舞！\n");
 {
 extra = me->query_skill("bainiao-jian",1) ;
 msg = HIW  "\n$N神色黯然，随之身形疾转，如冰天雪地中之凤凰独舞！\n风起，愁心起！风息，愁心却无处归依！！\n" NOR;
        message_vision(msg, me, target);
//   if( random((int)me->query_skill("xiaoyaoyou")*4) > (int)target->query_skill("dodge"))
{
msg = WHT"\n$n不觉神情呆滞，似乎勾起无限心伤!\n\n" NOR;
message_vision(msg, me ,target);
target->start_busy(random(1));
 me->add_temp("apply/attack", extra);
 me->add_temp("apply/damage", extra);
 msg =  HIC "$N弹剑轻吟，身形闪动间，连续向$n攻出三剑！\n" NOR;
        message_vision(msg, me, target);
msg = HIB  "\n   >>>>$N刺出一剑！剑光如    "HIC""BLINK"水银泻地"NOR"" NOR;
       message_vision(msg, me, target);
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
msg = HIB  "   >>>>$N刺出一剑！剑光如    "HIC""BLINK"星雨银河"NOR"" NOR;
       message_vision(msg, me, target);
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
msg = HIB  "   >>>>$N刺出一剑！剑光如    "HIC""BLINK"逐月流星"NOR"" NOR;
       message_vision(msg, me, target);
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
       me->set("fenghuang", 12);
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       me->set("fenghuang", 13);
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 me->add_temp("apply/attack", -extra);
 me->add_temp("apply/damage", -extra);
 me->start_busy(random(3));
 me->add("force", -200);
 if (target->query("eff_kee")<0 || !living(target) )  
{str="听说"+target->name()+HIM"被"+me->name()+HIM"用一式"HIY"凤凰独舞"HIM"送去了阎罗地府！据说"+target->name()+HIM"到了阎罗地府还在跳着舞！\n"NOR;
 message("channel:rumor",HIM"\n【谣言】某人："+str+"\n"NOR,users());
}
else {
msg = YEL"\n$n冷冷的看着$N笨拙的舞动，不禁露出嘲弄的笑容。\n" NOR;
message_vision(msg, me ,target);
 me->start_busy(2);
 me->add("force", -200);
 me->add("kee", -20);
}
}
 me->delete("fenghuang");
 me->set_temp("fenghuang_busy",1);
 call_out("remove_effect",3+random(8),me);
 return 1;
}
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("fenghuang_busy");
}
