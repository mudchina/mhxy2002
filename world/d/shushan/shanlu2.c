//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","山路");
  set ("long", @LONG

举目西望，只见山上清翠满目，山形如城,连峰不绝，蔚然深秀。不用
说，前面就是蜀山了。西面是一座栈桥。往东走就是下山的路了。
LONG);

  set("outdoors", 2);
  set("exits", ([      
  "eastdown" : __DIR__"shanlu1",
    "westup" : __DIR__"zhanqiao",
 ]));
 setup();
}






