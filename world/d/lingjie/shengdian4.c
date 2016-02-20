#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"圣殿四层"NOR);
        set("long", @LONG
地方突然变大了许多,真没想到这里还有如此整洁的地方,每
一寸地方都是有人细心打扫过的,望里面望去,却雾蒙蒙的,
什么也看不清。还是进去吧！向上走，又是圣殿的高层了，
真搞不懂，设计这里的人是怎么想的。
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian5",
                "down" : __DIR__"shengdian3",
                "enter" : __DIR__"zoulang",
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}
