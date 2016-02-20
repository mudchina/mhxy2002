// Room: /u/gua/sleep.c

inherit ROOM;

void create()
{
	set("short", "ｅ夜情");
	set("long", @LONG
这里是南瓜专门用来偷情用的地方 嘿嘿 你很魅力吧？
一般人想进来还 南瓜还不让他近呢 你一定很有魅力!
但是一旦进来了....就别想带着清白出去 sigh
习惯就好了 就从来他吧 snicker。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"workroom",
]));
  set("no_fight", 1);
        set("if_bed",1); 
  set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
