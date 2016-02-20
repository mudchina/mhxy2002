//By Repoo
inherit ROOM;
#include <ansi.h>
void create()
{
   set("short", HIR"审判之门"NOR);
        set("long", @LONG
  
    这里弥漫着神秘的红色光芒，中间站着一个相貌威严的天神。
  
LONG);
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/shenpanshen" : 1,
]));
        setup();
}
void init()
{   
  object who = this_player();
if(!((who->query_temp("liudao/eguijie") == "begin") || (this_player()->query("id") == "shenpan shen")))
  {
  tell_object(who,"你怎么进来的？\n");
  who->move("/d/city/kezhan");
  }
  who->set_temp("obpks",0);
          add_action("block_cmd","",1);         
          add_action("do_chanhui","chanhui");   
}
int block_cmd()
{
        string verb = query_verb();
        if (verb=="score") return 1; 
        return 0;
}
int do_chanhui ()
{
  object who = this_player();
  int i = who->query("PKS");
  int j;
if (!who->query_temp("eguijie/chanhui")) return notify_fail("有人请你忏悔吗?\n");
  if (who->is_busy())
    return notify_fail ("你正忙着呢！\n");

  message_vision (HIY"$N盘膝而坐，合掌闭目。\n"NOR,who);
   if ((int)who->query_temp("obpks") == i)
  {
    message_vision (HIM"\n$N感觉到已经超度死者的亡魂了。\n"NOR,who); 
 who->delete_temp("eguijie/chanhui");
  who->move("/d/newjob/liudao/shendian");
  }
  else
  {
    j = i+10;
    who->start_busy (j,j);
    call_out ("start_chanhui",5,who,i);
    call_out ("finish_chanhui",j,who);
  }
  return 1;
}

void start_chanhui (object who, int i)
{
  message_vision (HIB"\n$N念道：请上天饶恕我的罪孽。\n"NOR,who); 
  who->add_temp("obpks",1);
}

 void finish_chanhui (object who)
{
  object where = environment(who);
  who->interrupt_me ();
  message_vision (HIB"\n$N忏悔完毕，睁开眼睛。\n"NOR,who); 
}
