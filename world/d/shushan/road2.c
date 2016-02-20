//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","村路");
  set ("long", @LONG

这是一条村中的石子路。路西是一家客栈，客栈门前的大树上挂着一
个幌子，上书“悦来客栈”。路东是一家杂货铺。一直向南走，就到
村头了。
LONG);

  set("outdoors", 2);
  set("exits", ([      
     "north" : __DIR__"road1",
 "southwest" : __DIR__"road3",
 "southeast" : __DIR__"jiudian",
      "east" : __DIR__"xiaoxiang",
      "west" : __DIR__"dangpu",
 ]));
 setup();
}






