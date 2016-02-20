// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: /d/qujing/wudidong/inner-tang.c

inherit ROOM;

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();
void create ()
{
  set ("short", "[33m´óµî[m");
  set ("long", @LONG

´óµîÀïÎÞÊýÐ¡ÑýÀ´»Ø±¼×ß£¬ÕýÔÚ×¼±¸´ó¿ªóÛÏ¯¡£Ò»¸öÅ®×ÓÕýÖÐ¸ß×ø£¬
ÔÆ÷ÙµÍ´¹£¬½ðîÎ°ëÁï£¬ÕýÐ¦Ò÷Ò÷µØÖ¸»Ó×ÅÖÚÐ¡Ñý£¬È«²»¹Ë×Ô¼ºÏãº¹ÁÜ
Àì¡£ÄãÍùÈËÈºÖÐÒ»»ì£¬Ò»Ê±µ¹Ò²ÎÞÈË·¢¾õ¡£Õâ¸öµØ·½Ò²ÊÇ´«ÊÚÈËÈâ
°ü×Ó×ö·¨µÄµØ·½¡£ÄãÖ»ÒªÀ´(hear)£¬¾Í¿ÉÒÔÁË¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yushu" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tang-gate",
]));

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
   if(phase==5&&(!query("jiangjing"))) jiang_jing(where);
if(phase==6&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}

void jiang_jing(object where)
{
message("channel:chat",CYN+"¡ó"YEL"ÏÝ¿ÕÉ½ÎÞµ×¶´"CYN"¡ó"NOR+WHT"ÓñÊó¾«(Yu shu)£º"CYN"ÏÖÔÚ¿ªÊ¼´«ÊÚÎÒÃÇÎÞµ×¶´µÄ±¦µä¡£"HIR"(Hear)\n"+NOR,users());
tell_object(where,"µØÓ¿·òÈËËµµÀ£ºÕâÈËÈâ°ü×ÓµÄÎ¶µÀ¿ÉÊµÔÚÊÇºÃ°¡¡£\n");
tell_object(where,"Ê×ÏÈÒªÐÄºÝÊÖÀ±£¬²»ÄÜÍÏÄà´øË®¡£\n");
tell_object(where,"ÈËÈâ°ü×Ó³ÔµÄ¾ÍÊÇÐÂÏÊ£¬²»ÄÜ·ÅÖÃ£¬¿³ÏÂÈâºó£¬ÒªÁ¢¼´×ö³É°ü×Ó¡£\n");

   tell_object(where,"ÒªµãÊÇ£ºÈËµÄÐÄÔà¸½½üµÄÈâ×îÎªÏÊÃÀ¡£\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"µØÓ¿·òÈËËµµÀ£º»ØÈ¥ÊÔÊÔÄãµÄÈËÈâ°ü×Ó×öµÄÈçºÎ¡£\n");
   set("jiangjing",0);
     set ("long", @LONG
    ÕâÀï×ø×ÅÐ©¹ÖÄ£¹ÖÑùµÄÑý¹Ö£¬ËûÃÇµÄÑÛ¾¦ºìºìµÄ
£¬ËÆºõÏëÒª³ÔÈË£¬ËûÃÇÔÚÌýµØÓ¿·òÈËËµÐ©Ê²Ã´¡£
LONG);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");
   if(!query("jiangjing"))
      return notify_fail("µØÓ¿·òÈË»¹Ã»¿ªÊ¼´«ÊÚ±¦µäÄØ¡£\n");

 if((string)me->query("family/family_name")!="ÏÝ¿ÕÉ½ÎÞµ×¶´")
      return notify_fail("ÍâÅÉµÜ×Ó²»µÃÀ´Ìý½²¡£\n");
   if(me->query("faith")>1500)
      return notify_fail("×öÈËÈâ°ü×ÓÕâÖÖÐ¡ÊÂ£¬ÄãÒÑ¾­ÊÇµØÓ¿·òÈËµÄÊ¦¸µÁË¡£\n");

    tell_object(me,"ÄãÔÚÅÔ±ßÌý×Å£¬Ìý×Å¡£²»½ûÏëÆðÁËÈËÈâ°ü×ÓµÄÃÀÎ¶¡£\n");
   me->start_busy(5);
   me->add("faith",1);
   me->add("combat_exp",30);
   me->add("potential",10);
   me->improve_skill("yaofa",100);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
