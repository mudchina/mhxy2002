//Cracked by Roath
// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HBRED+HIW"冷風工作室"NOR);
  set ("long", @LONG

這裡是冷風的地盤，任何人謝絕打擾。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "水晶大床(gosleep,gobed,bed)。 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "wizroom" : "/d/wiz/wizroom",
  "center" : "/d/city/center",
  "silao" : "/d/wiz/outjail",
  "kz" : "/d/city/kezhan",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
        me->move(__DIR__"sleep");
            message_vision(HIY "\n纱帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}

