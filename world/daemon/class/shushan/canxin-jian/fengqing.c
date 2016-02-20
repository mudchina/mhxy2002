// keelv.c 那一剑的风情
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        object ob;              // 对手的武器
        string msg;
        int i,attack_time,skill,damage;
        me=this_player();
        skill = me->query_skill("canxin-jian",1);
//      target=this_object();
//      ob=target->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character() )                return notify_fail("「那一剑的风情」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("canxin-jian", 1) < 200 )
                return notify_fail(HIW"你无法自行体会出「那一剑的风情」。\n"NOR);

        if ( me->query("force") < 400)
                return notify_fail(HIW"你的内力不够，现在无法使出「那一剑的风情」。\n"NOR);
        me->add("force", -200);


        msg = HIW "$N轻声长叹,使出了「那一剑的风情」,剑招中带着三分惊艳,三分潇洒,三分可爱和一分不可一世。\n";

  if((me->query_skill("sword")*me->query("int") ) > ((int)target->query_skill("force")*target->query("int")))
        {
 
                if (! objectp(ob = target->query_temp("weapon")))
                {
                        msg += "\n"HIW "那剑犹如一道电光闪过,却比彩虹更加绚丽!"NOR"\n\n"HIR"结果$n已为$N的剑意所伤,哇,的一声吐出一口鲜血。\n\n" NOR;
                        me->start_busy(3);
                        damage = 700 + random(skill);
                        target->receive_damage("kee", damage);
                        target->start_busy(3);
        message_vision(msg, me, target);
                } else
                {
                          msg += "\n"HIW"那剑犹如一道电光闪过,却比彩虹更加绚丽!"NOR"\n\n"HIR"结果$n已为$N的剑意所伤,哇,的一声吐出一口鲜血。\n" NOR;
                          msg += "\n"YEL"那一剑,击断了$n手里的"+ob->query("name")+"。\n\n"NOR;

                        ob->unequip();
                        ob->move(environment(target));
                        ob->set("name", YEL"断了的"NOR + ob->query("name"));
                        ob->set("long", "一"+ob->query("unit")+ob->query("name")+"。\n");
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        damage = 700 + random(skill / 2);
                        target->receive_damage("kee", damage);
                        me->start_busy(2);
                        target->start_busy(2);

        message_vision(msg, me, target);

                } 

        }
else
        {
                msg += HIW"那剑犹如一道电光闪过,却比彩虹更加绚丽!\n"NOR"\n"HIY"结果$n让自身真气灌注四周空间,消解了$N的剑意。\n" NOR;
                me->start_busy(random(2));
                message_vision(msg, me, target);

        } 
                
}
