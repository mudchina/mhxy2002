//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "¶«Ïá×ßÀÈ");
        set("long", @LONG
Äã×ßÔÚÒ»Ìõ×ßÀÈÉÏ£¬¶«±ßÓĞ¼¸¼äÑÅÊÒ£¬ÈËÀ´ÈËÍùºÜÈÈÄÖ¡£Î÷±ßÊÇ´óµî¡£
LONG );
        set("exits", ([
                "east" : __DIR__"donglang2",
                "west" : __DIR__"sanqingdian",
        ]));
        set("objects", ([
                __DIR__"npc/xi" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "Îäµ±ÅÉ") && dir == "east" &&
                objectp(present("zhang songxi", environment(me))))
           return notify_fail("ÕÅËÉÏªºÈµÀ£ºÄã²»ÊÇÎäµ±µÜ×Ó£¬²»µÃÈëÄÚ¡£\n");

        return ::valid_leave(me, dir);
}
