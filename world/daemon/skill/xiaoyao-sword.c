// 逍遥拜让风回剑，xiaoyao-sword.c
// icejia
// 起剑式 落剑式 浪剑式 挫剑式 荡剑式 转剑式
#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "name":                 "起剑式",
                "action":
"起剑式！\n"
"$N轻身后翻，倒身而起手中$w点地，随后纵身飘向$n,$w点向$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":               30,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "落剑式",
"落剑式！\n"            "action":
"$N双脚顿地跃入空中，倒落而下。急颤手中$w\n"
"剑尖却始终不离一点，流星一般飞向$n,攻到了$n的$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":               50,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "浪剑式",
                "action":
"浪剑式！\n"
"$N横走两步侧翻横滚，手中$w绕身旋转。\n"
"突的反身回卷袭向$n，手中$w分向$n的$l",
                "dodge":                30,
                "parry":                20,
                "damage":               30,
                "damage_type":          "割伤"
        ]),
        ([      "name":                 "挫剑式",
                "action":
"挫剑式！\n"
"$N在$n四周游走，待$n刚想出招，"
"$N手中$w让开$n的攻势，逆行而上刺向$n的$l",
                "dodge":                -5,
                "parry":                30,
                "damage":               35,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "荡剑式",
                "action":
"荡剑式！\n"
"$N原地一个大回转，手中$w荡到$n的$l",
                "dodge":                0,
                "parry":                0,
                "damage":               50,
                "damage_type":          "震伤"
        ]),
        ([      "name":                 "转剑式",
                "action":
"转剑式！\n"

"$N展开身形，$w之攻势绵绵不绝地缠向$n的$l。"
"转剑式，果然有风回路转的奇功。",
                "dodge":                10,
                "parry":                10,
                "damage":               40,
                "damage_type":          "割伤"
        ]),
        ([      "name":                 "凝剑式",
                "action":
"起剑式！\n"
"$N抱剑而立，$n只觉$N的身影迅速移动，可是$N手中的$w凝重点向$n的$l,$n似乎已经无从避闪。",
                "dodge":                40,
                "parry":                40,
                "damage":               40,
                "damage_type":          "刺伤"
        ]),
        
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力修为不够深，学了也没用。\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一柄剑才能练习剑法。\n");
        return 1;
}

int practice_skill(object me)
{
        int dod=(int)me->query_skill("dodge");
        int swo=(int)me->query_skill("xiaoyao-sword");

        if (dod<swo/2)
                return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("你体质欠佳，强练逍遥剑法有害无益。\n");
        if ((int)me->query("force") < 5)
                return notify_fail("你内力不足，强练逍遥剑法有走火入魔的危险。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        message_vision("$N默默回忆了一会儿，然后练了一遍逍遥剑法。\n", me);
        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword"||usage=="parry";
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

        ap = me->query_skill("sword");
        ap += (me->query_str())*2;
        dp =  victim->query_skill("parry");
        
        weapon = victim->query_temp("weapon");

        if(objectp(weapon) && me->query_skill("sword")>100){ 
        if( random(ap+dp) > dp && random(2)>0){
        if(me->query("force") > random(victim->query("force"))){
                         if(weapon->query("rigidity") >=4 ){  
                               victim->start_busy(2);
                               weapon->move(environment(victim));       
                               victim->receive_damage("kee", ap);  
                               victim->receive_wound("kee", ap/2);      
       msg = HIR"只听“铛”的一声，$n手中的$w"HIR"已被你挑飞。$n也被你的剑气所伤。\n" NOR;
                                msg = replace_string(msg, "$w", weapon->name());    
                               }
                        else{
                               victim->start_busy(1);
msg = HIW"$N念动真言：“噫嘛啦萨！！”只听“啪”的一声响，$n手中$w"HIW"已被你震成两段。\n" NOR;
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
       msg = HIY"只听“嗡”地一声大响，$n手中的$w"HIY"在无形剑气的冲击下不住颤抖，险些脱手！\n" NOR;
                            msg = replace_string(msg, "$w", weapon->name()); 
                                                           }
                }

                return msg; 
    }
}

string perform_action_file(string action)
{
    return CLASS_D("tiankongjie") + "/xiaoyao-sword/" + action;
}

