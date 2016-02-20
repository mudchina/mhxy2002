// menpai_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("门派留言本", ({ "board" }) );
        set("location", "/u/redrain/workroom");
        set("board_id", "menpai_b");
        set("long",     "门派留言本，对自己的门派有什么意见和好的建议可以在此留言。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

