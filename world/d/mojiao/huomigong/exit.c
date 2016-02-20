
// create by qlwy 28/06/2001
// room: maojiao/exit.c

inherit ROOM;

void create ()
{
        set ("short", "迷宫出口");
        set ("long", @LONG

终于走出火迷宫了，你往南面望了望，不禁觉的
心有余辜。

LONG);
        set("exits", 
        ([ //sizeof() == 2
                  "south" : __DIR__"outhmg0", 
//                "north" : __DIR__"xxx", 用于连接
        ]));
        setup();
}
void init()
{
  add_action("do_turn", "turn");
}
int do_turn(string arg)
{
  object me=this_player();
  int myeffstr=me->query("str")+me->query_skill("unarmed", 1)/10-2;
  int mykar=me->query_kar(), diff=40-mykar, percentage;
  int mymaxkee=me->query("max_kee"), mymaxsen=me->query("max_sen");
  if ((arg != "8310" && arg != "8011") || !arg)
    return notify_fail("你要转什么？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
  if (me->query_temp("no_move")) return notify_fail("你被定住了，什么也干不了。\n");
  if (me->query_skill("tianmo", 1) > 50
   && me->query("family/family_name") == "魔教")
  {
      message_vision("天上伸下一只大手一把抓住$N，接着就不见了！\n", me);
      me->move(__DIR__"tower");
      return 1;
  }
  if (me->query_str()<40||myeffstr<20)
   {
      message_vision("$N费了九牛二虎之力也没能转动一分。\n", me);
      return 1;
   }
  if(random(diff)>4)
   {
      message_vision("突然岩缝里冒出一股岩浆，落了$N满身！\n", me);
      percentage=diff*2;
      me->receive_wound("kee", mymaxkee*percentage/100);
      return 1;
   }
  message_vision("$N大喝一声，转动了机关。\n", me);
  me->move(__DIR__"tower");
  return 1;
}


