//stockroom.c  by wfei apr 3 2001

inherit ROOM;
#include <ansi.h>
void create ()
{
set("short","彩票购买窗口");
set("long",@LONG

这是梦幻西游的彩票购买站。如果你想发财的话，
你可以花10两黄金购买一张彩票。
LONG);
set("exits", ([ /* sizeof() == 1 */
 "south" : "/d/wiz/entrance",
]));
set("chat_room",1);
      set("no_magic", 1);
  set("no_fight",1);
        set("freeze",1);
set("objects", ([ /* sizeof() == 1 */
  "/d/wiz/caipiao/npc/stockboss" : 1,
]));
       setup();
}
void init()
{
add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "bian") return 1;
    if (verb == "fight") return 1;
    if (verb == "exert") return 1;
    if (verb == "cast") return 1;
 if (verb == "steal") return 1;
 if (verb == "edit") return 1;
 if (verb == "more") return 1;
 if (verb == "look2") return 1;
 if (verb == "cat") return 1;
    if (verb == "ji") return 1;
    if (verb == "perform") return 1;
    if (verb == "smash") return 1;
    if (verb == "dest") return 1;
    if (verb == "update") return 1;
    if (verb == "kill") return 1;
    return 0;
}

