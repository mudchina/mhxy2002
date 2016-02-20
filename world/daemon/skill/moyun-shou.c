//摩云手

//by tianlin 2001.7.3修改
#include <ansi.h>
inherit SKILL;

mapping *action = ({
   ([   "action":   HIM"$N一招"BLINK YEL"『螳螂捕蝉式』"NOR HIM"，左手抓向$n的丹田，就在$n回身自防的一瞬间，右手却已掐上了$n的$l"NOR,
     "dodge":     10,
     "parry":     10,
     "force":     160,
     "damage_type":   "刺伤",
                        "weapon":     "右手食指",
   ]),
   ([   "action": HIC"$N双手一翻，出"BLINK MAG"『梅花五朵』"NOR HIC"，双手如穿花蝴蝶一般上下翻飞。\n"CYN"$n看花了眼，刹那间$N已欺身到了眼前"NOR,
     "dodge":     5,
     "parry":     -15,
     "force":     180,
     "damage_type":   "内伤",
                        "weapon":     "右手",
   ]),
   ([   "action":     HIY"只见$N一转身，一指由胁下穿出，疾刺$n的$l，正在$n回身自防的一瞬间,拳击面门,竟是毒辣的杀手"NOR,
     "dodge":     5,
     "parry":     10,
     "force":     100,
     "damage_type":   "刺伤",
                        "weapon":     "左手食指",
   ]),
   ([   "action":     HIY"$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招"BLINK HIR"「拿云式」"NOR HIY"使$n进退两难"NOR,
     "dodge":     20,
     "parry":     20,
     "force":     140,
     "damage_type":   "内伤",
                        "weapon":     "左手", 
   ]),
([   "action":     YEL"$N一招"BLINK RED"『乌龙翻江』"NOR YEL"，左手在空中虚划了个半弧，拍向$n的$l"NOR,
     "dodge":     30,
     "parry":     10,
     "force":     70,
     "damage_type":   "内伤",
                        "weapon":     "左手",
   ]),
([   "action":     HIC"忽听$N一声怒吼，右手高高举起，一式"NOR+BLINK+HIY"『力劈华山』"NOR+HIC"，砍向$n的$l"NOR,
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "砍伤",
                        "weapon":     "右手",
   ]),
([   "action": "$N右手虚握，左手掌立如山，一招「批亢式」，猛地击向$n的$l",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "砍伤",
                        "weapon":     "左手",
   ]),
([   "action": "$N前脚着地，一手顶天成爪，一手指地，一招「追日式」劲气笼罩$n的全身",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "刺伤",
                        "weapon":     "左爪",
   ]),
([   "action": "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「拿云式」使$n进退两难",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "刺伤",
                        "weapon":     "右手",
   ]),
([   "action": "$N一手虚指$n的剑诀，一招「夺剑式」，一手劈空抓向$n手中的长剑",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "内伤",
                        "weapon":     "右掌",
   ]),
([   "action": "$N右腿斜插$n二腿之间，一招「抢珠式」，上手取目，下手反勾$n的裆部",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "内伤",
                        "weapon":     "左手",
   ]),
([   "action": "$N两手胸前环抱，腋下含空，五指如钩，一招「守缺式」插向$n的顶门",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "刺伤",
                        "weapon":     "左指",
   ]),
([   "action": "$N双手平提胸前，左手护住面门，一招「抱残式」右手推向$n的$l",
     "dodge":     10,
     "parry":     -10,
     "force":     220,
     "damage_type":   "刺伤",
                        "weapon":     "左指",
   ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练摩云手必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("moyunshou_per");
        if( !me->query_temp("moyunshou_per") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习摩云手。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍摩云手。\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/moyun-shou/" + func;
}

