inherit ROOM;
#include <ansi.h>
void create()
{
set("short", HIR"主宰神殿"NOR);
set("long", @LONG
  
广阔无边的大殿，你一眼看去，似乎无边无际，永远望不到尽头。
前面的宝座上坐着一个高大的巨神，正冷冷注视着你。
  
LONG);
        set("exits", 
        ([ 
        "up" : "/d/newjob/liudao/jitan",
                        ]));
set("objects", ([ /* sizeof() == 1*/ 
__DIR__"npc/luohou" : 1,
]));
setup();
}
void init()
{   
          add_action("block_cmd","",1);         
}
int block_cmd()
{
string verb = query_verb();
if (verb=="score") return 1; 
return 0;
}
