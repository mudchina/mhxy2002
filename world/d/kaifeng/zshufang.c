// Room: /u/mimi/zhuziguo/prince_shufang.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "书房");
  set ("long", @LONG

房间三面都是书架，上面摆满了书，大多都是爱情与佛学方面的书。
房中央有一张红木的书桌，桌后的太师椅上照样挂着一张猪头像，
画的非常的传神。听说是某年某月一位大师给八哥画的。后来这就
成了天蓬府的标记了。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "northwest" : __DIR__"neitang",
  ]));

  setup();
}
