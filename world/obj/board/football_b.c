inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
          set_name("中国队"+HIW+"十强赛"+NOR+"留言板", ({ "board" }) );
          set("location", "/d/city/zhuque-s1");
          set("board_id", "football_board");
          set("long",     "中国第七次冲击世界杯，加油，中国！\n" );
        setup();
          set("capacity", 1000);
        replace_program(BULLETIN_BOARD);
}
