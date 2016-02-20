//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","山路");
  set ("long", @LONG

你顺着草丛走了过来，西边的那座高山好象就在你的面前,那座山应该
就是蜀山了。一直往西走估计就会到了传说中的蜀山剑派了。
LONG);

  set("outdoors", 2);
  set("exits", ([      
 "northeast" : __DIR__"shanlu",
    "westup" : __DIR__"shanlu2",
 ]));
 setup();
}






