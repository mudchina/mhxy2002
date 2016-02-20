// sgzl
// 飞天御剑法，

/*
飞天御剑法    dodge  -4    parry  -4    damage  25
飞天御剑流的镇派功夫,是古代的神奇功夫!可算无敌!
*/

// 龙槌闪,龙翔闪,双龙闪,飞龙闪,龙巢闪
// 龙卷闪,龙卷闪·寒风,龙卷闪·旋,龙卷闪·岚

inherit SKILL;


mapping *action = ({
        ([      "name":                 "龙槌闪",
                "action":
"$N跳到空中,手中$w紧握，向$n劈去，都有似开山大刀一般，好一力道雄厚的「龙槌闪」",
                "dodge":                -15,
                "parry":                10,
                "damage":               30,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "龙翔闪",
                "action":
"只见$N左手辅剑，向空中舞剑，手中$w向$n的全身砍去\n"
"正是一招「龙翔闪」！",
                "dodge":                -5,
                "parry":                -10,
                "damage":               30,
                "damage_type":          "砍伤"
        ]),
        ([      "name":                 "龙卷闪",
                "action":
"$N飞身上前，手中$w疾舞，一招「龙卷闪」幻出团团剑芒，将$n紧紧裹在其中",
                "dodge":                -10,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "劈伤"
        ]),
        ([      "name":                 "龙巢闪",
                "action":
"$N打到兴发，蓦地里一声清啸，手中$w急速向$n的$l刺去！这招山崩海啸般的「龙巢闪」完全将$n惊呆了",
                "dodge":                -10,
                "parry":                -5,
                "damage":               20,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "飞龙闪",
                "action":
"只见$N单足离地，使出一招「飞龙闪」，手中$w急速飞进，劈出层层剑气，直向$n的$l劈去",
                "dodge":                -5,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "土龙闪",
                "action":
"$N快速前进，一式「土龙闪」，身随剑起，$N向地面一挥,地上的土向$n卷去,招势若土龙卷身，$n哪里闪避得过",
                "dodge":                -5,
                "parry":                -5,
                "damage":               20,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "龙卷闪·寒风",
                "action":
"$N右手捏着剑,一式「龙卷闪·寒风」，手中$w由左至右，劈出万道光芒\n"
"剑刃急颤，根本劈不到对方",
                "dodge":                -15,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "龙卷闪·岚",
                "action":
"只见$N身形慢慢飞起,神情极为兴奋，不经意间右手$w一砍，\n"
"$w直奔$n头部，这一招「龙卷闪·岚」果然如诗如画",
                "dodge":                -10,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "龙卷闪·旋",
                "action":
"只见$w挽出数朵剑芒，猛地向$n砍去,$n哪里知道「龙卷闪·旋」的利害,躲闪不及,已被劈中脸部",
                "dodge":                -20,
                "parry":                -10,
                "damage":               20,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "龙巢闪·咬",
                "action":
"只见$N向$n劈去,$n哪里识得这招「龙巢闪·咬」的利害",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "刺伤"
        ]),
        ([      "name":                 "龙鸣闪",
                "action":
"$N突然脸色突变，将剑插回剑套,又急速拔出,剑身和剑套发出鸣响,鸣声就像龙鸣一样！而且$w也向$n斩去，\n"
"眼见$N$w直奔$n的$l，$n却不知如何防备这招「龙鸣闪」",
                "dodge":                -5,
                "parry":                -15,
                "damage":               30,
                "damage_type":          "割伤"
        ]),
        ([      "name":                 "双龙闪",
                "action":
"$N身形突变，先用$w向$n劈去,随后又用剑套打向$n,这一招「双龙闪」去势防不胜防,直奔$n的$l",
                "dodge":                -10,
                "damage":               25,
                "damage_type":          "刺伤"
        ]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力修为不够深，无法学习飞天御剑法。\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一柄剑才能练习剑法。\n");
        return 1;
}

int practice_skill(object me)
{
        int dod=(int)me->query_skill("dodge");
        int swo=(int)me->query_skill("yujian-sword");

        if (dod<swo/2)
                return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("你体质欠佳，强练飞天御剑法有害无益。\n");
        if ((int)me->query("force") < 5)
                return notify_fail("你内力不足，强练飞天御剑法有走火入魔的危险。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        message_vision("$N默默回忆了一会儿，然后练了一遍飞天御剑法。\n", me);
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

string perform_action_file(string func)
{
        return CLASS_D("yujian") + "/yujian-sword/"+func;
}