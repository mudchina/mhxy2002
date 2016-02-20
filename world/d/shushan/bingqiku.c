//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","兵器库");
	set("long", @LONG

这是兵器库，一个大架子。上面放的整整齐齐，看来这里的管家是
很认真负责的，一些人正在跟管兵器的管家说着什么。
LONG);
        set("no_fight",1);
        set("exits", ([
		"west" : __DIR__"eastway2",
         ]));
        set("objects", ([ 
        __DIR__"npc/lingyunzi" : 1,
        __DIR__"npc/guanjia" : 1,
        "/d/obj/weapon/sword/qingfeng" :1,
        "/d/obj/weapon/sword/qinghong" :1,
         ]));

       setup();
}

