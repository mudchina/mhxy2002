inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
          set_name("爱后余生留言板", ({ "board" }) );
          set("location", "/u/link/workroom");
          set("board_id", "link_board");
          set("long",     "这是供爱后余生和大家互相沟通的讨论板。\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
