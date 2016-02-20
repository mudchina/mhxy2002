//door.c by yushu 2000.11
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short",HIR "「"HIY "山门" HIR "」" NOR);
  set ("long", @LONG
这里是蜀山派派前的山门，整个山门前由大块的青石铺成，极为
平坦。但因年代久远，都有些破损。丛丛小草从石板的缝隙中长
了出来。广场周围都是密密的松树林，四角上各放了几块石碑，
字迹都甚为模糊。正前方黄墙碧瓦，飞檐翘檩，正中一道二丈来
宽，三丈来高的朱红杉木包铜大门(door)。上方一块大匾，龙飞
凤舞地书着『蜀山派』三个大字。门前三三两两的站着几个弟子。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 3 */
  "enter" : "/d/shushan/xiaoyuan",
  "south" : "/d/shushan/shushan4",
  ]));
    set("objects", 
        ([ //sizeof() == 1
               "d/shushan/npc/dizi" : 2,
               "d/shushan/npc/dizi1" : 2,
    ]));
 
create_door("enter", "大门", "out", DOOR_CLOSED);
set("valid_startroom", 1);
setup();

}

