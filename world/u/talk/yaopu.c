//by tianlin 2001.8.14修改药铺不能战斗.

inherit ROOM;
#include <ansi.h>
void create ()
{
       set ("short","聊天大米娛樂室" );
        set ("long", @LONG

這是聊天大米用來消遣娛樂的地方。這裡佈滿了各種遊戲機，還有很多
還有很多各式各樣用來消遣娛樂的東西。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"workroom",
        ]));
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/girl" : 1,
        ]));
  set("no_fight", 1);
  set("no_magic", 1);

//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


