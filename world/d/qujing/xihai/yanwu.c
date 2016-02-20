inherit ROOM;

void create()
{
        set("short", "演武场");
        set("long", @LONG
这里是西海龙宫的演武场。敖顺重英豪，常在此召开西海
比武大会，广招西海豪杰，以招贤纳士。四周放满了形形
色色的武器，刀戢剑斧，无所不有，几位龙宫护卫站在旁
边，虎视耽耽地看着你这位不速之客。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "enter" : __DIR__"dian", 
                "southdown" : __DIR__"gate", 
                "east" : __DIR__"lgroom", 
                "west" : __DIR__"bqroom", 
        ]));
        set("no_fight",1);
        set("objects", ([
                 "/d/qujing/xihai/npc/huwei":3, 
        ]));


        setup();
}

void init ()
{
  add_action ("do_enter","enter");
}

int do_enter (string arg)
{
  object me;
  me = this_player ();

  message_vision ("$N装出一副很镇静的样子，大摇大摆地往里走。\n",me);
  if (! me->query_temp("apply/name") ||
      me->query_temp("apply/name")[0] != "送信小妖")
  {
    message_vision ("\n龙宫护卫嚷道：“哪来的混蛋！”言讫，飞起一脚，将$N踢了出去。\n",me);    
    me->move(__DIR__"haidi5");
  return 1;
  }
  else
    message_vision ("\n龙宫护卫笑道：“原来是给小王爷送信的，辛苦了，请进，请进！”\n",me);    
    me->move(__DIR__"dian");
  return 1;
}

