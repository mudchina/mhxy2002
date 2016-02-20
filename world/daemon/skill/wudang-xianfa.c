//By tianlin@mhxy for 2001.9.25
inherit SKILL;


int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 20 )
        return notify_fail("你的法术修为还不够高深，无法学习武当仙法。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("wudang") + "/wudang-xianfa/" + spell;
}

string type() { return "magic"; }
