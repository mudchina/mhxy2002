//tianlang-blade.c 【天狼夜魔刀】icejia 2001

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "无",
                "action":
"$N轻抚手中的$w，$w上拢上了一层淡淡的紫气。
一道沁人心骨的寒气已然袭上了$n的$l",
                "dodge":                0,
                "parry":                10,
                 "damage":              35,
                "damage_type":          "割伤"
        ]),
        ([      "name":                 "无",
                "action":
"只见$N右手树握$w，左手食指无名指按住刀脊，一道刀光直冲天际。
在$n发愣只时，$w已经滑到了$n的$l",
                "dodge":                0,
                "parry":                0,
                "damage":                       50,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "无",
                "action":
"$N突然后退一步，刀人和一直冲向$n的$l",
                        "dodge":                        10,
                        "parry":                -15,
                        "damage":                       50,
                        "damage_type":          "劈伤"
        ]),
        ([      "name":                 "无",
                "action":
"$N向前迈出数步。一个翻身，刀从上往下划下。
淡淡紫色的刀光封住了$n的头脸，切断了$n的呼吸",
                        "dodge":                        5,
                        "parry":                10,
                        "damage":                       40,
                        "damage_type":          "割伤"
        ]),
        ([      "name":                 "无",
                "action":
"只见$N一声冷笑，口念佛咒，刀式一缓
$n似乎动作也凝滞了，看着$w劈向自己的$l，却也动弹不得。",
                        "dodge":                        -15,
                        "parry":                0,
                        "damage":                       50,
                        "damage_type":          "劈伤"
        ]),   
        ([      "name":                 "无",
                "action":
"$N刀势突然变快，紫光大胜直冲向$n的$l
$n的心头一紧，粹不及防，愣在那里。",
                "dodge":                        0,
                "parry":                10,
                "damage":                       40,
                        "damage_type":          "刺伤"
        ]),   
        ([      "name":                 "无",
                "action":
"$N心中魔念一闪。向前跨出两步，一刀劈向$n，
虽然是简单的一刀，可怕的刀势却包含了浓重的魔气，$n似乎已经没有退路",
                        "dodge":                        0,
                        "parry":                0,
                        "damage":                       80,
                        "damage_type":          "劈伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力修为不够深，学了也没用。\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能练习刀法。\n");
        return 1;
}

int practice_skill(object me)
{
        int dod=(int)me->query_skill("dodge");
        int swo=(int)me->query_skill("tianlang-blade");

        if (dod<swo/2)
                return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("你体质欠佳，强练夜魔刀有害无益。\n");
        if ((int)me->query("force") < 5)
                return notify_fail("你内力不足，强练夜魔刀有走火入魔的危险。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        message_vision("$N默默回忆了一会儿，然后练了一遍夜魔刀。\n", me);
        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim)
{
        string msg;
        int ap,dp;
        object weapon;

        ap = me->query_skill("blade");
        ap += (me->query_str())*2;
        dp =  victim->query_skill("parry");
        
        weapon = victim->query_temp("weapon");

        if(objectp(weapon) && me->query_skill("blade")>100){ 
        if( random(ap+dp) > dp && random(2)>0){
        if(me->query("force") > random(victim->query("force"))){
                         if(weapon->query("rigidity") >=4 ){  
                               victim->start_busy(2);
                               weapon->move(environment(victim));       
                               victim->receive_damage("kee", ap);  
                               victim->receive_wound("kee", ap/2);      
         msg = MAG"只听“铛”的一声，$n手中的$w已被你挑飞。$n也被你的魔气所伤。\n"NOR ;
                                msg = replace_string(msg, "$w", weapon->name());    
                               }
                        else{
                               victim->start_busy(1);
  msg = MAG"$N念动真言：“噫嘛啦萨！！”只听“啪”的一声响，$n手中$w已被你震成两段。\n"NOR ;
                                msg = replace_string(msg, "$w", weapon->name());
                                weapon->unequip();
                                weapon->move(environment(victim));
                                weapon->set("name", "断掉的"+weapon->query("name"));
                                weapon->set("value", 0);
                                weapon->delete("long");
                                weapon->set("weapon_prop", 0);
                                }
                                }
                   else {       
         msg = HIM"只听“嗡”地一声大响，$n手中的$w在无形霸气的冲击下不住颤抖，险些脱手！\n"NOR ;
                            msg = replace_string(msg, "$w", weapon->name()); 
                                                           }
                }

                return msg; 
    }
}

string perform_action_file(string action)
{
    return CLASS_D("tiankongjie") + "/tianlang-blade/" + action;
}

