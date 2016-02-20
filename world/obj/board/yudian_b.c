
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
              set_name("雨点的"+HIW+"风雪"+NOR+"留言板", ({ "board" }) );
            set("location", "/u/yudian/workroom");
            set("board_id", "yudian_b");
            set("long",     "如果主人不在家，请您留言，谢谢！\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
