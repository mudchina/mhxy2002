//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG 
这里是河神府的石室。本来是清洁典雅，幽深静悒。现在
却是喧嚣嘈杂，肮脏龌龊，到处都是乱七八糟的杂物。几
个小妖正坐在地上猜株耍子。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"sleeproom",
  "north" : __DIR__"zoulang2",
]));

        set("objects", ([
                __DIR__"npc/guai" : 3,
        ])); 

        setup();
} 

