// Room: /u/tianlin/bedroom.c
inherit ROOM;
void create ()
{
  set ("short", "Happy Bar");
  set ("long", @LONG

  这里是田林的睡房.
LONG);
  set("outdoors", 0);
  set("chat_room",1);
  set("no_time",1);
  set("no_fight", 1);
        set("sleep_room",1);
        set("no_magic", 1);
        set("if_bed",1);                             
        set("freeze",1);                            
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  set("valid_startroom", 1);
    set("exits", ([
            "east" : __DIR__"workroom",
    ]));             
//        set("objects", ([
//            __DIR__"liudh" : 1,
//        ]));        
      setup();
}
