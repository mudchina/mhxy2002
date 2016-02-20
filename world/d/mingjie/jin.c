//Cracked by Roath
#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);

void create()
{
  set ("short", "入口");
  set ("long", @LONG

这里就是冥界的入口
LONG);

          set("valid_startroom",1);
  set("exits", ([ /* sizeof() == 4 */
               "northdown"    :       __DIR__"men",
  ]));

  set("objects", ([ 
        ]));
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
  	"water" : 1,
	]));
  set("outdoors", 1);
      
	setup();     
}


