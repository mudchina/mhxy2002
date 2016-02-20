//shushan by yushu 2000.11
inherit ROOM;
void create ()
{
  set ("short","密道");
  set ("long", @LONG

这里是蜀山派的密道，这里四面都是云彩，但你看不到天空。
脚下都是雾，如仙境一般。你不知道如何是好，只好往前
继续走。
LONG);

  set("exits", ([
  "north" : __DIR__"midao0",
    ]));
     set("no_fight", 1);
     set("no_magic", 1);
     set("no_get", 1);
     setup();
}
