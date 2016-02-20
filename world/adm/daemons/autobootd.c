
// autobootd.c
// file:                Auto reboot 
// creator:    arrow 
// date:                2000-12-5

// for auto reboot for 刀剑如梦
#include <ansi.h>
#include <net/daemons.h>
#include <mudlib.h>
//autoboot at 7:30
#define REBOOT_TIME 7.5

inherit F_DBASE;

static int last_time=1440;//24 hours,60*24 minute

int query_time()
{
	return last_time;
}
void set_time(int time)
{
	last_time=time;
}
void pass_time()
{
	if(last_time>0) last_time-=1;
}
void auto_boot();

void create()
{
	mixed *local;
	int t,r;
        seteuid(ROOT_UID);
        set("channel_id", "系统精灵");
        CHANNEL_D->do_channel( this_object(), "sys", CHINESE_MUD_NAME+"自动重起系统已经启动。\n");
#ifdef REBOOT_TIME
	local=localtime(time());
	t=local[2]*60+local[1];
	r=1440+REBOOT_TIME*60-t;
	r%=1440;
	set_time(r);
#endif
        call_out("auto_boot", 60);
}

void auto_boot()
{
        int i,mem,last;
        object *ob, link_ob;
        string id;

	pass_time();
	last=query_time();
	if(last>0 && last<10)
		message("channel:chat", HIR"【系统】"+CHINESE_MUD_NAME+chinese_number(last)+"分钟后将重新启动。\n"NOR,users());
	
	if(last>0)
	{
        remove_call_out("auto_boot");
        call_out("auto_boot", 60);
	return;
	}

//do autoboot

        seteuid(getuid());
        ob=users();
        i=sizeof(ob);
        reclaim_objects();
        for( i=0;i<sizeof(ob);i++) {
                id = (string) ob[i]->query("id");
                if (!id) continue;
                if(!environment(ob[i]) )        continue;
                if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
                if( (int)link_ob->save() && (int)ob[i]->save() )
message("channel:chat", HIR"【系统】"+CHINESE_MUD_NAME+"要重新启动了。不要紧，您的档案已经自动存盘。\n"NOR,ob[i]);
                else
message("channel:chat", HIR"【系统】"+CHINESE_MUD_NAME+"要重新启动了。您的档案已经自动存盘失败，请与巫师联系。\n"NOR,ob[i]);
        }

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
	shutdown(0);
}

