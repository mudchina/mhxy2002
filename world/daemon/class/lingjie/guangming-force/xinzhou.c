//光明心咒
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        
        if( (int)me->query_skill("guangming-force",1) < 20)
                return notify_fail("你的光明心法还需要进一步的提高。\n");
        
        if( me->query("family/family_name")!="灵界")
                return notify_fail("您非灵界弟子，无法使用光明心咒");

        if( (int)me->query("force") < 250 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("mana") < 250 )
                return notify_fail("你的法力不够。\n");

        message_vision(HIC"$N盘膝而坐，双手扣诀--“落于无心，直于心定”一股清气淡淡的罩住$N...\n"NOR,me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
        me->receive_curing("sen", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -100);
        me->add("spells", -100);

        return 1;
}