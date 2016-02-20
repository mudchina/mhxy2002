inherit __DIR__"piggy.c";
#include <ansi.h>

void create()
{
    ::create();

    set ("short","¹°ÖíÄÏ·¿");
    set("exits", ([
        "north": __DIR__"club3",
    ]) );
}
