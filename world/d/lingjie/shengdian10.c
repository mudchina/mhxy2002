#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", MAG"圣殿顶层"NOR);
        set("long", @LONG
看到头了,你高兴的跳了起来。可仔细看来，并没有
什么特别之处，只是有一位老人一副闭目养神的样子
做在那里。
LONG
        );
        set("exits", ([
                "down" : __DIR__"shengdian9",
        ]) );
        set("objects", ([
"/d/lingjie/obj/baiyu.c":1,
    __DIR__"npc/baye":1,
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}




