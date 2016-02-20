// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//
inherit SSERVER;
#include <ansi.h>;
int cast(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
        if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神无法集中！\n");
message_vision(HIR"$N默运火魔心法,体内真气转烈,忽地脸色通红,张口喷出一团烈火！\n"NOR, me);
   if(me->is_fighting() ) {
     if(random((int)me->query("max_mana")) >
(int)target->query("max_mana")/2) {

message_vision(HIR"$N借着烈火,化身一朵红云,飘身向西方遁去。。。\n"NOR, me);
me->receive_damage("sen", 100);
me->move("/d/city/kezhan");
   }
   else
message_vision(HIY"$N刚想变化，那火忽地又自行熄了!!\n"NOR, me, target);
me->receive_damage("sen", 100);
   }
   if(!me->is_fighting() ){
message_vision(HIR"$N借着烈火,化身一朵红云,飘身向西方遁去。。。\n"NOR, me);
   me->receive_damage("sen", 100);
   me->move("/d/city/kezhan");
   }
//        me->start_busy(1+random(2));
        return 5+random(5);
}

