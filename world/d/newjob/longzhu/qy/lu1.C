// 灵月小路 by Calvin

inherit ROOM;

void create()
{
  set ("short", "灵月小路");
  set ("long", @LONG

灵月仙界是传说中的仙界,可是这崎岖的山路怎么也
让人不敢相信那的地方会有多么的美丽。

LONG);

  set("exits", ([ 
    "west" : __DIR__"lu2",
    "east" : __DIR__"lu7",
  ]));

  set("outdoors", __DIR__"");

  setup();
}
void init ()
{
  add_action ("do_climb","climb");
  add_action ("do_jump","jump");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N攀着一块大石奋力向上爬去。\n",who);
  message_vision ("$N手一松连人带石哗啦一声滑了下来。\n",who);
  who->unconcious();
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();

  message_vision ("$N鼓足勇气往下跳去。\n",who);
  message_vision ("$N砰地重重摔在台下。\n",who);
  who->unconcious();
  return 1;
}