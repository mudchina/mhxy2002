inherit ROOM;
#include <room.h>
void create()
{
set("short","大殿");
set("long",@LONG
这里是古墓的大殿,你一抬头就发现妲几娘娘
正端座在太师椅上.
LONG);
set("exits", ([
         "north" : __DIR__"nei2",
     //  "west" : __DIR__"road4",
     //  "north": __DIR__"chufang",
       "south":__DIR__"mishi",
]));
set("objects", ([
  __DIR__"npc/daji" : 1,
]) );
//  create_door("south", "铁门", "north", DOOR_CLOSED);

setup();

}
int valid_leave(object me, string dir)
{
    if (dir == "south" ) {
{ if (((string)me->query("family/family_name")=="轩辕墓")
//   ||   wizardp(me)
   ||   me->query_temp("gumu_answer")) {
     return ::valid_leave(me, dir);
           }
}
return notify_fail("只有妲几娘娘的亲信才能过去，你和古墓毫无渊源怎能过去？\n");  
}
if (dir == "north")
{ return ::valid_leave(me,dir);}
}
