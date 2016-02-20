// link
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"草坪"NOR);
        set("long", @LONG
这里是灵界圣殿前一片翠绿的草坪，草坪上栽种着几棵不知名的热带
植物，散乱的放着几块石头，不过可惜因为常有人来坐，早已脏得很
了。你最好不要坐上去。草地上还停着几只小鸟，也许已经麻木了吧，
它们并不怕人。
LONG
        );
	set("valid_startroom",1);
        set("exits", ([ 
  "west" : __DIR__"shengdian0",
  "north" : __DIR__"swimrm",
  "up" : __DIR__"shengdian1",
  "out":__DIR__"rukou"
]));
        set("objects", ([
        __DIR__"npc/bird" : 1,
                        ]) );

	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}