//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","½ûµØ");
	set ("long", @LONG
        [1;31mÊñÉ½½ûµØ  ÉÆ´³ÕßËÀ[2;37;0m
LONG);

	set("exits", ([     
        "west" : __DIR__"jby",
        "east" : "d/shushan/zhenyaota/tower",
	]));
       set("objects", ([         
         __DIR__"npc/shouhu" : 1,
        __DIR__"npc/shouhu1" : 1,
       ]));
  
       setup();
}
int valid_leave(object me, string dir)
{
    if ( dir == "east" ) {
        if(objectp(present("shouwei dizi", environment(me))))
            return
notify_fail("ÊñÉ½µÜ×ÓÒ»¸ö¼ı²½ÉÁµ½ÄãÇ°Ãæ£¬º°µÀ£ºÄÄÀï×ß£¡\n");
    }
    return ::valid_leave(me, dir);
}
