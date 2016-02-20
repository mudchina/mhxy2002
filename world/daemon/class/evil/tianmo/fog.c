//created by ken
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("想跑?没门！\n");
        if( me->query("mana") < 1000 )
                return notify_fail("你的法力不足,跑不了！\n");
        if( me->query("max_mana") < 1000 )
                return notify_fail("你的法力还不高，不能随便招魔神！\n");
        if( me->query("force") < 1000 )
                return notify_fail("你的内力不足，不能随便招魔神！\n");
        if( me->query("max_force") < 1000 )
                return notify_fail("你的内力不足，不能随便招魔神！\n");
        if( me->query("sen") <= 700 )
                return notify_fail("你的精力不足，还是别念咒了！\n");
        if( me->is_ghost())
                return notify_fail("做了鬼就老实点吧！\n");     
        if((int) me->query_skill("tianmo",1) < 180)
                return notify_fail("你的天魔大法还不够熟练，还是不念咒好了！");
        if( target )
                return notify_fail("你只能对自己念咒！\n");
        write("你要御龙到哪一个人身边？");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        object ob;

        if( !name || name=="" ) {
                write("中止念咒。\n");
                return;
        }

        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)
        || !ob->query("max_force") || !ob->query("force")) {
                write("你无法感受到这个人的内力 ....\n");
                write("你要跑那儿去？");
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        if( me->is_fighting() ) {
                write("战斗中不能跑！\n");
                return;
        } else if( me->query("max_mana") < 1000 ) {
                write("你的能量不够了！\n");
                return;
        }
        me->add("force",-1000);
        me->add("mana", -1000);
        me->receive_damage("sen", 200);
        
        message_vision( MAG "$N大喝一声：天魔何在！\n" NOR, me);
        if( random(me->query_skill("spells")) < (int)ob->query("mana") / 300 ) {
                write("呼唤毫无效果，可能是你运气不好。\n");
                return;
        }
        if( random(50) > 
        (int)(me->query_skill("tianmo",1))){
                write("呼唤毫无效果，可能是你命太坏。\n");
                return;
        }
        if(environment(ob)->query("no_fight")) {
              write("那里你去不了！\n");
              return;
        }
        if(environment(ob)->query("no_magic")) {
              write("那里你不能去！\n");
              return;
        }                message( "vision", MAG "\n半空中申出一只巨手把" + me->name() + "，抓起，然后就不见了！\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        me->start_busy(10);
        message( "vision", HIY "\n你的上空中突然出现一只巨掌，一把将"+me->name()+"丢了下来。\n\n" NOR,
                environment(ob), ({ me }) );
}
