//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","环峰朱栏栈桥");
  set ("long", @LONG

这是山上的一座大桥，桥下面是万丈深渊。在桥的上面听到水的声音，
好像是从桥下传上来的，听起来水流很急。再往上走就是迎客亭了,
你已经能远远的看到，在迎客亭里有人在那里歇息。
LONG);

  set("outdoors", 2);
  set("exits", ([      
  "eastdown" : __DIR__"shanlu2",
   "northup" : __DIR__"yingketing",
 ]));
 setup();
}






