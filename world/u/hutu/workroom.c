//Cracked by Roath
// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>
inherit ROOM;

void create ()
{
set ("short", HBRED+HIR"糊涂居"NOR);
  set ("long", @LONG

这里就是大天神糊涂的家，到处充满着温馨和诗情画意。
墙上挂着一块大匾,正是郑板桥的难得糊涂。
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "水晶大床(gosleep,gobed,bed)。 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "wiz" : "/d/wiz/wizroom",
  "kz" : "/d/city/kezhan",
  "out" : "/u/xlan/workroom",
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

