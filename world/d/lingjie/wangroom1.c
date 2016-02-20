inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"明王殿"NOR);
        set("long", @LONG
降世明王住的地方,一般这里不会有别人在,除了他的弟子
很少有人可以到这里来的,也许就因为这个原因,这里显得
清净了很多。
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoulang",
                
               ]) );
                 set("objects", ([
                __DIR__"npc/mingwang1":1,
        ]) );

        set("no_fight",1);
       set("no_sleep", 1);
       set("no_magic", 1);


        setup();
        replace_program(ROOM);
}
