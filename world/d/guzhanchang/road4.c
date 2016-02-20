//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "第四重天入口处");
  set ("long", @LONG

这里就是传说中的第四重天的入口了。
如果你不愿犯天条的话，现在离开还来的急。
 ==============================
      / \| O   O |
      \ /  \v_'/
       #   _| |_
      (#) (     )
       #\//|* *|\\     报
       #\/(  *  )/     上
       #   =====       名
       #   (\ /)       来
       #   || ||        ！
      .#---'| |----.
       #----' -----'
===============================
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "north": __DIR__"tian4",
]));
set("objects", ([
        "/d/guzhanchang/npc/shouhuzhe4": 1]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();


}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "north") {
                if(objectp(a=present("shouhuzhe", environment(me))) && living(a) )
                return notify_fail("守护者好象不愿让你过去！\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}


