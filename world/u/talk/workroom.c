// Room: /u/gua/workroom.c

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "聊天大米的工作室");
          set("long", @LONG

祥云光满，瑞霭香浮。在这冰天雪地里居然还有如此仙境。这里正是独立
云海，傲越千山的聊天大米休息室。靠北则有一圈篱笆，围着几间精致的小屋。
往东可望见一片杏林。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj1/box" : 1,
]));
        set("exits", ([ /* sizeof() == 3 */
  "wiz" : "/d/wiz/wizroom",
  "bed" : __DIR__"sleep",
  "out" : __DIR__"damen",
  "east" : __DIR__"yaopu",
  "kz" : "/d/city/kezhan",
  "tianlin" : "/u/tianlin/workroom",
]));
	set("no_magic", 1);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "ｅ夜情(gosleep,gobed,bed)。 
",
]));
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
