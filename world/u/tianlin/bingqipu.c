//By tianlin@mhxy for 2001.9.18

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "兵器铺");
        set ("long", @LONG

刚一进门就看到兵器架上摆着各种兵器，从上百斤重的大刀到轻如芥
子的飞磺石，是应有尽有。女老板是老英雄萧振远的小女儿，也是振
远镖局二老板，巾帼不让须眉。


LONG);

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"qinglong-e1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoxiao" : 1,
        ]));

	set("no_clean_up", 0);
       setup();
	//replace_program(ROOM);
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{

	object me=this_player();
	me=this_player();

              return notify_fail(HIY"这个道具店不是给大米设定的\n"NOR);
       if(me->query("daoxing")<50000)
              return notify_fail(HIY"这个道具店不是给大米设定的\n"NOR);
	message_vision(HIY"$N往里面的道具店走去。\n"NOR, me);
       this_player()->move("/u/tianlin/wuqi/daojudian");
        return 1;
}
