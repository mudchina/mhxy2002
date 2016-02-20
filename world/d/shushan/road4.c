//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","村路");
  set ("long", @LONG

这条路上就没什么人了，西南方就是村头了。东边有一座小庙，不过
从外面看就是破旧不堪的了。
LONG);

  set("outdoors", 2);
  set("exits", ([      
 "southwest" : __DIR__"exit",
      "east" : __DIR__"pomiao",
     "north" : __DIR__"road3",
 ]));
 setup();
}






