// icejia grin

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage =0, dragon;
        int myhammer;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("天狼斩只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if(me->query("family/family_name") != "天空界")
                return notify_fail("不是天界弟子的也想用天狼斩？\n");
             
        if( (int)me->query_skill("tianlang-blade", 1) < 150 )
                return notify_fail("你的天狼夜摩刀不够娴熟，不能发出「天狼斩」。\n");
                                
        if( (int)me->query_skill("shouya-force", 1) < 150 )
                return notify_fail("你的兽牙魔经不够高，不能够运起那股劲气。\n");
                        
        if( (int)me->query("force", 1) < 600 )
                return notify_fail("你现在内力太弱，不能发出「雷霆三击」。\n");
                        
        msg = HIG "$N撮嘴尖啸，猛吸一口气,快速运转兽牙魔经，浑圆霸气散布四周五丈范围
随后将浑圆内力灌注于刀上，
一连三刀带起三道劲风，从上，中，下三路带着撕晋烈帛般的声音扫向$n。
这正是黑幕凯的绝学"HIR"「天狼斩」\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("shouya-force", 1)) > target->query_skill("force", 1)/4)
        {
                target->start_busy(1);
                
                damage += (int)me->query_skill("tianlang-blade", 1);
                damage = damage +  (int)me->query_skill("shouya-force", 1);
                damage = damage +  (int)me->query_skill("shanbishu", 1);
                
                  if (damage < 600) {
                        dragon = 1;
                   } else if (damage < 900) {
                        damage = damage/3*4;
                        dragon = 2;
                   } else {
                        damage = damage/5*8;
                        dragon = 3;
                   }                    
                
                if (damage >= target->query("max_kee")) damage = target->query("max_kee")-1;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                me->add("force", -300);
                msg += HIC"$n被$N的兽牙魔经的劲力牵制动弹不得，身中"+chinese_number(dragon)+"刀！\n$n只觉兵刃对身体造成的疼痛似乎已经不算什么，强大的霸气，只震的$n的五脏六腑都在颤抖！\n"NOR;
                me->start_busy(1+random(2));
        } else 
        {
                msg += MAG"$p识得这招的厉害，向后几个纵身跳出了$P浑圆霸气散布的范围。\n"NOR;
                me->add("force", -350);
                me->start_busy(1+random(2));
        }

        message_vision(msg, me, target);
        if (damage > 0) COMBAT_D->report_status(target);
        return 1;
}

