//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","睡房");
	set("long", @LONG

这里是蜀山剑派内的睡房，屋子有点旧，但是打扫的非常干净，
一排床铺靠墙摆着,不断的有人进来休息或醒后离去，你悄悄的
找个空铺睡了下来。
LONG);
        set("exits", ([
	     "east" : __DIR__"westway3",
        ]));

       set("sleep_room",1);  
       setup();
}

