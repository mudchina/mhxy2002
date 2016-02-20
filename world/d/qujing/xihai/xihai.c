#include <ansi.h>
inherit ROOM;
int do_dive();

void create ()
{
        set ("short", "西海之畔");
        set ("long", @LONG

见惯了一望无际的雪原，巍峨雄伟的冰山，突然间碧波万顷，浩
瀚壮阔的水面展现在面前，你顿时觉得一股柔情蜜意涌上心头。
山，湖，草，鸟，仿佛是到了另一个世界，一片片海浪不停的
扑上海滩来，看来这里是个冲浪(dive)的好去处。
LONG);

       set("exits", 
        ([ //sizeof() == 4
                "east" : "/d/xueshan/xueshan5", 
                "north" : __DIR__"haitan4",
                "east" : "/d/lingtai/lantao2",
        ]));

        set("outdoors", "xihai");
        setup();
}

void init()
{
    add_action("do_dive", "dive");
}

int do_dive()
{       object me, zhou;
        me=this_player();



            if(( !(zhou=present("bishui zhou", me))
                ||(string)zhou->query("unit")!="张")
                && (string)me->query("family/family_name")!="龙宫"
                && (string)me->query("family/family_name")!="东海龙宫")

                return notify_fail("你一个猛子扎到水里．．．\n"+
                  "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");


                message_vision(HIG "$N一个猛子扎到水中，然后不见了．\n" NOR, me);
                me->move("/d/qujing/xihai/haidi1");
                message_vision("$N吐着气泡，潜了过来。\n",me);
                return 1;
}


