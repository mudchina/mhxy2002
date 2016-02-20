//Cracked by Roath
//evil...........2000.4.16
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,j,k,lmt;
        object weapon;
        j=(int)me->query_skill("fumo-zhang",1)+me->query_skill("staff",1)/2;
	k=(int)me->query_skill("fumo-zhang",1);
        if(j<180 || k<1)            
        return notify_fail("你的伏魔杖法与基本杖法还不够纯熟，怕是无法运用「群魔乱舞」！\n");
      if(me->query_skill("zhenyuan-force",1) < 120)
    return notify_fail("你的内功底子不足，无法运杖如风，施展不出「群魔乱舞」。\n");

        if((string)me->query_skill_mapped("force")!="zhenyuan-force")
        return notify_fail("「群魔乱舞」必须以镇元神功为底子。\n");

  if(me->query("max_force") < 500)
      return notify_fail("你的内力不足，难以随意挥动一把禅杖。\n");

       if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「群魔乱舞」只能对战斗中的对手使用。\n");
         if(me->query("family/family_name") != "五庄观")
                return notify_fail("「群魔乱舞」只有五庄观弟子才能用！\n");

        weapon = me->query_temp("weapon");

        msg = HIM  "$N身型闪动，地面随之起伏一降狂风，手中"+ weapon->name()+  "也有如狂风暴雨般地向$n卷来！" NOR;

        message_vision(msg,me,target);

        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        lmt = 9;
        for(i=6;i<=lmt;i++)
        {
        me->set_temp("FMZ_perform",i);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        }
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
        me->add("force",-extra*5);
         me->delete_temp("FMZ_perform");
        me->start_busy(2+random(1));
        return 1;
}



