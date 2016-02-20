#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"圣殿三层"NOR);
        set("long", @LONG
灵界管理处就在这层了,并且还有些其他的建筑,其实
也没什么好说的了。再向上走就是圣殿的更高层。
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian4",
                "down" : __DIR__"shengdian2",
                "enter" : __DIR__"guanli",
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}
