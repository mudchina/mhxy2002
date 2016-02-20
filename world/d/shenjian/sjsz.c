//By tianlin@mhxy for 2002.1.13

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);           
int do_hear();

void create()
{
        set("short", "Éñ½£É½×¯");
        set("long", @LONG
ÕâÀï¾ÍÊÇÎäÁÖÖÐÈË¾¡½ÔÖªµÄÉñ½£É½×¯£¬Àú¾­½­ºþÖÐÁ½°Ù¶àÄêµÄ·çÆðÔÆ
Ó¿£¬¼øÖ¤ÁËÎäÁÖÖÐÁ½°ÙÄêÀ´µÄ²×º£É£Ìï¡£¸ß´óµÄÃÅÂ¥ºÍÔºÇ½Ê÷Á¢£¬ÒòÎª²»
¶ÏÓÐÈË½ø½ø³ö³ö£¬ÕÉ¸ßµÄÖìÄ¾´óÃÅ³¨¿ª×Å£¬ÃÅÇ°ÅÅ×Å¼¸ÅÅÉÏÂíÊ¯¡¢Ë¨Âí×®
¡£ÃÅµÄÉÏ·½¸ß¹Ò×ÅÒ»¸ö½ðÆá´óØÒ£¬ÉÏÃæ²Ô¾¢ÓÐÁ¦µÄÐ´×Å:

                 [37;40m©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©·[0m
                 [37;40m©§[31m   Éñ ½£ É½ ×¯  [37;40m  ©§[0m
                 [37;40m©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿[0m

LONG
        );
        set("exits", ([ 
   "south" : __DIR__"sroad3",
   "north" : __DIR__"rroad",
]));
  set("objects", ([
		__DIR__"npc/guard4" : 4,
		__DIR__"npc/zhangmen" : 1,
              	]));
  set("outdoors", __DIR__);
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
   if(phase==4&&(!query("jiangjing"))) jiang_jing(where);
   if(phase==5&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",HIW+"¡è"HIC"Éñ½£É½×¯"NOR+HIW"¡è"NOR+HIY"ÕÆÃÅ´óµÜ×Ó[Zhang men]:"HIG"Éñ½£É½×¯µÜ×ÓÌýÃü,ÏÖÔÚ¿ªÊ¼´«ÊÚ±¾ÃÅ×îÉî»úÃÜ.(Hear) \n"+NOR,users());
   tell_object(where,"Ñ©Ó°ÏÉ·¨¿ÉÎ½ÊÇÐ»Ïþ·å´´Ôì³öÀ´µÄÆæÌØµÄÏÉ·¨.\n");
   set("jiangjing",1);
     set ("long", @LONG

ÕâÀï¾ÍÊÇÎäÁÖÖÐÈË¾¡½ÔÖªµÄÉñ½£É½×¯£¬Àú¾­½­ºþÖÐÁ½°Ù¶àÄêµÄ·çÆðÔÆ
Ó¿£¬¼øÖ¤ÁËÎäÁÖÖÐÁ½°ÙÄêÀ´µÄ²×º£É£Ìï¡£¸ß´óµÄÃÅÂ¥ºÍÔºÇ½Ê÷Á¢£¬ÒòÎª²»
¶ÏÓÐÈË½ø½ø³ö³ö£¬ÕÉ¸ßµÄÖìÄ¾´óÃÅ³¨¿ª×Å£¬ÃÅÇ°ÅÅ×Å¼¸ÅÅÉÏÂíÊ¯¡¢Ë¨Âí×®
¡£ÃÅµÄÉÏ·½¸ß¹Ò×ÅÒ»¸ö½ðÆá´óØÒ£¬ÉÏÃæ²Ô¾¢ÓÐÁ¦µÄÐ´×Å:

                 [37;40m©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©·[0m
                 [37;40m©§[31m   Éñ ½£ É½ ×¯  [37;40m  ©§[0m
                 [37;40m©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿[0m

LONG);
}
void finish_jing(object where)
{
   set("jiangjing",0);
}
int do_hear()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");
   if(!query("jiangjing"))
      return notify_fail("»¹Ã»¿ªÊ¼ÊÚ·¨ÄØ.\n");              
   if((string)me->query("family/family_name")!="Éñ½£É½×¯")
      return notify_fail(CYN"ÕÆÃÅ´óµÜ×ÓËµ:ÍâÅÉµÜ×Ó²»µÃÀ´Ìý½²¡£\n"NOR);
    if(me->query("faith")>400)
      return notify_fail("Äã¾õµÃ×Ô¼º²»ÓÃÔÙÌý½²ÁË¡£\n");
    tell_object(me,"ÄãÈ«Éñ¹á×¢µÄÔÚÌý£¬¼òÖ±¶¼ÈëÁËÃÔ¡£\n");
   me->start_busy(3);
   me->add("faith",1);
   me->add("combat_exp",12);
   me->add("potential",3);
   me->improve_skill("xueying-xianfa",100);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}                                                                    

