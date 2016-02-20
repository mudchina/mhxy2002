// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

    这是一条弯弯曲曲的小路，往西望去可以隐隐看到一座烟
雾缭绕的大山。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/qujing/baigudong/sroad",
   "southeast"  : "/d/qujing/village/road4",
]));

  setup();
}






