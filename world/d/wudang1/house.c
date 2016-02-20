//Room: house.c
//Date: Feb.12 1998 By Jave

inherit ROOM;

void create()
{
        set("short", "小土屋");
        set("long", @LONG
这是一间小土屋，看样子是一户农家的房子。屋里简单地摆着些家具，墙
角里堆着些农具。炕上坐着一个老婆婆和一个小孩，见有人冲进来，都神色紧
张地望着你。
LONG);
        set("exits", ([
            "north"      : __DIR__"wdroad6",
        ]));
        set("objects", ([
            "/d/wudang1/npc/oldwoman" :1,
            "/d/wudang1/npc/kid" :1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


