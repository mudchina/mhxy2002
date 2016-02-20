#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"圣殿二层"NOR);
        set("long", @LONG
来到这里的人已经很少了,可以从这里进到圣殿二
层的里面。里面便是供大家休息的睡房了，再向
上走就是圣殿的更高层。
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian3",
                "down" : __DIR__"shengdian1",
                "enter" : __DIR__"bedroom",
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}


