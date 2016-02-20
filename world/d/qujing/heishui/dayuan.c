//EDIT BY LUCAS
inherit ROOM;
int do_open(string arg);

void create ()
{
  set ("short", "大院");
  set ("long", @LONG 
这里是黑水峪河神府的大院。几个小妖在这里磨刀霍霍，间或
嬉戏打闹。地上一大片残肢断腿，不知有多少人曾死在这里。
前面有一间小亭，倒是布置的幽雅别致。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"buyun",
  "west" : __DIR__"damen", 
  "east" : __DIR__"zoulang6",
  "south" : __DIR__"zoulang1",
]));

        set("objects", ([
                __DIR__"npc/guai" : 4,
        ])); 

        setup();
} 

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me=this_player();

        if( !arg || arg != "gate" ) {
                return notify_fail("你要打开什么?\n");
        }

        message_vision("$N把大门打开。\n",this_player());
        set("exits/west", __DIR__"damen");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
        message("vision","小妖发现大门被打开了，大吃一经，跌跌撞撞跑过来把大门关上了。\n", room);
        room->delete("exits/west");
}

