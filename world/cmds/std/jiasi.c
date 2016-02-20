// jiasi.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
//	if(me->query("class") != "bandit")
//		return notify_fail("名门正派的人不可以装死！\n");
        seteuid(getuid());
        if( !me->is_fighting() )
                return notify_fail("你不在战斗中，不需要假装死。\n");
	wimpy = (int)me->query("env/wimpy");
	message_vision("$N惨叫一声，一头栽倒在地下。\n$N死了。\n",me);
	me->set_temp("disable_inputs",1);
	me->set_temp("block_msg/all",1);
	me->disable_player(HIG "<假死中>" NOR);
        me->remove_all_killer();
	me->remove_all_enemy();
	me->delete("env/wimpy");
        me->start_call_out( (: call_other, __FILE__, "remove_jiasi", me, wimpy :), 
random(80 - (int) me->query_con()));
	return 1;
}

void remove_jiasi(object me, int wimpy)
{
	me->delete_temp("disable_inputs");
	me->enable_player();
	me->delete_temp("block_msg/all");
	me->set("env/wimpy",wimpy);
   	message_vision("$N在地上悄悄地翻了个身，小心翼翼地睁开了眼。\n",me);
	me->move(environment(me),1);

}

int help(object me)
{
        write(@HELP
指令格式 : jiasi
让你在战斗中装死，创造逃生的机会。
名门正派的人不可以装死。

HELP
        );
        return 1;
}
 
