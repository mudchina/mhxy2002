inherit ROOM;

void create()
{
  set ("short", "掌门休息室");
  set ("long", @LONG

一间不太大的房间,只见一个人直挺挺的站在那里,他便是灵界
现任的掌门了。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"shengdian0",

]));
set("objects", ([
                __DIR__"npc/zhangmen": 1,
		
]) );
        set("no_clean_up", 0);
	set("outdoors", 0);
        setup();
}



