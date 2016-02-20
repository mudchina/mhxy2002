//by tianlin 2001.7.30

inherit ROOM;

void create ()
{
  set ("short", "郊外小镇");
  set ("long", @LONG

这里就是开封城里面,最有名的一个小镇了,这里也是猪八戒
常来的地方,近处有个老头在那里站着,好像在想些什么
LONG);

  set("exits", ([
        "north" : __DIR__"migong/mi2",
        "south" : __DIR__"xiaolu2",
      ]));
  set("objects", ([
        __DIR__"npc/laotou" :  1,
      ]));

  setup();
}


