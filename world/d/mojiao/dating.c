#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIR"天魔殿"NOR);
     set("long",
   "                                   \n"
"                        "+BBLU+""+HIR+"天魔殿"+NOR+"                 \n"    
""+HIW+"这里就是天魔殿，也是魔教的总部，看起来是守卫是十分的森严\n"
""+HIW+"此殿上书一匾"+HIR+"□天魔殿□"+NOR+"\n"
);
  set("exits", ([ /* sizeof() == 3 */
          "out": __DIR__"gate",
          "enter": __DIR__"dating2",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/tianmo" : 1,
  ]));
 setup();
      replace_program(ROOM);
}
