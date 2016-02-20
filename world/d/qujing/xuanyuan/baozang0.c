//changed by justin
inherit ROOM;
void create ()
{
  set ("short", "古墓宝藏");
  set ("long", @LONG
黄金，白银，珍珠，玛瑙，夜明珠……
据说是殷商被灭后但被一些带出宫的珠宝......
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baozang",
  "south" : __DIR__"maze12",
]));  
  set("objects", ([
  ]));
   set("no_clean_up", 1);

  setup();
}

void init()
{
  add_action("do_ba","ba");
   if( query("started") != 1 )
   {
     set("started", 1);
	call_out("generate_gold",1600);
   }
}

void generate_gold()
{
   remove_call_out("generate_gold");
   set("available", 1);
}

int do_ba(string arg)
{
   object me, gold,manao,feicui,pearl;
   object ob;
   me = this_player();
	if(me->query("kar")<30)
   me ->unconcious();
 if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type
")!="sword"))
     return notify_fail("没有合适的家伙怎么挖！\n");

   if( query("available") == 1 )
   {
     set("available", 0);
	gold = new("/obj/money/gold");
     manao =new("/d/obj/misc/manao");
     feicui =new("/d/obj/misc/feicui");
     pearl=new("/d/obj/misc/pearl");
     gold->set_amount(500);
     gold->move("/d/xuanyuan/baozang0");
     manao->move("/d/xuanyuan/baozang0");
     feicui->move("/d/xuanyuan/baozang0");
     pearl->move("/d/xuanyuan/baozang0");
     message_vision("只听哗啦一阵响声黄金珠宝落了一地。\n", me);

     remove_call_out("generate_gold");
	call_out("generate_gold",1800);

     return 1;
   }
   else return notify_fail("宝藏被人挖走了。\n");
}

int clean_up()
{
   return 0;
}

