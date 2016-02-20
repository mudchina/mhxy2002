//Cracked by Roath
// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "南瓜家的大门");
  set ("long", @LONG

这里是通往南瓜家的大门，从表面上看上去根本没有任何去南瓜家的路
但是据说 只要是有缘人就肯定能找到去南瓜的地方 不知你是否就是传
说中的有缘人，听说南瓜家里非常的豪华，可能还有什么从来没有见过
的宝贝。
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "zhuli" : "有缘人来的地方(zhuli,zhuli1,zhuli2)。 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/city/chatroom",
]));
  set("objects", ([
    __DIR__"npc/dog" : 1,
  ]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_zhuli", "kisszhuli");
        add_action("do_zhuli", "lovezhuli", );
        add_action("do_zhuli", "zhuli");
}

int do_love()
{       object me;
        me=this_player();
        message_vision(HIY "$N说道：“芝麻开门”\n\n" NOR, me);
        me->move("/u/gua/workroom");
            message_vision(HIY "\你说道：“芝麻关门”,你走了进来。\n" NOR, me);
                return 1;
}

