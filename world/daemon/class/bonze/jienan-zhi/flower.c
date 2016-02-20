#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int number, size, i, four,amount;
        object *tar;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「佛祖沾花」？\n");

        if((int)me->query("force") < 50+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("kee") < 200 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("jienan-zhi", 1) <100)
                return notify_fail("你的劫难指级别还不够！\n");
              if((int)me->query_skill("huadao", 1) < 20)
                return notify_fail("你对花道还不大了解！\n");

        tar=all_inventory(me);
        size = sizeof(tar); 
        if(size) {
                for(i=0;i<size;i++)
                if(tar[i]->query("material") == "flower") {
                        if (tar[i]->query_amount())
                              number+=tar[i]->query_amount();
                        else number++;
}
}
        write((string)number+"\n");

        if((int)number < 1)
               return notify_fail("你身上无花，何以沾花？\n");

        me->add("force", -50-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);
        msg = HIG
"\n$N面露诡异笑容，将右手三指拢入袖中，做沾花状\n"+
"$n感到事态不妙，一时间不知所以，只觉三道劲风扑面而来，连忙闪避！\n" NOR;

        ap = me->query_skill("jienan-zhi", 1)+me->query_skill("huadao",1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 400) );
        dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) {
                msg += HIC "好在$n躲的及时，指风拂面而过，无甚大碍！\n\n"NOR;
                message_vision(msg, me, target);
        } else {
damage = 50+random(50)+(int)me->query("force_factor")+random((int)me->query_skill("huadao",1))*2;
                msg += HIC "这三道指风看似柔弱无力，却如疾风将$n的气，神，内力尽数散去！\n" NOR;
                       target->receive_wound("sen", damage);
                        target->receive_wound("kee", damage);
                                           target->add("force",-damage/10);
                        me->improve_skill("jienan-zhi", 1, 1);
                message_vision(msg, me, target);
}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}

        for (i = 0; i< size; i++){
           if (tar[i]->query("material") == "flower"){
                amount=tar[i]->query_amount();
                if (amount) four+=amount;
                  else four++;
                if (four <= 1)
                destruct(tar[i]);
                else {
                       tar[i]->set_amount(four-1);
                       four=1;
                       break;
}
}
}
        me->start_busy(random(4));
        return 1;
}
