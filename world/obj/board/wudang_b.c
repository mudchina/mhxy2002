//By tianlin@mhxy for 2001.9.27
//部分优化

inherit BULLETIN_BOARD;

void create()
{
        set_name("武当弟子留言板", ({ "board" }) );
        set("location", "/d/wudang1/sanqingdian");
        set("board_id", "wudang_b");
	 set("long", "这是一个供武当门下交流的留言板。\n");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

