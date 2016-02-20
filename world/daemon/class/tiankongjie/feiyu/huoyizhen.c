// huoyizhen  icejia 2001

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("迦楼罗火翼阵只能对战斗中的对手使用。\n");
        if((int)me->query("force") < 5000 )
                return notify_fail("你的内力不够。\n");
        if((int)me->query("mana") < 5000 )
                return notify_fail("你的法力不够。\n");
        if((int) me->query_skill("feiyu",1) <= 300)
                return notify_fail("你的飞羽还不够精纯，不能施展出迦楼罗火翼阵。\n");
        if((int) me->query_skill("mtl-force",1) <= 300)
                return notify_fail("你的曼佗罗心经还不够精纯，不能施展出迦楼罗火翼阵。\n");
        if((int) me->query_skill("shanbishu",1) <= 300)
                return notify_fail("你的闪避术还不够精纯，不能施展出迦楼罗火翼阵。\n");
        if((int) me->query_skill("baimofa",1) <= 300)
                return notify_fail("你的白魔法还不够精纯，不能施展出迦楼罗火翼阵。\n");

        message_vision(HIR"$N念动真言缓缓从地面升起，两条火蛇向两侧游走包向$n。\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(5)+5);
        me->start_busy(5+random(2));
                me->add("force", -4000);
                me->add("mana", -4000);
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg = HIR "火蛇在$n身后合拢，顿时$n被笼罩在一片火海中。
羽毛犹如暴风雪般从$N身上飞射出来射向$n，
$N在暴风雪般的羽毛中，轻轻扔出了一根"HIY"金色的飞羽。" ;
msg +=  "\n金色的飞羽"HIR"直射向$n的心口，全部没入。$n也倒在了地上。。。\n" NOR;

        message_vision(msg, me, target);
                target->die();
        }
        me->start_busy(5);
        return ;
}


