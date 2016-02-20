// Room: /u/linger/workroom.c

inherit ROOM;

void create()
{
set("short", "女王府");;
	set("long", @LONG

你的眼前一黑，接着什么也不知道了．．．
慢慢地你终于又有了知觉．．．
你站在一个飘满玫瑰花瓣的浴盆里...
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "up" : "/u/valen/workroom",
  "down" : "/d/city/kezhan",
  "wiz" : "/d/wiz/wizroom",
  "tianlin" : "/u/tianlin/workroom",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
