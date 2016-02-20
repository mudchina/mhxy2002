// shutdown.c
//by tianlin@Mhxy for 2002.3.10,修改和login作揖搭配
#include <net/daemons.h>//这里是调用版本,比如MUD_NAME定义等 
#include <ansi.h>//这里是调用颜色代码
#include <command.h>//这里是调用include下的command.h定义
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;

	if( me->query("id") != "tianlin") //这里限制id.谁使用.这里我限制了tianlin.就是只能tianlin使用
       return notify_fail("目前系统只能由tianlin启动。\n");

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");

	message( "system","对不起，游戏重新启动，请稍候一分钟再连入梦幻西游。\n"NOR, users() );
	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}
	log_file("static/CRASHES","“ "+BLU+ me->query("name")+NOR+HIY" <"+me->query("id")+">"+NOR"”重新启动《"+MUD_NAME+"》于："
		+BJTIME_CMD->chinese_time(1,time()) + "\n");
	write_file("/log/static/shutdown",""+HIY+me->query("name")+NOR+"("+HIB+me->query("id")+NOR+") "HIC"shutdown "NOR+WHT+MUD_NAME+"于:"
		+ BJTIME_CMD->chinese_time(1,time()) + "\n", 1);//这里是调用bjtime里面的chinese_time使用1
	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();//查找dns_master并且关闭
	shutdown(0);
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: shutdown
 
马上重新启动游戏。
 
HELP
);
        return 1;
}
 
