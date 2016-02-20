//Cracked by Roath
//by tianlin 2001.8修改
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int i, j;	        
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁使用这一招「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」。\n");

        if(!me->is_fighting())
                return notify_fail("「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」只能对战斗中的对手使用。\n");

        if(me->query("family/family_name") != "东海龙宫" )
                return notify_fail("你是哪儿偷学来的武功，也想使用！\n");

        if( (int)me->query_skill("dragonfight",1) < 120)
        return notify_fail("你的龙行搏击还不够纯熟!!\n");

        if((int)me->query("force") < 700 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 200 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
	}

	me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(YEL"\n$N双掌平平提到胸前，神色沉重的缓缓施出菩提指的最后一招「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+YEL"」一招八式推向对方！"NOR, me);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIC"\n第一式！$N右掌一式「龙现于野」，勇猛无比地劈向对方！\n"NOR, me, weapon);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
       message_vision(HIR  "第二式！$N双掌施出一式「鸿龙在陆」，隐隐约约带着掌风拍向对方！\n"NOR, me, weapon);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIB  "第三式！$N左掌御胸，右掌一式「潜龙出海」缓缓推向对方！\n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIY  "第四式！$N使出「龙跃在天」，向对方的连拍数掌！\n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIG "第五式！$N双掌一式「双龙戏水」一前一后按向对方的胸前！\n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIM  "第六式！$N身形转动，使出「晴天六龙」向对方连打六下！\n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(YEL  "第七式！$N脚下一转，突然欺到对方身前，一式「龙战于野」直拍向对方面门. \n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIW "第八式！$N突然飞起，双掌居高临下最后一式「龙啸九天」全力拍向对方！\n"NOR, me, weapon);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        if( i ) me->set("env/brief_message", 1);
        if( j ) target->set("env/brief_message", 1);

	me->receive_damage("kee", 100);
	me->add("force", -400);//我给多加了一点

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);//加大busy
	return 1;
}
