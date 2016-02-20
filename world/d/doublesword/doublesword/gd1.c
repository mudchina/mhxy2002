#include <room.h>

inherit ROOM;

void create()
{
    set("short", "谷底");
        set("long", @LONG
只见空谷无人，一片荒凉，削壁环列，宛似身处一口大井之底 。
没想到在皇宫后宫会有这么一个隐蔽的地方.
LONG
        );
        setup();
 
}
void init()
{
        object ob = this_player();
        object jing=new(__DIR__"npc/xiniu-jing");
        if( present("xiniu jing",environment(ob)))
                return 0;
         ob->set("laojun_killjingover", 1);
        message_vision("忽然狂风大作。\n",ob);
        message_vision("不知道从那里，一只妖怪跳了出来。\n",ob);
      jing->move(environment(ob));
     add_action("do_look", "look");
        add_action("do_climb", "climb");
}
int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "cliff") return 0;
             write(
             "你仔细打量四周,高山仰止，令人心寒。你似乎发现一个可疑(climb)的地方。\n"
             );
             this_player()->set_temp("huanggong_look2", 1);
             return 1;
}
int do_climb(string arg)
{
       object me;
       me = this_player(); 
       if ( !arg ) return 0;
       if (!me->query_temp("huanggong_look2"))
        return notify_fail("你没仔细看看就爬？\n");
       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) 
       return notify_fail("你身上负重太多，无法移动。\n");
       message_vision("$N用力爬呀爬。\n", me);
      if((int)me->query_skill("dodge",1) < 200 )  
       return notify_fail("以你目前的轻功修为，爬不上去的。\n"); 
       message_vision("$N纵身一跃。\n", me);
       me->move(__DIR__"qb");
       tell_room(environment(me), me->name() + "从谷底竟然跃上来了。\n", ({ me }));
       me->delete_temp("huanggong_look1");
       me->delete_temp("huanggong_look2");
       return 1;
}
