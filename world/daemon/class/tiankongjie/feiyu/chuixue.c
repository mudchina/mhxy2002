//icejia

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    object weapon;
        string who1, who2;
    int damage, lvl, r_lvl, count, form, skill, i;
    string msg;

        if( !me->query_skill("feiyu", 1) )
                return notify_fail("你不会迦楼罗翼吹雪。\n");
if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「迦楼罗翼吹雪」？\n");
        if( skill > 300 ) skill=300;
        if(me->query("family/family_name") != "天空界" )
                return notify_fail("你是哪儿偷学来的武功，也想用「迦楼罗翼吹雪」?\n");
        if(!me->is_fighting())
                return notify_fail("「迦楼罗翼吹雪」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("feiyu", 1) < 100)
                return notify_fail("你的飞羽术级别还不够，小心走火入魔！\n");               
        if (me->query_skill_mapped("force")!="mtl-force")
                return notify_fail("迦楼罗翼吹雪必须配合曼佗罗心经才能使用。\n"); 
 //               if( time()-(int)me->query_temp("xingyun_end") < 10 )
 //               return notify_fail("绝招用多就不灵了！\n"); 
            me->delete("env/brief_message");
            target->delete("env/brief_message");
    skill = (int)me->query_skill("feiyu", 1);
        lvl = skill/20;
        r_lvl = 3+random(lvl);
        if( r_lvl < 1) r_lvl = 1;
        count = me->query_str();
        write( HIW "你默运曼佗罗心经，使出迦楼罗翼吹雪，片片羽毛漫天飞舞,瞬间在周身裹成一团云雾," + target->name() + "的攻击被尽数挡回。\n"NOR);
        tell_object(target, HIW"忽然，你发现有一股奇怪的力量向你袭来,四周片片雪白的羽毛在你周围使你动探不得。\n"NOR);
 if (random(me->query("force",1)) > 4*target->query("force",1)/5 )
        {
                target->start_busy(random(3));                
                damage = skill/2 + r_lvl*target->query("force_factor",1);                
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage);
                me->add("force", -damage);
                                msg = CYN "$N默运神功，使出迦楼罗翼吹雪。\n"NOR;
                        msg += HIW "云雾罩将$n的内力全数反击回去！\n" NOR;                
                if( damage < 70 )
                        msg += HIM"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
                else if( damage < 100 )
                       msg += HIR"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 150 )
                       msg += RED"结果$n被$N的飞羽，片片穿透而过。\n"NOR;
                else
                       msg += RED"结果$n被$N的羽毛，透胸而过！！\n"NOR;
                message_vision(msg, me, target);
        }
        else 
        {
                tell_object(target, HIW"你周身不畅，似乎有股奇异的力量，将你的出招竟然反了回来击向自己！\n"NOR);
                target->start_busy(random(3));
                message("vision", HIW"\n" + target->name() + "被羽毛裹住，片片羽毛控制着你不停的象自己进攻！\n\n"NOR, environment(me), target);
                for(i = 0; i < r_lvl; i++)
                COMBAT_D->do_attack(target, target, target->query_temp("weapon") );
                me->add("force", -300);
                }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);}
                                
        }
        me->set_temp("xingyun_end",time());
        me->start_busy(2);
        return 1;
}


