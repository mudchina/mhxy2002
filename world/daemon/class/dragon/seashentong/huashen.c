#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 80 )
                return notify_fail("你的法力不足了，不法使用化身！\n");

        if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神无法集中！\n");
        message_vision(HIC"$N忽然大喝一声，将腰躬了躬，身子抖了几抖，便欲化身而去……\n"NOR, me);

   if(me->is_fighting() ) {
   if(random((int)me->query("max_mana")+10) >((int)target->query("max_mana")+10)/2) {

message_vision(HIC"只听得一声霹雳，$N顿时化做条巨龙起在空中，又长啸一声，向东海飞去。\n"NOR, me);
me->receive_damage("sen", 80);
me->add("mana", -80);
me->move("/d/sea/yujie2");
me->start_busy(1);
   message_vision(HIC"轰隆巨响声中，一条巨龙张牙舞爪的从空而下，就地一滚化便做成个人形。\n仔细一看，居然是$N！\n"NOR,me);
   }
   else
message_vision("却为$n的法力所困，脱不得身。\n", me, target);
me->receive_damage("sen", 40);
me->add("mana", -40);
   }
   if(!me->is_fighting() ){

message_vision(HIC"只听得一声霹雳，$N顿时化做条巨龙起在空中，又长啸一声，向东海飞去。\n"NOR, me);
   me->receive_damage("sen", 80);
   me->add("mana", -80);
   me->move("/d/sea/yujie2");
   message_vision(HIC"轰隆巨响声中，一条巨龙张牙舞爪的从空而下，就地一滚化便做成个人形。\n仔细一看，居然是$N！\n"NOR,me);
   me->start_busy(1);
   }
        return 5+random(5);
}

