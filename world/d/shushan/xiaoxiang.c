//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","小巷");
  set ("long", @LONG

这个小巷并不是一个寂静的小巷，东面的武器铺不时传来叮叮当当的打
铁噪音。这里除了买卖铁器的人就没什么人走动了。打铁铺就是为了避
免影响村人才修建这条小巷的。西边是村路。
LONG);

  set("outdoors", 2);
  set("exits", ([      
      "west" : __DIR__"road2",
      "east" : __DIR__"datiepu",
 ]));
 setup();
}






