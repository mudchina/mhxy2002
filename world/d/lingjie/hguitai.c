// link
inherit ROOM;
void create()
{
        set("short", "柜台后");
        set("long", @LONG
这里就是麦当劳餐厅的柜台后了，人们都忙忙碌碌，如果你问服务员总管
要到了工作，不妨问这里的服务员要盘子，拿到东边的厨房里洗。
LONG
        );
	set("valid_startroom",1);
        set("exits", ([ /* sizeof() == 4 */
//  "east" : __DIR__"chufang2",
  "south" : __DIR__"mdc",
]));
	set("objects", ([
		__DIR__"npc/fuwu4" : 1,
	]));
	set("coor/x",-40);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
