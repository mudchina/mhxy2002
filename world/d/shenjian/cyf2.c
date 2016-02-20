// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "上山路");
        set("long", @LONG
转过弯弯曲曲的山路走到这里已经到了尽头，西面一阵阵强烈
的湖风扑过来，眼前的绿水湖是那么的广阔，那么的清澈。北面的
峭壁被一根跟臂粗的曼藤缠绕着直上云雾，东边被大片的树林挡的
严严实实。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"cyf3",
]));
        set("item_desc", ([
      		"北面": "峭壁虽然直上云霄，但顺着曼藤，似乎可以试着爬(climb)上去。\n",
      		"峭壁": "峭壁虽然直上云霄，但顺着曼藤，似乎可以试着爬(climb)上去。\n",
      		"up": "峭壁虽然直上云霄，但顺着曼藤，似乎可以试着爬(climb)上去。\n",
        ]) );
         set("coor/x",-1025);

	set("coor/y",55);

	set("coor/z",20);
set("no_magic",1);
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "峭壁" || arg == "北面" || arg == "up")
        {
        me = this_player();
        message_vision("$N抓着曼藤慢慢地往峭壁上面爬去。\n", me);
        me->move(__DIR__"cyfd.c");
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}

