//°æ¥Û¡¶∞Ù°ødali-bang.c
//by tianlin 2001/5/1
/*
¥Û¡¶∞Ù    dodge  10    parry  -10    damage  30
∞Ù∫≈¥Û¡¶£¨¡¶¥Û ∆√Õ£¨º±ƒ—’–º‹
*/

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
        ([      "name":                 "¡˘∂°ø™…Ω",
                "action":
"$N∑¢≥ˆ“ª…˘¿˜Ω–£¨ ÷÷–$w“‘“ª’–[5m[33m°∏¡˘∂°ø™…Ω°π[2;37;0m£¨¥¯◊≈∫Ù∫Ù∑Á…˘œÚ$nµƒ$l‘“»•",
                "dodge":                10,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "‘“…À"
        ]),
        ([      "name":                 "ªÏ„Á≥ı∆∆",
                "action":               
"$N…Ì–Œ“ª◊™£¨“ª’–[5m[31m°∏ªÏ„Á≥ı∆∆°π[2;37;0m π≥ˆ£¨÷‹Œß’…ƒ⁄Õ¡ Ø¬“∑…£¨
≈˘ˆ®º‰$w“—‘“œÚ$nµƒ$l£¨∂„“≤∂„≤ªø™¡À",
                "dodge":                15,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "‘“…À"
        ]),
        ([      "name":                 "∑≠Ω≠Ω¡∫£",
                "action":
"$NŒË∂Ø$w£¨“ª Ω[5m[1;36m°∏∑≠Ω≠Ω¡∫£°π[2;37;0m£¨≈¸Õ∑∏«¡≥µƒœÚ$nµƒ$l‘“»•",
                "dodge":                15,
		"parry":		0,
                "damage":               30,
                "damage_type":  "‘“…À"
        ]),
        ([      "name":                 "∞À∑Ω∑Á”Í",
                "action":
"$NŒË∂Ø$w£¨ π≥ˆ[5m[1;32m°∏∞À∑Ω∑Á”Í°π[2;37;0m£¨ª√≥ˆ¡ÀŒﬁ ˝$wœÚ$n‘“»•",
                "dodge":                0,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "‘“…À"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª£¨√ª”–∞Ï∑®¡∑¥Û¡¶∞Ù°£\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("ƒ„±ÿ–Îœ»’““ª∏˘∞Ù◊”≤≈ƒ‹¡∑¥Û¡¶∞Ù°£\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("ƒ„µƒƒ⁄¡¶ªÚ∆¯≤ªπª£¨√ª”–∞Ï∑®¡∑œ∞¥Û¡¶∞Ù°£\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("ƒ„∞¥◊≈À˘—ß¡∑¡À“ª±È¥Û¡¶∞Ù°£\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("dali-bang", 1) > 30 
	 && (int)me->query_skill("dali-bang", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\nƒ„Õª»ªæıµ√“ªπ…∂Ò∆¯≥Â…œ–ƒÕ∑£¨÷ªæıµ√œÎ…±»À....\n\n" NOR);
                me->add("bellicosity", 200);
	}
}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/dali-bang/"+func;
}

