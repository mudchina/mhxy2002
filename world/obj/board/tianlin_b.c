//by tianlin 2001.5.1
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
              set_name("田林的"+HIY+"拳皇"+NOR+"留言板", ({ "board" }) );
            set("location", "/u/tianlin/workroom");
            set("board_id", "tianlin_b");
            set("long",     "如果主人不在家，请您留言，谢谢！\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
