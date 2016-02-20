// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "绿水湖畔");
        set("long", @LONG
眼前枫叶飞舞，站在这里，可以看到远处的山峰，从湖面吹来的风中充
满了清香，和一种从远山传来的芬芳。
LONG
        );
         set("coor/x",-1310);

	set("coor/y",165);

	set("coor/z",5);
set("no_magic",1);
	setup();
}
void init()
{
  add_action("do_yell", "yell");
}
int do_yell(string arg)
{
 object boat;
 object me,oob;
 int i;

 if(!arg || arg=="")
  {
   write("你要喊什么？\n");
   return 1;
  }
 if( arg == "谢掌柜")
  {
   me = this_player();
   message_vision("$N对着幽静的湖面喊道：谢掌柜......一条快船慢慢的出现在你眼前。\n", me);
  }
  else
   {
    write("一个苍老的声音在你耳边说到：没事就请离开，不要大呼小叫。\n");
    return 1;
   }
	
 if (query("exits/down")) return 1;
 if (!objectp(boat=find_object(__DIR__"xiaochuan")))
  boat=load_object(__DIR__"xiaochuan");
 boat->set("exits/up",__DIR__"sjhupan1");
 boat->set("no_fight",1);
 boat->set("no_magic",1);
 set("exits/down",__DIR__"xiaochuan");
 boat->set_temp("mark/dest","jiujia2");
 call_out("boat_leave",10,boat);
 return 1;
}

void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","船慢慢的往湖水中央漂走了。\n",this_object()); 
	message("vision","小船向远处的谢家村划去。\n",boat);
	boat->delete("no_fight");
	boat->delete("no_magic");
	boat->boat_run(0);
}
