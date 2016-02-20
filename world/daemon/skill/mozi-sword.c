// 墨子剑法，mozi-sword.c   created 17-06-2001 海上飘(piao)
//  根据黄易小说《寻秦记》中的项少龙的墨子剑法改编

inherit SKILL;
#include <ansi.h>


mapping *action = ({
   ([
     "action":
"$N不敢怠慢，运起"+BLINK""+CYN"「墨守陈规」"NOR"$w舞得尤如一堵剑墙，$n的攻势亦难以伤$N分毫",
     "dodge":     -15,
     "parry":     10,
     "damage":     200,
     "damage_type":     "内伤",
        "dodge_msg":
"$n的步法短捷快绝,一招"+BLINK""+MAG"「以攻为守」"NOR"错步间竟顺势夺过$N的攻势。\n",
                "dodge_power":          10,
                "parry_msg":
"$n不敢怠慢,运起"+BLINK""+HIY"「墨守成规」"NOR"手中武器舞得尤如一堵剑墙,$N的攻势亦难以伤$n分毫。\n",
                "parry_power":          50,
     ] ),
   ([
     "action":
"$N一招"+BLINK""+GRN"「二墨相连」"NOR"，转身用手中$w档住攻势的同时，瞬间又出一剑刺向$n的$l",
     "dodge":     -5,
     "parry":     -10,
     "damage":     300,
     "damage_type":     "刺伤",
        "dodge_msg":
"$n的步法短捷快绝,一招"+BLINK""+WHT"「攻守兼备」"NOR"错步间竟顺势夺过$N的攻势。\n",
                "dodge_power":          50,
                "parry_msg":
"$n不敢怠慢,运起"+BLINK""+HIY"「墨守成规」"NOR"手中武器舞得尤如一堵剑墙,$N的攻势亦难以伤$n分毫。\n",
                "parry_power":          50,
   ] ),
   ([
     "action":
"只见$N大喝一声，一招"+BLINK""+RED"「血墨夺腾」"NOR"，纵身飞起，手中$w幻出无数剑影犹如火龙冲天攻向$n",
     "dodge":     -5,
     "parry":     -5,
     "damage":     500,
     "damage_type":     "震伤",
        "dodge_msg":
"$n的步法短捷快绝,一招"+BLINK""+MAG"「以攻为守」"NOR"错步间竟顺势夺过$N的攻势。\n",
                "dodge_power":          10,
                "parry_msg":
"$n不敢怠慢,运起"+BLINK""+HIY"「墨守成规」"NOR"手中武器舞得尤如一堵剑墙,$N的攻势亦难以伤$n分毫。\n",
                "parry_power":          50,

   ] ),
   ([
     "action":
"正在久攻不下之际，$N剑势聚变，随着扭动身体，$w剑招从不可能的角度狂砍而出",
     "dodge":     -15,
     "parry":     5,
     "damage":     200,
     "damage_type":     "砍伤",
        "dodge_msg":
"$n的步法短捷快绝,一招"+BLINK""+BLU"「以守代攻」"NOR"错步间竟顺势夺过$N的攻势。\n",
                "dodge_power":          80,
                "parry_msg":
"$n不敢怠慢,运起"+BLINK""+HIY"「墨守成规」"NOR"手中武器舞得尤如一堵剑墙,$N的攻势亦难以伤$n分毫。\n",
                "parry_power":          50,

   ] ),
   ([
     "action":
"激战中，不知$N的身形如何走动，只见$w左穿右插，剑光一刻间竟向$n连出六招",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "割伤",
        "dodge_msg":
"$n的步法短捷快绝,一招"+BLINK""+BLU"「以守代攻」"NOR"错步间竟顺势夺过$N的攻势。\n",
                "dodge_power":          80,
                "parry_msg":
"$n不敢怠慢,运起"+BLINK""+HIY"「墨守成规」"NOR"手中武器舞得尤如一堵剑墙,$N的攻势亦难以伤$n分毫。\n",
                "parry_power":          50,

   ] ),
     ([
     "action":
"蓦地$N加速逼至，$w幻出大片剑影时，突然现出剑体,闪电横削$n的$l而来,凌厉无比",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "割伤",
        "dodge_msg":
"$n的步法深含某种奥秘，令$N很难把握逼近的速度和时间。\n",
                "dodge_power":          80,
                "parry_msg":
"$n丝毫不惧，略摆$W的角度，挡住了$N的进攻。\n",
                "parry_power":          50,

   ] ),
   ([
     "action":
"$N双目掠过寒芒，显然是动了杀气，舌绽春雷，大喝一声，荡开$w往$n$l处一剑劈下",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "劈伤",
        "dodge_msg":
"$n错身开去，划出一道剑芒，外圈处刚好迎上$N的这一招。\n",
                "dodge_power":          80,
                "parry_msg":
"$n错身开去，划出一道剑芒，外圈处刚好迎上$N的这一招。\n",
                "parry_power":          50,

   ] ),
   ([
     "action":
"$N不再犹豫，如影附形地往$n逼去，同时由单手改为双手握$w，高举过头,
随着似蹈敌之虚的步法，当头疾往$n劈去",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "劈伤",
        "dodge_msg":
"$n的步法短捷快绝，一招"+BLINK""+BLU"「以守代攻」"NOR"错步间竟顺势夺过$N的攻势。\n",
                "dodge_power":          80,
                "parry_msg":
"$n$w上下翻飞，寒芒电射，堪堪挡住了$N的攻势。\n",
                "parry_power":          50,

   ] ),


});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 150 )
     return notify_fail("你的内力修为不够深，无法学墨子剑法。\n");

   if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") == "axe" 
           || (string)ob->query("skill_type") == "spear" 
           || (string)ob->query("skill_type") == "fork" 
           || (string)ob->query("skill_type") == "qin" 
           || (string)ob->query("skill_type") == "mace" 
           || (string)ob->query("skill_type") == "dagger" 
           || (string)ob->query("skill_type") == "hammer" 
           || (string)ob->query("skill_type") == "staff" 
           || (string)ob->query("skill_type") == "stick" 
           || (string)ob->query("skill_type") == "whip" 
           || (string)ob->query("skill_type") == "rake" 
           || (string)ob->query("skill_type") == "throwing" 
           || (string)ob->query("skill_type") == "archery" )
      return notify_fail("你必须先找一把武器才能练习墨子剑法。\n");

   return 1;
}


int valid_enable(string usage)
{
   return usage=="sword"||usage=="parry"||usage=="blade"||usage=="dodge";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
        return action[random(sizeof(action))]["parry_msg"];
}
string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["dodge_msg"];
}

int practice_skill(object me)
{
   int dod=(int)me->query_skill("dodge");
   int swo=(int)me->query_skill("mozi-sword");

   if (dod<swo/2)
     return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
   if ((int)me->query("kee") < 30)
     return notify_fail("你体质欠佳，强练墨子剑法有害无益。\n");
   if ((int)me->query("force") < 30)
     return notify_fail("你内力不足，强练墨子剑法有走火入魔的危险。\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
   message_vision("$N默默回忆了一会儿，然后练了一遍墨子剑法。\n", me);
   return 1;
}

string perform_action_file(string func)
{
return CLASS_D("youxia") + "/mozi-sword/" + func;
}


