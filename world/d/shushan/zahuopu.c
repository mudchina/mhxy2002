//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","杂货铺");
  set ("long", @LONG

这里的东西都不错，而且可以说是样样俱全,所以客人也比较多。屋里打
扫的也很干净，所以即使没有客人，也有好多人在这里和老板聊天。
LONG);

  set("exits", ([ 
     "west" : __DIR__"road1",
 ]));
 set("objects", ([ 
  __DIR__"npc/zaboss" : 1,
 ]));
 set("no_clean_up", 0);
 setup();
}






