inherit BULLETIN_BOARD;

void create()
{
  set_name("水陆大会留言簿", ({"board"}) );
  set("location", "/d/kaifeng/gate");
  set("board_id", "sldh_b");
  set("capacity", 100);
  set("long", "水陆大会的留言簿，供巫师通知和玩家报名交流用。\n");
  setup();
  replace_program(BULLETIN_BOARD);
}

