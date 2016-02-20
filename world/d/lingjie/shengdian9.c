#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"圣殿九层"NOR);
        set("long", @LONG
好不容易走到了这里,总算可以歇歇脚了,周围一片华丽
的景象,奇怪!那里有一只奇怪的动物挡住了继续前进的
路口,看来又少不了一场恶战了。
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian10",
                "down" : __DIR__"shengdian8",
                "enter" : __DIR__"tree",
        ]) );
        set("objects", ([
                __DIR__"npc/miaosi":1,
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{       
        object a;
//        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("miaosi", environment(me))) && living(a) )
                return notify_fail("妙思不屑的看了你一眼：算了吧,何必找死呢！\n");

        return ::valid_leave(me, dir);
        }

        return 1;
}

