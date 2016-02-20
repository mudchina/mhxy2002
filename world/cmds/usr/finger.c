// finger.c
#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if( !arg ) {
		if( (int)me->query("sen") < 50 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) )
			me->receive_damage("sen", 50);
		me->start_more( FINGER_D->finger_all() );
//		write( FINGER_D->finger_all() );
    } else if (arg == "lei" || arg == "tianlin") {   
        if( (int)me->query("sen") < 15 ) 
            return notify_fail("你的精神无法集中。\n");
        write( FINGER_D->tianlin_finger_user(arg) );
    } else {
	    // mon 9/1/98 the following chars will cause an error.
	    arg=replace_string(arg,"#"," ");
	    arg=replace_string(arg,"."," ");

		if( (int)me->query("sen") < 15 )
			return notify_fail("你的精神无法集中。\n");
	if( time()-(int)me->query_temp("finger_end") < 1&& !wizardp(me) )
                return notify_fail("你不能连续finger ID！\n");
		if( !wizardp(me) )
			me->receive_damage("sen", 15);
		write( FINGER_D->finger_user(arg) );
		          me->set_temp("finger_end",time());
}
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式： finger
           finger [使用者英文代号]
           finger [使用者英文代号]@Mudname
 
这个指令，如果没有指定使用者姓名，会显示出所有正在线上玩家
的连线资料。反之，则可显示有关某个玩家的连线，权限等资料。
 
see also : who, mudlist
HELP
    );
    return 1;
}
 
