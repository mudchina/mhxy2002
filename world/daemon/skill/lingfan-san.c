// link 2001.2.16
#include <ansi.h>
inherit SKILL;
string* skill_head =({
        "$N$N使出灵幡九阴中的起手式一招",
        "$N手一抖，一招",
        "$N$N伞柄忽转，手中的$w一招",
        "$N身影晃动，伞锋忽左忽右，一招",
        "$N的双脚点地，伞背贴身，一招",
        "$N伞刃向上，一招",
        "$N手中的$w左右横划，一招",
        "$N使出灵幡九阴中的收手式",
});
string* skill_tail =({
        "，手中的$w划出一溜光芒斩向$n的$l。",
        "，手中的$w幻成一片伞花，散向$n的$l。",
        "，手中$w闪电般劈向$n的$l。",
        "，手中的$w，从中路突然砍至$n的$l。",
        "，全身转出一团伞光滚向$n。",
        "，从一个$n意想不到的角度撩向$n的$l。",
        "，手中的$w左右横划来来回回地狂扫向$n的$l。",
        ", 手中的$w迅捷无比地砍向$n的$l。",
});

mapping *action = ({
        ([      "action":               "$N使出灵幡九阴中的起手式一招"+BLINK""+MAG"「仇恨生天阴」"NOR"，手中的$w划出一溜光芒斩向$n的$l",
                "force":                60,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手一抖，一招"+BLINK""+CYN"「恶毒生地阴」"NOR"手中的$w幻成一片伞花，散向$n的$l",
                "force":                55,
                "damage_type":  "砸伤"
        ]),
        ([      "action":               "$N伞柄忽转，手中的$w一招"+BLINK""+HIR"「怨气生人阴」"NOR"，闪电般劈向$n的$l",
                "force":                60,
                "damage_type":  "砸伤"
        ]),
        ([      "action":               "$N身影晃动，伞锋忽左忽右，一招"+BLINK""+HIY"「反叛生日阴」"NOR"，手中的$w，从中路突然砍至$n的$l",
                "force":                40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N的双脚点地，伞背贴身，一招"+BLINK""+HIB"「遗弃生星阴」"NOR"全身转出一团伞光滚向$n",
                "force":                60,
                "damage_type":  "淤伤"
        ]),
        ([      "action":               "$N伞刃向上，一招"+BLINK""+HIG"「生离生法阴」"NOR"，从一个$n意想不到的角度撩向$n的$l",
                "force":                55,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N手中的$w左右横划，一招"+BLINK""+HIC"「死别生玄阴」"NOR"，来来回回地狂扫向$n的$l",
                "force":                40,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N使出灵幡九阴中的收手式"+BLINK""+HIW"「天劫生气阴」"NOR"，手中的$w迅捷无比地砍向$n的$l",
                "force":                120,
                "damage_type":  "砸伤"
        ]),
});


mapping query_action(object me)
{
    if (random(me->query_skill("umbrella",1)) > 20 &&
        me->query_skill("force",1) > 20 &&
        me->query("force") > 200 ) {
             me->add("force", -20);
             return ([
                  "action": "$N"+BLINK""+RED"「咬破舌尖，口中喷血，吐在伞上」"NOR"，"+BLINK""+WHT"「聚集全身的力量」"NOR"击向$n",
                  "force": 300,
                  "damage_type": "割伤"]);
    }
    return action[random(sizeof(action))];
}


int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 20 )
                return
                notify_fail("你的内功心法火候不足，无法练灵幡魑魅伞 。\n");
        if( (int)me->query_skill("guangming-force", 1) < 20 )
                return
                notify_fail("你的光明心法火候不足，无法练灵幡魑魅伞 。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="umbrella") || (usage=="parry");
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "umbrella" )
                return notify_fail("你必须先找一把伞，才能练伞法。\n");

        if( (int)me->query("kee") < 10 )
                return notify_fail("你的体力不够练这门伞法，还是先休息休息吧。\n");
me->receive_damage("kee", 10);
        write("你按着所学练了一遍灵幡魑魅伞。\n");;
        return 1;
}
int effective_level() { return 50;}

string *parry_msg = ({
        "$n使出灵幡九阴中的真谛"+BLINK""+HIG"「怨恨劫毒离弃悲哀叛」"NOR"，手中的$w化成九重伞幕护住全身。\n",
});

string *unarmed_parry_msg = ({
        "$n使出灵幡九阴中的真谛"+BLINK""+HIG"「怨恨劫毒离弃悲哀叛」"NOR"，手中的$w化成九重伞幕护住全身。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return -5;
}
int black_white_ness()
{
        return 20;
}

string perform_action_file(string action)
{
        return CLASS_D("lingjie") + "/lingfan-san/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int i=random(10);
    if( damage_bonus < 100 ) return 0;
    if (me->query("force")<=200) return 0;
    if(random(me->query_skill("lingfan-san", 1)) > 40
       &&i>7&&me->query_skill("lingfan-san", 1) > victim->query_skill("lingfan-san", 1)
       && (me->query("force") + me->query("con")*30) > victim->query("force")){
       if(victim->query_skill("force")/2 < me->query_skill("force")){
          victim->apply_condition("yun_poison", 2+victim->query_condition("yun_poison"));
        me->add("force",-200);
        message_vision(YEL"$N被转晕了！\n"NOR,victim);}
       else {me->apply_condition("yun_poison", 1+victim->query_condition("yun_poison"));
        me->add("force",-200);
        message_vision(RED"$N害人不成，反而自己被转晕了！\n"NOR,me);}
        }
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("lingfan-san",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对灵幡九阴伞的领悟加深了，你的灵幡九阴伞进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对灵幡九阴伞领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_lingfan-san");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"砸伤"]);

   if(!arg||arg==" ")arg="灵幡九阴必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_lingfan-san",m_actions);
}
