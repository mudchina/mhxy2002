// created 17-06-2001 海上飘(piao)

inherit ROOM;
void create()
{
        set("short", "万梅山庄");
        set("long", @LONG
这里就是江湖盛传的万梅山庄，此地景色迷人，一年四季
处处可见千姿百态的梅花，万梅山庄的庄主既是西门吹雪，每
天还有好多江湖豪杰前来拜会他，偶尔不乏可以看到江湖中赫
赫有名的大人物。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" :"/d/changan/seashore2",
    "north" : __DIR__"road",

]));
        set("objects", ([
                __DIR__"npc/yingke" :1,
                        ]) );
  set("outdoors", 1);
        set("coor/x",180);
	set("coor/y",-400);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
