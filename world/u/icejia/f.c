// created by ken   2001.3.9
#include <ansi.h>

inherit SSERVER;

void free(object target);
int perform(object me, object target)
{
       object weapon;
       int ap, ap1, ap2, dp, dp1, dp2, kaee, kkee, damage,hitt;
       if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("���빥��˭��\n");

        if(!me->is_fighting())
                return notify_fail("��ɲ����������.\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("��������������ˡ�\n");

        if((int)me->query("force") < 1500 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("huolong-zhang", 1) < 120)
                return notify_fail("��Ļ��������л����Ǻܴ��죬��ʱ���ò��ˡ�\n");

        if( (int)me->query_skill("evil-force", 1) < 120)
                return notify_fail("���ħ���򲻵����޷�������ô�������书��\n");

        if( (int)me->query_skill("unarmed", 1) < 120)
                return notify_fail("���ȭ��������ǳ�����Ǳ����������ˡ�\n");

  message_vision(HIR+"ֻ��$N˫�־���һ����𣬻������������������������֮����$nϮ����\n" NOR,me,target,);
       ap = (int)me->query("combat_exp");
       ap1 = (int)me->query_skill("unarmed")+(int)me->query_skill("evil-force")+(int)me->query_skill("huolong-zhang");  
       ap2 = me->query("max_mana")+me->query("max_force") ;
       dp = (int)target->query("combat_exp");
       dp1 = target->query("max_mana")+target->query("max_force") ;
       dp2 = (int)target->query_skill("parry")+(int)target->query_skill("force");
       hitt = random(9);  
       if(hitt<1) hitt=1;
       if (random(ap+dp) > dp)
   {
                message_vision( HIR "$n�������������ϱ�"HIY+chinese_number(hitt)+HIR "���������������\n"
NOR,me,target,);

             me->add("force",-800);
             damage=random(ap1+ap2)*hitt;
             if(damage<1) damage=random(ap1);
             if(damage<300) damage=500;
             target->receive_damage("kee", damage, me);
             COMBAT_D->report_status(target);
             me->start_busy(random(3));
}
         else {
             message_vision(HIC "$N˫�ۻ��˸���Բ,Ӳ�ǽ�$n����ȫ�����˿���\n" NOR,target,me,);  
             me->add("force",-400);
             me->start_busy(2);
        }
        return 1;
}
