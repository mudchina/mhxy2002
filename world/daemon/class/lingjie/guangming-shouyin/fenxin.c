// llink 2001.2.20
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target, *inv;
        int skill, ap, dp, equip;
        int neili_wound, qi_wound ;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("guangming-shouyin",1);

        if( !(me->is_fighting() ))
                return notify_fail("「焚心似火」只能对战斗中的对手使用。\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须空手运功。\n");

        if( skill < 50)
                return notify_fail("你的「光明手印」等级不够, 不能使出「焚心似火」！\n");

        if( me->query_skill("guangming-force",1) < 60)
                return notify_fail("你的「光明心法」等级不够, 不能使出「焚心似火」！\n");

        if( me->query("force") < 500 )
                return notify_fail("你的内力不够，无法运功！\n");
 
        msg = HIC "$N聚气在手，手掌渐渐变红,使出一招"HIR"「焚心似火」"NOR"，向$n的胸口卷去。\n"NOR;

        ap = ((me->query("combat_exp"))*(me->query_dex()));
        dp = ((target->query("combat_exp"))*(target->query_dex()))/2;

        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("force",-300);


                neili_wound = 100 + random(skill);
                if(neili_wound > target->query("force"))
                        neili_wound = target->query("force");

                qi_wound = target->query("qi") - 50;
//              qi_wound = neili_wound / 5;
//              if(qi_wound > target->query("qi"))
//                      qi_wound = target->query("qi");

                target->receive_damage("qi", qi_wound);
                target->receive_wound("qi", qi_wound);
                target->add("neili", -neili_wound);
                target->start_busy(2);
                me->start_busy(random(2));

                inv = all_inventory(target);
msg += HIR "$n只觉得眼前一黑，一阵赤炎扑面而来，“哇”的一声喷出一口鲜血！\n"NOR;
                for(equip=0; equip<sizeof(inv); equip++)
                {
                        if( inv[equip]->query("equipped") &&
                                !inv[equip]->query("weapon_prop") )
                        {
msg += RED "$n闻到一股焦味，发现身上的"+inv[equip]->query("name")+HIR"全不都被赤炎烧光变成了白灰，掉在了地上！\n"NOR;
                        inv[equip]->unequip();
                        inv[equip]->reset_action();
                        inv[equip]->move(environment(target));
                        inv[equip]->set("name", inv[equip]->query("name") + "的碎片");
                        inv[equip]->set("value", 0);
                        inv[equip]->set("armor_prop", 0);
                        inv[equip]->set("long", "一堆破碎物事，好象是布片铁片什么的。\n");
                        }
                }
        }
        else
        {
msg += HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me)) me->add("force",-300);
                me->start_busy(4);
        }
    message_vision(msg, me, target);

        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);

        return 1;
}
