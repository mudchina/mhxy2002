//Cracked by Roath
// idle_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("意见流言板", ({ "board" }) );
        set("location", "/d/city/misc/advise");	
       set("board_id", "idle_b");
	set("long",	"这是一个供玩家给本MUD提意见的流言板。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
