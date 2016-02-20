// xiuxishi.c by yushu.2000.11
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIR "「" HIY "卧室" HIR "」" NOR);
	set("long", @LONG

这里是蜀山派内的休息室，屋子有点点旧，但是打扫的非常干净，一排
床铺靠墙摆着，东面过去也是一间休息室，不断的有人进来休息或醒后
离去，你悄悄的找个空铺睡了下来。
LONG
	);
        set("exits", ([
	         "west" : __DIR__"xiuxishi",
	  ]));

       set("sleep_room",1);  
       setup();
	replace_program(ROOM);
}

