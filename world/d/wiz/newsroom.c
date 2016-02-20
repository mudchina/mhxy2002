#include <ansi.h>
#include <room.h>

inherit ROOM;
int block_cmd();

void create()
{
	set("short",  "梦幻西游新闻发布中心" );
	set("long", @LONG
这里是梦幻西游的新闻发布中心，有什么新闻都可以在这里发布(post)，
然后系统自动随机通知所有在线玩家。
LONG );
	set("exits", ([
           "north" : __DIR__"wizroom",
	]));
	set("objects",([
//		__DIR__"newer":1,
	]));
	set("no_clean_up", 1);
	setup();
//	replace_program(ROOM);
}
void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
       if (verb=="look") return 0;
       return 1;
}
