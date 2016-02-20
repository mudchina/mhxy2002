// by cih 10/01/2002
// Room: /d/kaifeng/zhu2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "香路");
  set ("long", @LONG

这里就上所谓的香路的尽头了。这一路行来，饱览湖光的同时，
香路上还种满了玫瑰，看来八戒也是个罗曼蒂克的人哦。。。
不过看看那个低矮的围墙，好像只要会点什么庄稼把势的人都
可以轻而易举的翻过去似的(climb)

LONG);

  set("exits", ([
        "south" : __DIR__"zhu1",
      ]));
  set("objects", ([
        __DIR__"npc/chunchun" :  1,
      ]));

  set("outdoors", "kaifeng");

  setup();
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
       object chunchun;
       object me=this_player();
 
       if( (!arg) || !((arg == "wall") || (arg == "墙")))
               return notify_fail("爬什么？\n");
       if (me->is_busy()) return notify_fail("你现在正忙着呢。");
       if( me->query("kee") < (int)(me->query("max_kee")/3)){
               me->receive_damage("kee",(int)me->query("max_kee")*20/100);
               return notify_fail("你身子发虚，一头栽了下来，哎呀！\n");
}
       if (!((string)me->query("family/family_name")=="天蓬帅府" )&&
       objectp(chunchun = present("chun chun", environment(me))) && living(chunchun))
{
               message_vision(HIM"春春说道:这位仙人你在我的面前就敢爬我开封的墙,不想活了!\n"NOR, me);
}
       else
{
       if ((int)me->query_skill("dodge", 1)<100 && (int)me->query_skill("chaos-steps", 1) < 100)
{
               message_vision("$N小心翼翼的往上爬了一点，觉得头晕眼花，就赶紧爬了下来．\n", me);
               me->improve_skill("dodge", 100-me->query("str"));
               tell_object(me, "你领悟出一些基本轻功方面的窍门。\n");
}
      else
{
               message_vision(HIG"$N纵身往墙上一跳，只发现你已经翻了上来。\n"NOR, me);
               me->move(__DIR__"shuding.c");
}
}
               me->receive_damage("kee", (int)me->query("max_kee")*10/100);
               return 1;
}


