#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIC"人魔殿"NOR);
     set("long",
   "                                   \n"
"                        "+BBLU+""+HIC+"人魔殿"+NOR+"                 \n"    
"这里就是人魔殿，也是魔教的刑堂，看起来是守卫是十分的森严\n"
"此殿上书一匾"+HIG+"□人魔殿□\n"NOR
);
  set("exits", ([ /* sizeof() == 3 */
          "out": __DIR__"dating2",
          "enter": __DIR__"dating4",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/renmo" : 1,
  ]));
 setup();
      replace_program(ROOM);
}
