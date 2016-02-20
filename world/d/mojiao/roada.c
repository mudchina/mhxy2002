inherit ROOM;
int do_jump(string arg);
void create ()
{
  set ("short", "后厅");
  set ("long", @LONG

这里是后厅．室内装饰典雅，一看就晓得是专门接待贵宾的
地方，不过在地板上却有一个小小洞(hole).

LONG);

  set("exits", ([
        "south" : __DIR__"dating4",
      ]));
  set("item_desc", ([ /* sizeof() == 2 */
          "hole": "
一个非常小的眼，从洞眼里隐隐约约能闻到些许硫磺的味道。\n",
]));

  setup();
}

void init()
{
  add_action("do_jump", "zuan");
  add_action("do_jump", "xiaqu");
}
int do_jump(string arg)
{
  object me=this_player();
  int myeffcor=me->query("cor");
  int mycor=me->query_cor();

  if ( !arg || ((arg !="hole") ))
    return notify_fail("你到那里去？ \n");
if(myeffcor<18)
    return notify_fail("你看见那么小的眼，不由叹了口气。 \n");

  message_vision("$N念了几句咒语,变成了一只蚊子,飞了进去。\n", me);
  me->move(__DIR__"huomigong/entrance");
  message_vision("$N嗡嗡嗡的飞了过来,又变回了原形。\n", me);
  return 1;
}
