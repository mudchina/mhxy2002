//Cracked by Roath
// idle_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("笑话书柜", ({ "board" }) );
	set("location", "/d/city/misc/lqbz");
	set("board_id", "xiaohua_b");
	set("long",
		"这是一个笑话的书柜。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
