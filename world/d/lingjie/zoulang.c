inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"走廊"NOR);
        set("long", @LONG
这里是圣殿四层的走廊,不大不小的走廊贯通东西,走廊中的
石栏都是汉白玉雕做的,非常的精细,手模上去有一种说不出
的舒服。
LONG
        );
        set("exits", ([
                "west" : __DIR__"wangroom1",
                "east" : __DIR__"wangroom2",
                "out" : __DIR__"shengdian4",
                "south" : __DIR__"bedroom1",
        ]) );
                 set("objects", ([
                __DIR__"npc/shadow":1,
                
        ]) );

        set("no_fight",1);
       set("no_sleep", 1);
       set("no_magic", 1);


        setup();
        replace_program(ROOM);
}
