//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","山麓");
  set ("long", @LONG

曲折的小路尽头豁然开朗,东南方向就是著名的卧眉峰了。由于很久没
人走动，路边的小草(grass)都有人那么高了,不知道草里面有没有什么
东西。
LONG);

  set("outdoors", 2);
  set("exits", ([      
// "southeast" : __DIR__"womeifeng",
 "northeast" : __DIR__"road0",
 "southwest" : __DIR__"shanlu1",

 ]));
 setup();
}






