inherit BULLETIN_BOARD;
void create()
{
        set_name("天魔台", ({ "board" }) );
        set("location", "/d/mojiao/dating4.c");
        set("board_id", "mj_b");
        set("long", "这是一个高九尺，盘着九条火龙的天台。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
