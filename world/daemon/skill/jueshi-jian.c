//BY tianlin@mhxy for 2001.10.7
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N身形稍退，使出一招",
        "$N仰天长笑，看也不看，一招",
        "$N轻轻一跃，使了个",
        "$N神态悠闲，一招",
        "$N身形转个不停，突然一招",
        "$N脚下踏了个八字步，一招",
});

string* skill_tail =({
        "，手中$w势若飞瀑向$n拦腰一斩",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑刺去",
        "，手中$w轻妙地划向$n的$l",
        "，反手对准$n$l一剑刺去",
        "，趁$n转身之际，挥出一剑",
});



mapping *action = ({
   ([   "action":     "$N使出一招"+HIR"【"NOR+BLINK+WHT"拿人式"NOR+HIR"】"NOR+"，剑光闪烁不定，若有若无地刺向$n$l",
     "dodge":     0,
     "parry":     15,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N身形转个不停，突然一招"+HIR"【"NOR+BLINK+YEL"山动地摇"NOR+HIR"】"NOR+"使出，手中$w划出一道银弧，径刺$n$l",
     "dodge":     -10,
     "parry":     15,
     "damage":     45,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N脚下踏了个八字步，一招"+HIR"【"NOR+BLINK+CYN"来去无影"NOR+HIR"】"NOR+"手中$w势若飞瀑向$n拦腰一斩",
     "dodge":     -5,
     "parry":     15,
     "damage":     40,
     "damage_type":   "劈伤"
   ]),
   ([   "action":     "但见$N连退几步，忽然间纵身跃起，手中$w一式"+HIR"【"NOR+BLINK+HIG"平中式"NOR+HIR"】"NOR+"对准$n的$l凌空一斩",
     "dodge":     -15,
     "parry":     5,
     "damage":     50,
     "damage_type":   "劈伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
     return notify_fail(CYN"你的内力不够，没有办法练绝世剑法。\n"NOR);

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail(RED"你必须先找一把剑才能练剑法。\n"NOR);

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_jueshi-jian");
     if(me->query("skill_jueshi-jian")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(sizeof(action))];

}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习绝世剑法。\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   write(YEL"你按着所学练了一遍"NOR+HIC"绝世剑法"NOR+YEL"。\n"NOR);
   return 1;
}
string perform_action_file( string action)
{
return CLASS_D("shenjian") + "/jueshi-jian/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("jueshi-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对绝世剑的领悟加深了，你的绝世剑进入了一个新的境界！\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对绝世剑领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_jueshi-jian");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);

   if(!arg||arg==" ")arg="绝世剑法必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HBRED+WHT"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_jueshi-jian",m_actions);
}
 
