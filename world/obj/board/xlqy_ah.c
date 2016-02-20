
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name("梦幻西游发展讨论板", ({ "board" }) );
           set("location", "/d/wiz/entrance");
             set("board_id", "xlqy_ah");
set("long",     "这是供巫师和玩家互相交流，共同促进梦幻西游发展的讨论板。\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
