// by cih 10/01/2002
// Room: /d/kaifeng/zhu2

inherit ROOM;

void create ()
{
  set ("short", "香路");
  set ("long", @LONG

这里就上所谓的香路的尽头了。这一路行来，饱览湖光的同时，
香路上还种满了玫瑰，看来八戒也是个罗曼蒂克的人哦。。。
不过看看那个低矮的围墙，好像只要会点什么庄稼把势的人都
可以轻而易举的翻过去似的(climb)

LONG);

  set("exits", ([
  "northeast" : __DIR__"zhu1",
      ]));

  set("outdoors", "kaifeng");

  setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{       object me;
        me=this_player();

        if ( !arg || ((arg != "wall") ))
                return notify_fail("你要爬什么？\n");
        else
                message_vision("$N一扒墙头，翻了过去。\n", me);
                me->move("/d/kaifeng/donghu8");
                me->set_temp("apply/dodge",0);
                me->set_temp("ride/dodge",0);
                tell_room( environment(me), "「咕咚」一声，" + me->name() + "从墙头上摔了下来！\n",
({me}) );
                return 1;
}


