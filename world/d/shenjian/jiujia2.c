// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "小船坞");
        set("long", @LONG
这是一个修建在湖边的小船坞，站在这里，你可以看到美丽的湖光山色，
湖是绿水湖，山是翠云峰。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jiujia",
]));
        set("coor/x",-1085);

	set("coor/y",15);

	set("coor/z",0);
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
    write("店小二走出来给你一记耳光，说道：没事不要乱叫嚷。说完恶狠狠的瞪了你一眼就回到前面去了！\n");
    return 1;
   }
	
 if (query("exits/down")) return 1;
 if (!objectp(boat=find_object(__DIR__"xiaochuan")))
  boat=load_object(__DIR__"xiaochuan");
 boat->set("exits/up",__DIR__"jiujia2");
 boat->set("no_fight",1);
 boat->set("no_magic",1);
 set("exits/down",__DIR__"xiaochuan");
 boat->set_temp("mark/dest","sjhupan1");
 call_out("boat_leave",10,boat);
 return 1;
}

void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","船慢慢的往远处漂走了。\n",this_object()); 
	message("vision","小船向远处的神剑山庄划去。\n",boat);
	boat->delete("no_fight");
	boat->delete("no_magic");
	boat->boat_run(0);
}
