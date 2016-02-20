// By tianlin 2001.5.1
// hunpofeiyang.c ªÍ∆«∑…—Ô
 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
 
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	
	me->clean_up_enemy();
	target = me->select_opponent();

	if( !me->is_fighting() )
	    	return notify_fail("°∏ªÍ∆«∑…—Ô°π÷ªƒ‹‘⁄’Ω∂∑÷– π”√°£\n");

	if( (int)me->query("force") < 500 )
		return notify_fail("ƒ„µƒƒ⁄¡¶ªπ≤ªπª∏ﬂ£°\n");

	if( (int)me->query_skill("unarmed") < 150 )
		return notify_fail("ƒ„µƒ»≠∑®ªπ≤ªµΩº“£¨Œﬁ∑® π”√ªÍ∆«∑…—Ô£°\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 60)
		return notify_fail("ƒ„ªØπ«√‡’∆µƒ–ﬁŒ™≤ªπª£¨≤ªƒ‹ π”√ªÍ∆«∑…—Ô! \n");
	 
	msg = HIY "$N¥Û∫»“ª…˘£¨ π≥ˆªØπ«√‡’∆µƒæ¯ºº[5m[1;37m°∏ªÍ∆«∑…—Ô°π[2;37;0m[1;33m£¨À´»≠ ∆»Á¿◊ˆ™£¨œÚ$nª˜»•°£\n"NOR;
             message_vision(msg, me, target);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	
	me->start_busy(2);
	return 1;
}
