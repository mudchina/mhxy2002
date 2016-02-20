
// reboot.c

#include <net/daemons.h>
#include <mudlib.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help (object me);
int main(object me, string arg)
{
	int time;
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");
	if(!arg) {
		write(CHINESE_MUD_NAME + "目前距离重新启动还有"HIR+chinese_number(AUTOBOOT_D->query_time())+ NOR"分钟。\n");
		return help(me);
	}
	if(!sscanf(arg,"%d",time)) return help(me);
	if(time<3) return notify_fail("至少三分钟重新启动。\n");

	message( "system", HIR"注意！游戏"+chinese_number(time)+"分钟后重新启动。\n"NOR, users() );
	AUTOBOOT_D->set_time(time);

	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: reboot 分钟数
 
X分钟后重新起动游戏。
 
HELP
);
        return 1;
}
 

