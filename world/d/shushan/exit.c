//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","小村口");
  set ("long", @LONG

这里就是乌鸦嘴村头了。西边是一条曲折的小路，一般村人很少再往
西面去了，只是偶尔可以见到几位背负长剑的侠客往西而去。西边和
南边均有一座高山，高耸入云。
LONG);

  set("outdoors", 2);
  set("exits", ([      
 "northeast" : __DIR__"road4",
      "west" : __DIR__"road0",
 ]));
 setup();
}






