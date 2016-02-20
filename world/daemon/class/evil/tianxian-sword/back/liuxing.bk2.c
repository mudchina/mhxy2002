// zxzx.c
//write by yesi
//yeahsi@21cn.com
// modify by ken 2001/7/10
#include <ansi.h>
inherit SSERVER;

void check(object me);
void zxzx_effect(object me, object victim);
void remove_effect(object me);

int perform(object me)
{
//      object ob;
        int skill;
        int sword_skill,qixiu_skill;
        
        skill = me->query_skill("evil-force",1);
        if( skill > 250 ) skill=250;
        sword_skill= me->query_skill("sword",1);
        qixiu_skill= me->query_skill("tianxian-sword",1);
                       
        if( skill < 100 )  return notify_fail("你的魔功根本就不熟，怎么能用天魔斩。\n");
        if( sword_skill < 100 )  return notify_fail("你的基本剑法不够熟，用天魔斩有点困难。\n");
        if( qixiu_skill < 100 )  return notify_fail("你的天仙剑法还没练好，用不了天魔斩。\n");
        
        if( me->query_temp("zxzx") ) 
          {remove_effect(me);return 1;}
          
        if (me->query_skill_mapped("force")!="evil-force")
            return notify_fail("「天·魔·斩」没有运魔功的话是很难发动的。\n");

//        if( !(ob = me->query_temp("weapon"))
//        ||      (string)ob->query("skill_type") != "sword"
//        ||      (string)ob->query("material") != "fire" )
//                return notify_fail("手上没有火如何运天魔斩？\n");
        
        if(me->query("family/family_name") != "魔教")
                return notify_fail("你又不是魔，无法化身为魔！\n");     
        
        if( time()-(int)me->query_temp("zxzx_end") < 10 )
                return notify_fail("你刚刚施展过天魔斩，最好是先休息下。\n");       
               
        
        if( (int)me->query("force") < 1000 )     
                return notify_fail("你的内力不够。\n");
 
        me->add("force", -skill);
        message_vision(HIY "$N微一凝神，运起血魔神功，全身骨节发出一阵爆豆般的声响！\n
 随即化做一个巨大无比的魔神！\n" NOR, me);
        me->set_temp("zxzx", 1);
        me->set_temp("zxzx_time",skill);
                   
        call_out("check", 1, me);
        return 1;
}
void check(object me)
{       
        object weapon;
        
                
         if (me->query_skill_mapped("force") != "evil-force"
                 || !objectp(weapon=me->query_temp("weapon")) 
                 || (weapon->query("apply/skill_type") != "sword" 
                     && weapon->query("skill_type") != "sword" ) 
                 ||  me->query_skill_mapped("sword") != "tianxian-sword" )     
             remove_effect(me);
         else if(me->query_temp("zxzx_time")<1)
             remove_effect(me);                 
         else {  me->add_temp("zxzx_time",-1);
                call_out("check", 1, me);
              }
                     
}

void remove_effect(object me)
{
        if(!me) return;
        remove_call_out("check");
        me->delete_temp("zxzx");
        me->set_temp("zxzx_end",time());
        tell_object(me, CYN"你的天魔劲的效果散光了。\n"NOR);
}

void zxzx_effect(object me, object victim)
{   int damage,ini_damage_apply;
    string str;

   if ( random(2)>0 )
          { ini_damage_apply = me->query_temp("apply/damage");
            me->add_temp("zxzx",1);
            message_vision(HIY"\n$N大喝一声：＂天魔斩＂！\n
手中的长剑化做一柄巨大无比的火龙，闪电般的扑向了$n！"NOR,me,victim);
            me->add_temp("apply/damage",15);
            damage = COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));                                 
   if( damage > 0 )
          {
           message_vision(HIY"\n$N得势不饶人，又对其连连发动攻击！\n"NOR,me);
           me->add_temp("apply/damage",15);
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon")); 
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon")); 
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
           me->add_temp("zxzx",-1);
           if (victim->query("eff_kee")<0 || !living(victim) )  
                       {str="据说"+victim->name()+"被"+me->name()+"刺死了！"NOR;
                        message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
                       }
           }             
    else me->add_temp("zxzx",-1);
    
    me->set_temp("apply/damage",ini_damage_apply);
          }
}
