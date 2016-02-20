// by nina
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extra;
        object weapon;

        if(me->is_busy(1))
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("baihua-zhang",1) *2;

        if ( extra < 150) return notify_fail("你的百花掌还不够纯熟！\n");

        if(me->query_temp("last_siji")+5>time())
                return notify_fail("你刚刚使过「飞扬四季」,先歇一歇吧。\n");

        if(me->query("family/family_name") != "月宫")
                return notify_fail("「飞扬四季」是月宫不传之密！\n");

        if( (int)me->query("force",1) < 1000 )
                return notify_fail("你的内力不够，不能使用「飞扬四季」。\n");
        
        if( (int)me->query_skill("moonforce", 1) < 150 )
                return notify_fail("你的圆月心法不够娴熟，不能使用「飞扬四季」。n");
        
        if( (int)me->query_skill("moondance", 1) < 150 )
                return notify_fail("你的冷月凝香舞不够娴熟，不能使用「飞扬四季」。n");
     
        if( (int)me->query_skill("snowsword", 1) < 150 )
                return notify_fail("你的风回雪舞剑法不够娴熟，不能使用「飞扬四季」。n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［飞扬四季］只能对战斗中的对手使用。\n");                me->add_temp("apply/attack",extra/10);
        weapon = me->query_temp("weapon");
        msg = HIR  "$N使出百花掌中的不传绝技［飞扬四季］，一招连环四式向$n攻出！\n" NOR;
        message_vision(msg,me,target);
        msg = HIG  "\n~~~ 百花迎春 ~~~~ ！" NOR;
        message_vision(msg,me,target);
        msg = HIG "$N双掌翻飞, 宛如片片花瓣,夹杂着绵绵的劲力,层层拍向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "伴随着片片飞花,$n的眼前出现了翠绿的春季景色..." NOR;
        if(random((int)me->query("combat_exp")*5) >= (int)target->query("combat_exp"))
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIB "$N被掌法产生的幻象所迷惑,显得目光呆滞...,伴随着啊的一声惨叫, 一股蓝气从$N顶门喷涌而出！\n" NOR,target);
        target->receive_wound("sen",extra);
        me->receive_heal("sen",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N似乎看透了这一切,闭目调息,不为情形所迷惑...\n" NOR,target);
        }
        msg = HIC  "\n~~~ 仲夏晚风 ~~~~ ！" NOR;
        message_vision(msg,me,target);
        msg = HIC "$N变探出一掌, 划出一道美丽的弧线, 恰似柔柔微风, 击向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "伴随着柔柔的微风,$n的眼前出现了斑斓的夏季景色..." NOR;
        if(random((int)me->query("combat_exp")*5) >= (int)target->query("combat_exp"))
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIR "$N被掌法产生的幻象所迷惑,显得两眼迷茫...， 伴随着重重的一声闷哼，一股血气从顶门喷涌而出！\n" NOR,target);
        target->receive_wound("kee",extra);
        me->receive_heal("kee",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N似乎看透了这一切,转过脸去,不为情形所迷惑...\n" NOR,target);
        }
        msg = HIY  "\n~~~ 深秋雾幻 ~~~~ ！" NOR; 
        message_vision(msg,me,target);
        msg = HIY "$N腾空跃起, 身行变幻不定, 道道掌影, 无懈可击的击向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "伴随着不定的雾岚,$n的眼前出现了金黄的秋季景色..." NOR;
        if(random((int)me->query("combat_exp")*5) >= (int)target->query("combat_exp"))
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIC "$N被掌法产生的幻象所迷惑,显得心神涣散....，伴随着野兽般的长啸， 一股青气从$N顶门喷涌而出！\n" NOR,target);
        target->receive_wound("sen",extra);
        me->receive_heal("sen",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N似乎看透了这一切,屏气凝神,不为情形所迷惑...\n" NOR,target);
        }
        msg = HIW  "\n~~~ 飘雪寒冬 ~~~~ ！" NOR; 
        message_vision(msg,me,target); 
        msg = HIW "$N气运丹田, 双掌推出,无穷霸气化做片片飞雪,将$n罩在无尽内力中！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "伴随着纷飞的雪花,$n的眼前出现了苍茫的冬季景色..." NOR;
        if(random((int)me->query("combat_exp")*5) >= (int)target->query("combat_exp"))
        {
        message_vision(msg+"\n",me,target);
        message_vision( MAG "$N被掌法产生的幻象所迷惑,显得浑身发抖....，伴随牙齿碰撞的声音，一股紫气从$N顶门喷涌而出！\n" NOR,target);
        target->receive_wound("kee",extra);
        me->receive_heal("kee",extra);
        }       
        else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N似乎看透了这一切,驻念于心,不为情形所迷惑...\n" NOR,target);
        }
        me->start_busy(1+random(3));
        me->add("force",-300);
        me->add_temp("apply/attack",-extra/10);
        me->set_temp("last_siji",time());

        return 1;
}
