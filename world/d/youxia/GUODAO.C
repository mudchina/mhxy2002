// created 17-06-2001 海上飘(piao)

inherit ROOM;
void create()
{
        set("short", "白玉石阶");
        set("long", @LONG
万梅山庄内更是装饰的更是豪华，走廊都被布置的别有情调
，此处不少江湖豪杰正在等候着入庄拜会庄主西门吹雪，前方便
是通向的就是白梅阁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" :__DIR__"yard",
    "north" : __DIR__"baimei",

]));
        set("objects", ([
		__DIR__"npc/xiaofeng" :1,
                        ]) );

        set("coor/x",180);
	set("coor/y",-400);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
