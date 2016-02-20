#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIR"魔教总舵"NOR);
     set("long",
   "                                   \n"
"                        "+HIR+"魔教总舵"+NOR+"                 \n"    
"这里便是魔教的总堂，也是教主风飞白处理事情的地方，堂前挂着\n"
"一副泼墨山水画。\n"NOR
);
  set("exits", ([ /* sizeof() == 3 */
          "out": __DIR__"dating3",
          "west": __DIR__"bedroom",
          "east": __DIR__"jobroom",
          "north": __DIR__"roada",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/master" : 1,
  __DIR__"npc/tai" : 1,
  ]));
  set("valid_startroom", 1);
 setup();
  call_other("/obj/board/mj_b", "???");
      replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
   if((string)me->query("family/family_name")=="魔教") return 1;
    if (dir == "west" ) {
        return notify_fail("那里是风飞白的书房，你最好别进去了。\n");
    }
return 1;
}
