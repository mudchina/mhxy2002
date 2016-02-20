//邪王炎杀拳，evilfight.c
//created by foc, 10-6-01,in bjmc

inherit SKILL;

#include <ansi.h>

mapping *action = ({
([ "action":  
"$N略一运力，右手立刻燃起"+BLINK""+HIR"红色的火焰"NOR"，$N右拳紧握，向前\n一击，炙热的火焰如同狂风般向$n卷去。",
"dodge":  -40,
"parry": -30,
"force": 230,
  "damage_type": "烧伤",
]),
 ([ "action":  
"$N力灌双手，"+BLINK""+HIR"黑色的火焰"NOR"立刻燃烧起来。$N将双手一并，\n再往前一推，两道火焰呼地合成一个巨大的龙卷旋涡，气势凌厉\n地朝着$n卷去。",
"dodge":  -20,
"parry": -50,
"force": 280,
 "damage_type": "火焰卷伤",
]),
([ "action":  
"$N头上的"+BLINK""+HIC"邪眼"NOR"突然光芒大盛，浑身燃起\n"+BLINK""+HIR"赤黑色的火焰"NOR"，周围的空气好象被$N吸过去一般！\n突然$N大喝一声，身形已经来到$n的面前，左右手轮番击出。\n在这短短的六秒内已经击出了"+BLINK""+HIY"三百二十七拳"NOR"！",
"dodge":  -80,
"parry":  -30,
"force":  654,
"damage_type": "拳伤",
]),
([ "action":  
"$N身形一晃，变成了两个$N。$n大吃一惊，急忙攻击前面那个，没想\n到却是个假的。而这时，$N已经来到了$n的身后，一个旋身，左\n脚斩向$n的头部，接着右拳一运力，带着"+BLINK""+HIC"青绿色火焰"NOR"击向$n的后腰！",
"dodge":  -30,
"parry":  -40,
"force":  310,
"damage_type": "伤害",
]),
([
"action" : 
"$N跃至半空，头上"+BLINK""+HIC"邪眼"NOR"发出奇特的光芒。$N一个倒翻，来\n到了$n的上空，接着左脚连续踢出了二十踢，然后左脚一收，右\n脚带着雷霆万钧之势攻向$n的胸口！",
"dodge"  : -70,
"parry"  : -5,
"force"  : 350,
"damage_type" : "伤害",
]),
([
"action" : 
"$N头上的"+BLINK""+HIC"邪眼"NOR"再度张开，接着浑身燃起黑色的炙热\n斗气。$N大喝一声，凭空频频击出右拳，斗气结合着火焰的气流\n团立刻像流星一样射向$n！",
"dodge"  : -20,
"parry"  :  15,
"force"  : 260,
"damage_type" : "烧伤",
]),
});

int valid_learn(object me)
{    
     if( (int)me->query_skill("evilfight", 1) > 300 )
     return notify_fail("这种拳法你已经修炼到极限了，再怎么学习也没办法进步。\n");
     if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
     return notify_fail("练邪王炎杀拳最好空手，不然烧坏了东西怎么办？\n");
     if( (int)me->query_skill("evileye", 1) < 60 )
     return notify_fail("学习邪王炎杀拳必须能很好地控制邪眼的力量，把基础打好了再来吧！\n");
     if( (int)me->query("max_kee") < 399 )
     return notify_fail("以你现在的体力，恐怕受不了邪王炎杀拳修炼的痛苦。\n");
     if( (int)me->query("max_sen") < 399 )
     return notify_fail("以你现在的精力要修炼邪王炎杀拳简直是找死，爱惜生命吧！\n");
     if( (int)me->query("combat_exp") < 200000 )
     return notify_fail("你对战斗的领悟太少，没办法练习邪王炎杀拳。\n");
     if( (int)me->query("daoxing") < 200000 )
     return notify_fail("你的修为不足以应付这种拳法的修炼。\n");
     if( (int)me->query_skill("unarmed",1) < (int)me->query_skill("evilfight", 1) || (int)me->query_skill("evileye", 1) < (int)me->query_skill("evilfight", 1) )
{
   message_vision(HIR"$N头上的邪眼突然放出奇怪的光，接着$N的右手燃烧起来，$N不由地惨叫了一声！\n"NOR,me);
   me->receive_damage("kee", 500 - (int)me->query_skill("unarmed", 1) );
   me->receive_damage("sen", 100 );
   write ("看起来，你的基础没打好。\n");
}

   return 1;
}

int valid_enable(string usage)
{
 return usage=="unarmed"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
     return action[random(sizeof(action))];
}

int practice_skill(object me)
{  
   if( (int)me->query_skill("evilfight", 1) > 300 )
   return notify_fail("这种拳法你已经修炼到极限了，再怎么练习也不会进步了。\n");
   if( (int)me->query_skill("evileye", 1 ) < 70 )
   return notify_fail("不行，以你现在的邪眼术修为，不能独自开始练习。\n");
   if( (int)me->query_skill("unarmed", 1 ) < 70 )
   return notify_fail("拳法的基础都没打好，怎么练？\n");
   if( (int)me->query("max_kee") < 350 )
   return notify_fail("以你现在的体力，恐怕受不了邪王炎杀拳修炼的痛苦。\n");
   if( (int)me->query("max_sen") < 350 )
   return notify_fail("以你现在的精力要修炼邪王炎杀拳简直是找死，爱惜生命吧！\n");
   if( (int)me->query("combat_exp") < 200000 )
   return notify_fail("你对战斗的领悟太少，没办法练习邪王炎杀拳。\n");
   if( (int)me->query("daoxing") < 200000 )
   return notify_fail("你的修为不足以应付这种拳法的修炼。\n");
   if( (int)me->query_skill("unarmed",1) < (int)me->query_skill("evilfight", 1) || (int)me->query_skill("evileye", 1) < (int)me->query_skill("evilfight", 1) )
{
   message_vision(HIR"$N头上的邪眼突然放出奇怪的光，接着$N的右手燃烧起来，$N不由地惨叫了一声！\n"NOR);
   me->receive_damage("kee", 500 - (int)me->query_skill("unarmed", 1) );
   me->receive_damage("sen", 100 );
   write ("看起来，你的基础没打好。\n");
}
   if( (int)me->query("sen") < 100)
   return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
   if( (int)me->query("kee") < 100 )
   return notify_fail("你现在体力不够了，休息一下再练吧。\n");
   if( (int)me->query("force") < 50 )
   return notify_fail("你的妖气不够了。\n");
   me->receive_damage("sen", 60);
   me->add("force", -20);
   
   return 1;
}

string perform_action_file(string func)
{
return CLASS_D("mojie") + "/evilfight/" + func;
}

void skill_improved(object me)
{
   tell_object (me, "哇，你好厉害呀，帅呀！\n");
}
