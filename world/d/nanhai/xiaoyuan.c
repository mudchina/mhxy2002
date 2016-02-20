//By tianlin@mhxy for 2002.3.6

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "小院");
  set ("long", @LONG

这是一间小院，院中遍布奇花异草，参天大树将院子四周遮
得严严实实，好一个修身养性之所在。
LONG);

  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/tidu" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guangchang",
  "west" : __DIR__"zoulang",
  "south" : __DIR__"gate",
  "east" : __DIR__"zoulang2",
]));

create_door("south", "石门", "north", DOOR_CLOSED);
  setup();
}
void init()
{
    object where=this_object();
    remove_call_out("check_time");
    check_time(where);
    add_action("do_hear","hear");
}
void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];

   int phase=((int)(t/120));
   if(phase==5&&(!query("nianjing"))) jiang_jing(where);
   if(phase==6&&query("nianjing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",CYN+"◇"HIY"南海普陀山"NOR+CYN"◇"NOR+WHT"剃度僧(Tidu seng)："CYN"诵经时间到了,普陀弟子速到书院诵经研习佛法！！(Hear)\n"+NOR,users());
tell_object(where,"你听到剃度僧嘴里念到 @@~$%%~~~&~@@#~$% 。\n");
tell_object(where,"........................................\n");
   set("nianjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"剃度僧说道：大家休息吧。\n");
   set("nianjing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("nianjing"))
      return notify_fail("剃度僧还没有开始诵经研习佛法。\n");

 if((string)me->query("family/family_name")!="南海普陀山")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>1000)
      return notify_fail("剃度僧对你说道：你可以去找些其它的事情做了。\n");
   tell_object(me,"你跟着剃度僧的口形慢慢的读着。\n");
   me->start_busy(5);
   me->add("faith",1);
   me->add("combat_exp",30);
   me->add("potential",5);
   me->improve_skill("buddhism",300);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
