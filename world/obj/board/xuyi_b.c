//by tianlin 2001.8.6

inherit BULLETIN_BOARD;

void create()
{
        set_name("盱眙山留言板", ({ "board" }) );
        set("location", "/d/xuyi/nanmen.c");
        set("board_id", "xuyi_b");
        set("long", "这是一本专门给盱眙山弟子留言用的板子。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
