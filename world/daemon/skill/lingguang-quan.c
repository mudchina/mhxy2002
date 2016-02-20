//【灵光波动拳】lingguang-quan.c
//create by foc,26-08-01
inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action":
"$N身形一晃，突然转到$n的背后，一团高密度灵气聚集在$N的右手上，闪电般地击向$n的$l",     
        "dodge":    -5,
        "parry":   -10,
        "force":   150,
        "damage" :  10,
        "damage_type":  "严重瘀伤",
        "weapon" :              "右手",
]),
        ([      "action":
"$N向后一跳，同时将灵气大量聚集在左手食指之上，\n"
"周围的空气立刻好象被吸了过去一样。$n感到有点\n"
"不妙，急忙往后连退几步。但几乎同时，$N大喝一声：“"+BLINK""+HIW"灵——弹——！"NOR"”一个发光的巨大能量\n"
"球朝着$n的$l呼地射了过去\n",
        "dodge":    -5,
        "parry":   -30,
        "force":   300,
        "damage" :  50,
        "damage_type":          "射伤",
        "weapon":               "灵弹",
]),
        ([      "action":
"只见$N凌空跃起，双手同时集中大量灵气，发出耀眼的光芒，\n"
"接着手中的灵气突然转化为许许多多的小"+BLINK""+HIW"灵气球"NOR"，$N\n"
"双手一并，无数小"+BLINK""+HIW"灵气球"NOR"漫天花雨般地向$n的全身袭去\n",                "dodge":   -20,
        "parry":    -5,
        "force":    80,
        "damage" :   5,
        "damage_type":          "射伤",
        "weapon":               "灵气球",
]),
        ([      "action":
"$N冷笑一声，突然超快速移动到$n的面前，猛地一头向$n撞过去！\n"
"这一击带着巨大的灵气能量，$n着实吃了一惊",
        "dodge":    10,
        "parry":   -20,
        "force":   130,
        "damage" :   2,
        "damage_type":          "撞伤",
        "weapon":               "头",
]),
        ([      "action":
"只见$N突然往后急推，$n大喝一声：怎么，还想出灵弹？！\n"
"快步追上去，欲做攻击。但$N却将左手放在右手手腕上，\n"
"同时整个身体右侧，全身放出极强的灵气，力量犹如台风\n"
"一般地集中在$N的右手拳头上。$n正在奇怪，突然间，\n"
"$N改退为进，闪身而上，朝着$n直冲过来，右拳一出，\n"
"无数威力巨大的"+BLINK"+"HIW"灵气球"NOR"流星雨般射出，将$n\n"
"的所有退路给封锁了！$n眼看着这一切，不知道该怎么办才好\n",
        "dodge":  -30,
        "parry":  -30,
        "force":  300,
        "damage_type":          "射伤",
        "damage" : 70,
        "weapon":               "大灵气球",
]),
        ([      "action":
"$N朝着$n冲过去，双拳连续出击，每一拳都含着巨大威力的灵气，\n"
"$n身处攻击之下，只觉得危险重重\n",
        "dodge":    0,
        "parry":    5,
        "force":   90,
        "damage_type":          "拳伤",
        "damage" : 10,
        "weapon":               "拳头",
]),
});

int valid_learn(object me)
{
        if(me->query("race")!="人类")
        return notify_fail("这种拳法只能由人类继承。\n");
        if( (int)me->query_skill("spiritforce",1) < (int)me->query_skill("lingguan-quan",1)/2 && (int)me->query_skill("segokee",1)<0)         return notify_fail("你的灵气量太低了，无法继续提高灵光波动拳的修为了。\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("练灵光波动拳必须空手。\n");
        if((int)me->query_skill("unarmed",1)<60 || (int)me->query_skill("force",1)<60)
        return notify_fail("你的基础好象还没打好哦！\n");
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
     if( (int)me->query_skill("spiritforce",1) < (int)me->query_skill("lingguang-quan",1)/2 && (int)me->query_skill("segokee",1)<1)
     return notify_fail("你的灵气不足以适应更高等级的拳法修炼。\n");
     if( (int)me->query("kee") < 50)
     return notify_fail("你的灵气不足了，再练可就要死翘翘了。\n");
     if( (int)me->query("sen") < 50 )
     return notify_fail("你现在的精力不足以控制自己的灵气流动，休息一下再练吧。\n");
     if( (int)me->query("force") < 20 )
     return notify_fail("你的灵力不够了。\n");
     me->receive_damage("kee", 40);
     me->add("force", -10);
     return 1;
}

string perform_action_file(string func)
{
     return CLASS_D("mojie") + "/lingguang-quan/" + func;
}
