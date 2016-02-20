#include <ansi.h>
#include <combat.h>

inherit SSERVER;
void guiku_ok(object);

int perform(object me, object target)
{
        object weapon;
        string msg;
        string str;//谣言的变量
        int damage, max_qi, myqi, mymz,  tamz, mzl;
        string anqi_type,b_unit;


        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("你要对谁使用"HIY"『"NOR""HIR"鬼哭血散斩"HIY"』"NOR"？\n");

        if(!me->is_fighting())
                return notify_fail(HIY"『"NOR""HIR"鬼哭血散斩"HIY"』"NOR"只能在战斗中使用！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail("装备刀子才能使用这招！\n");
        
      if((int)me->query_skill("kugu-blade", 1) <80)
            return notify_fail("你的枯骨刀等级太差！\n");

      if((int)me->query_skill("huntian-qigong", 1) <80)
            return notify_fail("你的混天气功等级太差！\n");

      if (me->query_skill_mapped("force")!="huntian-qigong")
                return notify_fail(HIY"『"NOR""HIR"鬼哭血散斩"HIY"』"NOR"必须配合混天气功才能使用。\n");

        if((string)me->query("family/family_name")!="陷空山无底洞" )
                return notify_fail("偷学的功夫，如何能用？\n");

      if((int)me->query_skill("blade", 1) <80)
            return notify_fail("你对刀法的理解太差了!\n");

        if((int)me->query("max_force") < 1200 )
                return notify_fail("你的内力太弱了！\n");

        if((int)me->query("kee") < (int)me->query("max_kee")/3 )
                return notify_fail("你太虚弱了！\n");

                if(me->query_temp("no_guiku"))
                        return notify_fail("你太累了，还是先歇歇吧。\n");

       if (me->query("force")<500)
           return notify_fail("你内力不继，无法发挥"HIY"『"NOR""HIR"鬼哭血散斩"HIY"』"NOR"的威力。\n");




           msg =  HIB"\n只见$N凝神吸气暴喝一声，使出"HIY"『"NOR""HIR"鬼哭血散斩"HIY"』"HIB"手中"+weapon->query("name")+HIB"连连挥舞，
犹如鬼哭神嚎般攻向$n，也不顾自己的破绽有多大！\n" NOR;



        me->add("force", -100);
        if( random(me->query("combat_exp"))*2 < (int)target->query("combat_exp")/2 ) {
              msg +=   WHT "$n也不管$N的破绽有多大，只是连连后退，左躲右闪的躲开了$N的这招攻击。\n"NOR;
              message_vision(msg, me, target);
              me->start_busy(1+random(3));
         } else {
                //me->start_busy(random(2));
                target->start_busy(random(2));
                damage = (int)me->query_skill("kugu-blade", 1);
                damage = damage+me->query("force_factor");
                target->receive_damage("kee", damage*2,me);
                target->receive_wound("kee", damage,me);
                me->add("force", -100);
        me->set_temp("no_guiku",1);
                call_out("guiku_ok",3+random(3),me);
                  msg += HIB "不料$N居然将手中"+weapon->query("name")+HIB"一刀刺进了$n的胸口。
结果只听见$n一声惨嚎，"+weapon->query("name")+HIB"已在$p的胸口对穿而出。\n"NOR;

                   message_vision(msg, me, target);
                   COMBAT_D->report_status(target); 
           }
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+HIM"被"+me->name()+HIM"用"NOR+YEL"陷空山"NOR+HIM"绝学"HIY"『"NOR""HIR"鬼哭血散斩"HIY"』"HIM"打死了，据说"+target->name()+HIM"是被一刀致命而亡！";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
          me->start_busy(random(2));
          target->start_busy(1+random(2));
        target->kill_ob(me);
          return 1;
}

void guiku_ok(object me)
{ 
if (!me) return;
      me->delete_temp("no_guiku");
}