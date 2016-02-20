// Room: /d/death/room10.c

inherit ROOM;

void create()
{
	set("short", "索命勾魂");
	set("long", @LONG
这就是索命鬼的住处了，没啥好看的。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/suoming" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"naiheqiao",
]));

	setup();
	replace_program(ROOM);
}
