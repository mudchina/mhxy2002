// edit by lucas
inherit ROOM;
#include <ansi.h>


void create()
{
        set("short", "卧龙殿");
        set("long", @LONG  
这里是敖顺的寝宫。富丽堂皇，金碧辉煌。轻纱罗帐，飞花
飘香。龙涎为香，凤翎为披。几颗硕大的夜明珠放在宫顶上，
照的整个寝宫青光恍惚。敖顺还未回宫，这巨大的寝宫里空
无一人，显得空荡荡的。龙宫宝物不少，你可以找找看。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"zoulang7", 
                "east" : __DIR__"zoulang8", 
        ]));
  set("zhu_count",3);
        setup();
}
void init()
{
  add_action ("do_search","search");
}

int do_search (string arg)
{
  object me = this_player ();
  object where = this_object ();
  object zhu;

        if( (int)me->query("kee") < 50 )
                return notify_fail("你太累了，歇歇再找吧。\n");
 if (query("zhu_count") < 1) 
  {
    message_vision ("$N在寝宫里四处搜索了一番，什么也没有找到。\n",me);  
    message_vision ("看来被人拿光了。唉！来晚了！\n",me);  
    return 1;
  }
        if (  present("ye mingzhu", me) ) {
                return notify_fail("做人不要贪心，拿了一颗珠子就够了。\n");
          }

  if (random(10))
  {
    message_vision ("$N在寝宫里四处搜索了一番，累得够呛，但什么也没有找到。\n",me);  
   me->add("kee" , -30);
  }
  else
  {
    zhu = new (__DIR__"obj/zhu");
    message_vision ("$N发现床四周有些东西闪着光。\n",me);  
    message_vision ("$N拣起来一看，哇！是价值连城的"HIW"夜明珠"NOR"啊\n",me,zhu);
   me->add("kee" , -30);
    zhu->move(me);  
   add("zhu_count", -1);
  }
  return 1;
}


