#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIY"地魔殿"NOR);
     set("long",
   "                                   \n"
"                        "+BBLU+""+HIY+"地魔殿"+NOR+"                 \n"    
"这里就是地魔殿，也是魔教的会堂，看起来是守卫是十分的森严\n"
"此殿上书一匾"+HIB+"□地魔殿□\n"NOR
);
  set("exits", ([ /* sizeof() == 3 */
          "out": __DIR__"dating",
          "enter": __DIR__"dating3",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dimo" : 1,
  ]));
 setup();
      replace_program(ROOM);
}
