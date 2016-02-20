// 龟仙岛 by Calvin
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "龟仙岛");
  set ("long", @LONG

这里是传说中龟仙人修身养性的地方,这里四季如春。
LONG);

  set("exits", ([ /* sizeof() == 2 */
//  "east" : "/d/longzhu/xxx",
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/longzhu/npc/guei" : 1,
        ]));

  set("outdoors", 1);
        set("sleep_room",1);
        set("if_bed",1);                             

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

message_vision(HIY "$N纵身一跃，跳入海中。只见$N使足了全身力气，手足并用，不一会儿就游到了仙石上。\n" NOR, me);
        me->move("/d/longzhu/qy/haibian");
        message_vision(HIY "只见$N浑身湿漉漉地从海里爬了上来。\n" NOR, me);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 150);
        return 1;
}
