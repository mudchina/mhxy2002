// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// inside3.c
#include <ansi.h>
void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_serve();
inherit ROOM;

void create ()
{
  set ("short", "[33mÁú¹¬Õýµî[m");
  set ("long", @LONG

ÕýµîÖ®ÉÏÐüÒ»Ã÷Öé£¬°ÑÅµ´óÒ»µîÕÕµÃÍ¨ÁÁ¡£Á½ÅÔ×ÀÒÎÓñÊ¯´òÔì¶ø³É£¬¡¡¡¡
µ±ÖÐ»¹Ç¶×ÅÎÞÊýÖé±¦¡£Á½±ßÇ½ÉÏ¹ÒÁËÁ½·ù»­£¬¿´ÆðÀ´Ïàµ±µÄ³Â¾É¡£¡¡¡¡¡¡
ÄÏ±±ÊÇÁ½×ùÆ«µî¡£Èç¹ûÁúÍõÀÛÁË£¬Äã»¹¿ÉÒÔ¸øËû·þÎñÒ»ÏÂ¡£(serve)

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"inside2.c",
  "east" : __DIR__"inside4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/longwang" : 1,
]));
  setup();
}

void init()
{
   object where=this_object();

  remove_call_out("check_time");
   check_time(where);
   add_action("do_serve","serve");
}

void check_time(object where)
{
   mixed *local = localtime(time()*60);
   int t = local[2] * 60 + local[1];
  int phase=((int)(t/120));
if((phase==1)&&(!query("hungry"))) feel_hungry(where);
if((phase==2)&&query("hungry")) feel_full(where);
   call_out("check_time",60,where);
}

void feel_hungry(object where)
{
message("channel:chat",CYN+"¡ó"HIC"¶«º£Áú¹¬"NOR+CYN"¡ó"NOR+WHT"°½¹ã(Ao guang)£º"CYN"ëÞÀÛÁË£¬ÓÐÈËÀ´·þÎñÂð£¿"HIR"(Serve)\n"+NOR,users());
   set("hungry",1);
}
void feel_full(object where)
{
tell_object(where,"¶«º£ÁúÍõÐ¦µÀ£ººÜºÃ£¬ºÜºÃ¡£\n");
  set("hungry",0);
}
int do_serve()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");
   if(!query("hungry"))
      return notify_fail("¶«º£ÁúÍõµÀ£ºÎÒÏÖÔÚ²»ÀÛ£¡\n");
   if((string)me->query("family/family_name")!="¶«º£Áú¹¬")
      return notify_fail("¶«º£ÁúÍõµÀ£º²»¸ÒÀÍÄú´ó¼Ý£¡\n");
   if(me->query("faith")>400||me->query("combat_exp")>100000)
      return notify_fail("ÄúÊÇÎÒÃÇÁú¹¬ÓÐÉí·ÝµÄÈË£¬ÕâÑùµÄÊÂ¾ÍÈÃÐ¡±²ÃÇ×ö°É¡£\n");
   tell_object(me,"Äã¸øÁúÍõÓÖÊÇ´·£¬ÓÖÊÇÆþµÄ£¬°ÑÁúÍõ·þÎñµÄÖ±½ÐÍ´¿ì£¡\n");
   me->start_busy(5);
      me->add("faith",1);
   me->add("combat_exp",9);
   me->add("potential",3);
   me->improve_skill("seashentong",100);  
   me->receive_damage("kee",40);
   me->receive_damage("sen",40);
   return 1;
}
