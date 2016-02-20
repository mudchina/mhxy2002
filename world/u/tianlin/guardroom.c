inherit ROOM;
void create ()
{
  set ("short", "皇家花园");
  set ("long", @LONG

这个花园，就是人间仙境。
LONG);

     set("exits", ([
             "enter" : __DIR__"workroom",
     ]));    
  set("outdoors", 1);
    set("objects", ([        
         "/d/obj/flower/flower.c" : 5,
       "/d/dntg/hgs/npc/gardener.c" : 1,
    ]));
  setup();
}
