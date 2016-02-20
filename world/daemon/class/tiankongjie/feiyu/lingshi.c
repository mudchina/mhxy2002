// icejia
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("feiyu");
        if((int) me->query_skill("feiyu",1) < 120)
                return notify_fail("你的控制羽毛的技术还没练好,还不能操纵迦楼罗灵视羽。");
//      if( !target ) target = offensive_target(me);
//      if( !target
//      ||      !target->is_character()
//      ||      !me->is_fighting(target) )
//              return notify_fail("［月影夜舞］只能对战斗中的对手使用。\n");
        if((string)me->query("family/family_name")!="天空界")
                return notify_fail("这招是天空界不传之秘，你不能用！\n");
        if(me->query("env/invisibility"))
                return notify_fail("你已经抛出灵视羽了。\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不足以操纵灵视羽！\n");
        if(me->query("force") < 600)
                return notify_fail("你的内力不够！\n");
        me->add("force",-300);
message_vision( HIC "$N单掌虚握，一根天蓝色的羽毛，在掌中诞生，缓缓的升到空中去了。\n\n" NOR,me,target);
        me->set("env/invisibility",1);
        me->start_busy(1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/3);
        return 1;
}
void remove_effect(object me)
{
        me->delete("env/invisibility");
        tell_object(me, "$N觉得内力不继，灵视羽慢慢飞回$N的身上隐退不见了。\n");
}


