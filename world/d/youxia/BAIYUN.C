// created 17-06-2001 海上飘(piao)

inherit ROOM;
void create()
{
        set("short", "阴暗石巷");
        set("long", @LONG
石巷散发着一种奇怪的霉腐味道，又加杂着一丝血腥和干
净宽敞的东云大路格格不入，一条又脏又臭的小河沟顺着巷侧
缓缓流淌，上面还漂着染满着黑血的绷带。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/kaifeng/east1",
  "north" : __DIR__"stone2",
]));
        set("objects", ([
        __DIR__"npc/shaolong": 1,
        __DIR__"npc/scavenger": 1,

			]) );

        set("outdoors", "fengyun");
        set("coor/x",10);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
