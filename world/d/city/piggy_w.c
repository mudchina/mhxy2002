inherit __DIR__"piggy_two.c";
#include <ansi.h>
void create()
{
    ::create();
    set ("short","Ë«ÈË¹°Öí·¿");
    set("exits", ([
        "east": __DIR__"club3",
    ]) );
}
