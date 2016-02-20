// created by snowcat.c 4/4/1997
// room: /d/nuerguo/xiaolu1.c

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

这是一条又细又长的山间小径，一会儿高，一会儿低。路的
两边是不知名的野花野草。你快速地走着，觉得山势有一点
陡峭。

LONG);

  set("exits", ([
    "east"       : __DIR__"jieyang",
    "westup"     : __DIR__"xiaolu2",
  ]));
  set("outdoors", __DIR__"");
    set("have_coin", 10);
  setup();
}

void init()
{
   add_action("do_dig", "waqianl");
   add_action("do_dig", "waqianl");
}

int do_dig(string arg)
{
   object ob,coin;
   object who=this_player();
   object where=this_object();
   if( (!arg) || (arg != "qiu yin" && arg != "coin" && arg !="蚯蚓") )
      return notify_fail("想挖什么？\n");
   if( !(ob = who->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && 
(string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) )
      return notify_fail("找个好锋利的家伙来挖吧。\n");
   if( who->query("kee")<50 )
      return notify_fail("你太累了，先歇会儿再挖吧。\n");
   who->add("mud_age",10000);
   if (random(10) > where->query("have_coin"))
      message_vision("$N在泥巴中翻来翻去，结果什么也没找到。\n", who);
   else  
     {
     coin=new("/obj/money/coin");
     coin->move(who);
        message_vision("$N从泥巴里找到一只蚯蚓，把它抓了出来。\n", who);
     where->add("have_coin",1);
     call_out("regenerate", 300);


     }
     return 1;
}

int regenerate()
{
   object where=this_object();
   if (where->query("have_coin") < 10)  
        where->add("have_coin",1);
   return 1;
}



