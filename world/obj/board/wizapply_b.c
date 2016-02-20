// wiz_apply

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIR"…Í«Î≤æ"NOR, ({ "wiz_apply" }) );
        set("location", "/d/wiz/apply_room");
        set("board_id", "wiz_apply");
        set("long", "…Í«ÎŒ◊ ¶¡Ù—‘±æ°£\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

