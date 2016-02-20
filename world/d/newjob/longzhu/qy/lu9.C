// 灵月小路 by Calvin


inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

灵月仙界是传说中的仙界,可是这崎岖的山路怎么也
让人不敢相信那的地方会有多么的美丽。

LONG);

  set("exits", ([
        "west"  : __DIR__"lu8",
        "east"  : __DIR__"lu9",
      ]));

  set("outdoors","1");

  setup();
}

int valid_leave (object who, string dir)
{
  if (who->query("combat_exp") < 200000 ||
      random(2))
  {
    if (! who->query_temp("fainted_yedu"))
    {
      message_vision ("一阵腥风吹来，$N顿时头重脚轻。\n",who);
      who->set_temp("fainted_yedu",1);
      remove_call_out ("fall_down");
      call_out ("fall_down",1,who,environment(who));
      who->start_busy(1,1);
      return notify_fail("你禁不住踉跄了几下，两腿突然一软。\n");
    }
  }
  who->set_temp("fainted_yedu",0);
  return 1;
}

void fall_down (object who, object where)
{
  who->move(where);
  who->unconcious();
}
