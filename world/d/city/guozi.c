//Create By Canoe 2000.11.17
//("combat_exp")>100000||("age")>20)
// literate >80
// + dx,+ pot,+ literate
// ÍíÉÏ¶ÁÊéµÄµØ·½
inherit ROOM;
#include <ansi.h>

string *strs = ({
        " »ìãç³õ·ÖÅÌ¹ÅÏÈ£¬Ì«¼«Á½ÒÇËÄÏóĞü£¬ \n",
        " ×ÓÌì³óµØÈËÒú³ö£¬±Ü³ıÊŞ»¼ÓĞ³²ÏÍ¡£ \n",
        " ìİÈËÈ¡»ğÃâÏÊÊ³£¬·üôË»­ØÔÒõÑôÇ°£¬ \n",
        " ÉñÅ©ÖÎÊÀ³¢°Ù²İ£¬ĞùÔ¯ÀñÀÖ»éÒöÁª¡£ \n",
        " ÉÙê»ÎåµÛÃñÎï¸·£¬ÓíÍõÖÎË®ºé²¨îÃ,  \n",
        " ³ĞÆ½Ïí¹úÖÁËÄ°Ù£¬èîÍõÎŞµÀÇ¬À¤µß¡£ \n",
        " ÖÜÊÒ¿ª»ùÁ¢µÛÍ¼£¬·ÖÃ©ÁĞÍÁ±¨¹¦Êâ.  \n",
     });
void init();
void check_time(object where);
void dushu(object where);
void finish_dushu(object where);
     
void create()
{
  set ("short", "¹ú×Ó¼à");
  set ("long", @LONG

    Õâ¸öµØ·½¾ÍÊÇ´óÌÆ¹ú×Ó¼àµÄÊéÔºÁË,Ò²¾ÍÊÇĞã²ÅÃÇÆ½Ê±ÉÏ¿ÎµÄµØ·½¡£
¸ß¸ßµÍµÍµÄ×À×ÓÅÅÁËÁ½Áï¡£¶«±ßµÄÒ»ÅÅ´°×Ó¶¼¿ª×Å£¬°ÑÎİÖĞÕÕµÄÍ¨ÁÁ¡£
ÕıÃæÒ»×ÀÒ»ÒÎ£¬ÉÏÓĞÎÄ·¿ËÄ±¦¡£Ò»Î»ÀÏÏÈÉúÕı±ÕÄ¿ÑøÉñ¡£Èç¹ûÄãÓĞĞËÈ¤
Ò²µ½ÕâÀïÀ´ËĞĞ©Ê«Êé(dushu)°É!ÔÚÕâÑùµÄ»·¾³Àï,Ò»¶¨»áÊÜÒæ²»ÉÙ.

                [1;35m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[2;37;0m
                [1;35m¡ù                    ¡ù[2;37;0m
                [1;35m¡ù[2;37;0m[1;36m     Êé      Ôº[2;37;0m[1;35m     ¡ù[2;37;0m
                [1;35m¡ù                    ¡ù[2;37;0m
                [1;35m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[2;37;0m

LONG);

  set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"guozijian",
]));
  set("objects", ([ /* sizeof() == 3 */
                __DIR__"npc/zhangsunwuji" : 1,
                __DIR__"npc/xiucai4" : 1,

]));
  set("light_up", 1);

set("start_dushu",1);
  setup();
}

void init()
{
   remove_call_out("check_time");
   check_time(this_object());
   add_action("do_dushu", "dushu");
}

void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   
   if(phase==3&&(!query("start_dushu"))) dushu(where);
   if(phase==6&&query("start_dushu")) finish_dushu(where);
   call_out("check_time",60,where);
}

void dushu(object where)
{
    message("channel:chat",CYN+"¡ó"HIC"´óÌÆÊéÔº"NOR+CYN"¡ó"NOR+WHT"ºØÖªÕÂ(He zhizhang),"HIC"´óÌÆ"HIY"ÊéÔº¿ª¿ÎÁË!´ó¼ÒÀ´¶ÁÊé°É!\n"+NOR,users());
     where->set("start_dushu",1);
} 

int do_dushu()
{ 
     object who=this_player();
     
if (who->query("kee")<20||who->query("gin")<20) return notify_fail("¶ÁÊéÕâÃ´ÓÃ¹¦?»¹ÊÇÏÈÈ¥ĞİÏ¢ĞİÏ¢°É!\n");
if (!who->query("family/family_name")) return notify_fail("ºØÖªÕÂ¶ÔÄãÒ¡Ò¡ÊÖËµ:ÔİÊ±²»ÊÕÃ»ÓĞ°İÊ¦µÄµÜ×Ó.\n");
     if(who->is_busy())
        return notify_fail("ÄãÕıÃ¦×ÅÄØ¡£\n");
     if(!this_object()->query("start_dushu"))
        return notify_fail("ÍíÉÏ²Å¿ª¿Î,»¹²»µ½¶ÁÊéµÄÊ±ºòÄØ¡£\n");
  //   if((int)who->query("combat_exp")<10000) return notify_fail("ÄãµÄÎäÑ§²»¹»½øÈë¹ú×Ó¼àµÄÌõ¼ş.\n");   
     if((int)who->query_skill("literate",1)>80) return notify_fail("ÄãµÄ¶ÁÊéĞ´×ÖÒÑ¾­ÓĞÒ»¶¨ÔìÒèÁË.\n"); 
     if((int)who->query("combat_exp")>100000||(int)who->query("age")>20||(int)who->query("daoxing")>100000)
        return notify_fail("Äã¶¼ÒÑ¾­³ÉÄêÁË,²»ÓÃÀ´ÕâÀï¶ÁÁË°É?\n");
     tell_object( who,"ÄãµÍÃ¼´¹Ä¿£¬¿ÚÖĞÎ¢ËÌ£º"+strs[random( sizeof(strs) )] );
     who->start_busy(random(1));
     who->improve_skill(   "literate",random(  (int)( who->query("spi")+who->query("int") )  )   );
     who->add("daoxing",12);
     who->add("potential",5);
      who->receive_damage("kee",20);
       who->receive_damage("sen",20);
     tell_object(who,"Äã¾õµÃ×Ô¼ºµÄÓÖÁË½âÁËĞ©ÊÀ½çµÄ·¢Õ¹Àú³Ì£¡\n");
     return 1;
}

void finish_dushu(object where)
{
     tell_object(where,"ºØÖªÕÂ¿ÈËÔÁ½Éù,ËµµÀ:Ó¦¸ÃÏÂ¿ÎÀ²,½âÉ¢°É¡£\n");
     where->delete("start_dushu");
}
