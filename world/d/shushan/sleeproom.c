//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","卧房");
  set ("long", @LONG

很简朴的房间，三面是书架, 上面摆满了杂七杂八的书，
墙边有一张牙玉色的软榻(bed)。
LONG);

  set("no_fight", 1);
  set("item_desc", ([
  "bed" : "一张牙玉色的软榻，塌四周雕着竹叶格，看上去极为精致(gosleep,gobed,bed)。 
",
]));
  set("exits", ([
  "east" : __DIR__"midao0",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
        me->move(__DIR__"bed");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}


