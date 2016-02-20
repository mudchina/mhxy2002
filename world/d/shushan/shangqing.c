//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","上清宫");
  set ("long", @LONG

这是蜀山剑圣修炼的地方，中央有一个香炉，香气充满了
整个房间。
LONG);
   set("exits", ([      
       "south" : __DIR__"zushi",
  ]));
   set("objects", ([ 
      __DIR__"npc/jiansheng" : 1,
      __DIR__"npc/jiantong" : 2,
       ]));
  setup();
}









