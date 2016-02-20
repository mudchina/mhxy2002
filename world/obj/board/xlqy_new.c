
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name("仙侣情缘发展讨论板", ({ "board" }) );
           set("location", "/d/wiz/entrance");
          set("long",     "这是供巫师和玩家互相交流，共同促进仙侣情缘发展的讨论板。\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
