// five by greenwc
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int damage,qq;
          object obj;


              if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「五行诀」？\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

	if((int)me->query_skill("wuxing-quan", 1) <100)
		return notify_fail("你对五行的了解还不够！\n");

if((int)me->query_skill("yange-blade", 1) <50)
		return notify_fail("你对金象的了解还不够！\n");
if((int)me->query_skill("fumo-zhang", 1) <50)
		return notify_fail("你对木象的了解还不够！\n");
if((int)me->query_skill("sanqing-jian", 1) <50)
		return notify_fail("你对水象的了解还不够！\n");
if((int)me->query_skill("taiyi", 1) <50)
		return notify_fail("你对火象的了解还不够！\n");
if((int)me->query_skill("kaishan-chui", 1) <50)
		return notify_fail("你对土象的了解还不够！\n");

        me->add("force", -200);
        me->receive_damage("kee", 50);

        obj = target->query_temp("weapon");
        if( random(me->query("max_force")) < 50 ) {
                write("糟糕，今日五行不顺！\n");
                return 1;
}

        me->delete("env/brief_message");
        target->delete("env/brief_message");
qq=random(5);
message_vision(HIY"\n$N换拳为掌，对空劈了几下，双掌发出淡淡的金芒！\n"NOR,me,target);
message_vision(HIY"只见一阵金光闪动，$N双掌向$n直扫而来，用的正是“金断”一诀！\n"NOR,me,target);
if (random((int)me->query_skill("blade")+ (int)me->query_skill("yange-blade", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("blade")+ (int)me->query_skill("yange-blade", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$n识得厉害，先行避了开来。\n"NOR,me,target);

message_vision(HIG"\n$N又是一声暴喝，双手箕张，臂上青筋条条暴出，宛若枯木\n"NOR,me,target);
message_vision(HIG"双手连晃，一式“木缠”若盘藤般将$n困在当中！\n"NOR,me,target);
if (random((int)me->query_skill("staff")+ (int)me->query_skill("fumo-zhang", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("staff")+ (int)me->query_skill("fumo-zhang", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$n逢虚不惑，逢实拆招，轻松化解了这道攻势。\n"NOR,me,target);

message_vision(HIC"\n$N双掌忽的白嫩了许多，双手连绵不绝接连出招，想以这式“水溅”迷惑住$n\n"NOR,me,target);
if (random((int)me->query_skill("sword")+ (int)me->query_skill("sanqing-jian", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("sword")+ (int)me->query_skill("sanqing-jian", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$n也随着$N拳意如浮萍般飘摆，潇洒的避开了这一击。\n"NOR,me,target);

message_vision(HIR"\n$N忽的袍袖一卷，一道“火焱”直扑$n\n"NOR,me,target);
if (random((int)me->query_skill("spells")+ (int)me->query_skill("taiyi", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("spells")+ (int)me->query_skill("taiyi", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$n哈哈一笑，轻舞于火光之中，豪无惧色。\n"NOR,me,target);

message_vision(YEL"\n$N腾身而起，一记怒拳由半空劈来\n"NOR,me,target);
message_vision(YEL"这“土掩”的气势，直迫$n，端的难以抗拒！\n"NOR,me,target);
if (random((int)me->query_skill("hammer")+ (int)me->query_skill("kaishan-chui", 1) +(int)me->query_skill("unarmed"))
             >(int)target->query_skill("parry")) 
{
 damage=random((int)me->query_skill("hammer")+ (int)me->query_skill("kaishan-chui", 1));
target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
}
else message_vision(HIM"$n屏息凝神，运力相抗，脚下步伐不曾乱得半点。\n"NOR,me,target);

if ((int)me->query_skill("baguazhen",1)>random((int)target->query_skill("literate",1))*2)
{
message_vision(HIW"$n没见过这五行阵仗，被困在当中！\n"NOR,me,target);
target->start_busy(5);
}

me->start_busy(2+random(3));
return 1;
}
