// by snowcat

inherit ROOM;

void create()
{
  set ("short", "后殿");
  set ("long", @LONG

后殿里庄严肃穆，墙上绘有金龙戏珠，殿顶上画着紫色祥云朵朵缭
绕，瑞气朦胧。殿墙边是凤尾屏风，地上铺着银花绣绒毯，殿里一
阵阵丝竹乐声轻缓地飘来。

LONG);
  set("exits", ([ 
    "south" : __DIR__"dadian",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  setup();
}
void init()
{
     add_action("do_look", "look");
        add_action("do_move", "move");
}
int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "wall") return 0;
             write(
             "你仔细打量四周。发现在阴暗处有一块凹陷的光滑的东西，似乎是按纽(button)。\n"
             );
             this_player()->set_temp("huanggong_look1", 1);
             return 1;
}
int do_move(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "button" ) return 0;
       if ( !arg ) return 0;
       if (!me->query_temp("huanggong_look1"))
        return notify_fail("你动的了吗？\n");
       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) 
       return notify_fail("你身上负重太多，无法移动。\n");
       message_vision("$N似乎看见一个暗室。\n", me);
      if((int)me->query_skill("dodge",1) < 200 )  
       return notify_fail("以你目前的轻功修为，不敢进去。\n"); 
       message_vision("$N纵身挤了进去。\n", me);
       me->move(__DIR__"qb");
       tell_room(environment(me), me->name() + "从后宫竟然进来了。\n", ({ me }));
       me->delete_temp("jqg_look1");
       me->delete_temp("jqg_look2");
       return 1;
}

