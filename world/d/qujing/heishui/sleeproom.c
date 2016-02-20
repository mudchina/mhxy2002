//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "睡房");
  set ("long", @LONG 
这里本来是河神府的客房，现在却成了小妖们歇息打闹的
地方。但现在小妖都在外边执勤玩乐，不会进来。所以在
这里安安静静睡一觉大概是没危险的吧。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"zoulang4",
]));
         set("sleep_room",1);
        setup();
} 

