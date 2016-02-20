//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","村路");
  set ("long", @LONG

这条路上只有几个小童在跑来跑去，互相嬉闹着。路边柳条拂地，时
见野花，几只小鸡小鸭踱来踱去。一条野狗摇着尾巴跑了过来，闻了
闻，又跑了开去。西面是一家很简陋的民居。
LONG);

  set("outdoors", 2);
  set("exits", ([      
 "northeast" : __DIR__"road2",
      "west" : __DIR__"minju",
     "south" : __DIR__"road4",
 ]));
 setup();
}






