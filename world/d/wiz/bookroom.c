//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
          set ("short",HIG "新书斋" NOR);
        set ("long", @LONG

这是三联书局的新书屋，存放了孔方兄新搞来的几本秘籍。
据说价值可是不斐哦！
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                  "out" : __DIR__"zoulang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                    __DIR__"npc/seller" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


