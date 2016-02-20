//妖剑术 
//created by foc,9-6-01

inherit SKILL;

#include <ansi.h>

mapping *action = ({
        ([      "name":          "迎风一断",
                "action":
"$N右脚在地上一点，身形朝着$n电射过去，同时右手拔剑朝着$n一挥。\n这一斩带着凌厉的杀气，$n不由的一惊！这招"+BLINK""+HIR"「迎风一断」"NOR+"果然厉害。",
                "dodge":   -25,
                "parry":   -5,
                "damage":   225,
                "damage_type":  "斩伤"
        ]),
        ([      "name":          "影杀", 
                "action":
"$N按着剑朝着$n冲去，使出妖剑术的"+BLINK""+HIG"「影杀」"NOR+"身影立刻变成了两个，\n一个出现在$n的背后，另一个出现在$n的面前。\n$n正在奇怪，两个身影已经同时挥剑向$n的$l斩下！",

                "dodge":     -25,
                "parry":     -30,
                "damage":     190,
                "damage_type":  "剑伤"
        ]),
        ([      "name":                 "真·两面断",
                "action":
"$N双脚加速，飞快地朝着$n冲去。在与$n错身而过的瞬间，$N突然\n拔剑一挥，一道凌厉的"+BLINK""+HIC"剑光"NOR+"立刻袭向$n的腰间！这正是妖\n剑术中的"+BLINK""+HIY"「真·两面断」"NOR+"！",
                "dodge":   -30,
                "parry":   -10,
                "damage":   230,
                "damage_type":  "斩伤"
        ]),
        ([      "name":                 "残像斩",
                "action":
"$N一声冷笑，不快不慢冲到$n的面前，$n正要运力攻击眼前的$N，\n但真正的$N却已经站在了$n的肩膀上，运力将剑向$n的头部刺下！原来$N使\n的是"+BLINK""+HIB"「残像斩」"NOR+"。",
                "dodge":   -10,
                "parry":    15,
                "damage":   200,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "二十六影断",
                "action":
"$N的全身突然放出强烈的妖气，接着跃至$n的斜上方，大喝一声，\n化作二十六个影子，每个影子都向$n挥出一剑。只见"+BLINK""+HIC"二十六道剑光"NOR+"\n向$n全身上下的要害飞射而去！这招"+BLINK""+HIW"「二十六影断」"NOR+"将$n的退路全封住了。",
                "dodge":     -35,
                "parry":     -25,
                "damage":     185,
                "damage_type":  "剑伤"
        ]),   
        ([      "name":                 "邪眼冥封杀",
                "action":
"$N使出"+BLINK""+HIM"「邪眼冥封杀」"NOR+"，双目一闭，额头上出现又一只"+BLINK""+HIC"眼睛"NOR+"！\n$n正在奇怪，那"+BLINK""+HIC"眼睛"NOR+"一张，一股诡异的力量放射出来，\n$n感到自己的行动突然一慢。与此同时，$N手中的$w自动朝着$n飞射而去！",
                "dodge":   -25,
                "parry":   -5,
                "damage":    220,
                "damage_type":  "刺伤"
        ]),   
        ([      "name":                 "奥义·冥狱炎杀剑",
                "action":
"$N头上的邪眼张开，浑身燃起"+BLINK""+HIC"黑色的火焰"NOR+"，\n同时手中$w也燃起同样的"+BLINK""+HIC"烈焰"NOR+"。$N大喝一声，将剑一抛，\n身形朝着$n电射过来。$N先是连续向$n攻出了数\n拳，接着右手一举，刚好接到$w，$N双手握剑，大力由右上\n向左下一斩。这一斩带着锐利的火焰，要是被斩中，可就完了。这正是\n传说中妖剑术的最大秘密"+BLINK""+HIR"「奥义·冥狱炎杀剑」"NOR+"！",
                "dodge":   -40,
                "parry":   -40,
                "damage":   450,
                "force":    300,
                "damage_type":  "致命伤"
        ]),
   ([   "name":        "实战连击",
     "action":   "$N运力向$n连续挥剑，无数的"+BLINK""+HIC"剑光"NOR+"带着锐利的剑气像一张大网一样罩向$n全身要害！",
     "parry":   -15,
     "dodge":   -20,
     "damage":   180,
     "damage_type":  "剑伤"
   ]),
});


int valid_learn(object me)
{
     object ob;
     if((int)me->query_skill("evileye", 1) < (int)me->query_skill("evilsword",1)/2)
     return notify_fail("你的邪眼术修为不够了，不能再提高妖剑术的等级了。\n"); 
     if( (string)me->query_skill_mapped("force")!= "evileye")
     return notify_fail("妖剑术必须配合邪眼术才能练。\n");
     if( (int)me->query("max_force") < 450 )
     return notify_fail("你的妖气不够，没有办法练妖剑术，提高了自己的妖气再说吧。\n");

     if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )       
     return notify_fail("你必须先找一把剑才能练这种剑术。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="parry"||usage=="sword";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_effect(object me, object weapon, string action_name, int skill)
{
          return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 200
        ||      (int)me->query("force") < 100 )
                return notify_fail("你的体力或妖气不够，没有办法练习妖剑术。\n");
        me->receive_damage("kee", 60);
        me->add("force", -20);
        write("你按着所学练了一遍妖剑术。\n");
        return 1;
}

string perform_action_file(string func)
{
        return CLASS_D("mojie") + "/evilsword/" + func;
}
