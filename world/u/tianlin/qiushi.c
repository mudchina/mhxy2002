//stockroom.c  by wfei apr 3 2001
//BY tianlin@Mhxy for 2002.2.26
inherit ROOM;
#include <ansi.h>
void create ()
{
set("short",HIR"拘留室"NOR);
set("long",@LONG

这里是专门用来关押囚禁流氓的地方，进了这里就只能老老实实
的呆着。四周黑漆漆的一片。举目远眺仍看不到任何事物。拢耳
倾听却听不到任何声响。
LONG);
set("exits", ([ /* sizeof() == 1 */
 "south" : "/d/wiz/caipiao/caipiaoroom",
]));
set("chat_room",1);
      set("no_magic", 1);
  set("no_fight",1);
        set("freeze",1);
set("objects", ([ /* sizeof() == 1 */
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
    if (verb == "ji") return 1;
    if (verb == "cat") return 1;
    if (verb == "look2") return 1;
    if (verb == "ilist") return 1;
    if (verb == "more") return 1;
    if (verb == "edit") return 1;
    if (verb == "perform") return 1;
    if (verb == "smash") return 1;
    if (verb == "dest") return 1;
    if (verb == "update") return 1;
    if (verb == "kill") return 1;
    return 0;
}

