// 龟仙岛 by Calvin
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "海边");
  set ("long", @LONG

这里是个很高的峭壁,崖边下是无尽的大海,浅海处还有几个人在游泳。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/calvin/lanling/xiaolu8",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object  me, horse;
        me = this_player();
/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/

message_vision(HIY "$N纵身一跃，跳入海中。只见$N使足了全身力气，手足并用，不一会儿就游到了海中龟仙岛上。\n" NOR, me);
        me->move("/d/longzhu/qy/dao");
        message_vision(HIY "只见$N浑身湿漉漉地从海里爬了上来。\n" NOR, me);
        me->receive_damage("kee", 500+random(500));
        me->receive_damage("sen", 1000+random(500));
//        me->receive_damage("combat_exp", 1000);
//        me->receive_damage("max_kee", 20);
//        me->receive_damage("max_sen", 20);
        return 1;
}
