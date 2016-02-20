// uptime.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <mudlib.h>
#include <ansi.h>

inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
	int l, t, d, h, m, s;
	string time;

	l = AUTOBOOT_D->query_time();
	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	if(l>=60)
		write(CHINESE_MUD_NAME + "已经执行了" + time + "。\n");
	else 
		write(CHINESE_MUD_NAME + "已经执行了" + time +"，目前距离重新启动还有"HIR+chinese_number(l)+ NOR"分钟。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : uptime
 
这个指令告诉您「梦幻西游」泥巴游戏已经连续执行了多久.
 
HELP
    );
    return 1;
}
