#include <ansi.h>
inherit ROOM;
string *msgs = ({
  "Çó¾­Õß£¬ÍòÔµ¶¼°Õ¡£",
  "ÁËÐÔÕß£¬Öî·¨½Ô¿Õ¡£",
  "´óÖÇÏÐÏÐ£¬å£²´ÔÚ²»ÉúÖ®ÄÚ¡£",
  "Õæ»úÄ¬Ä¬£¬ÏûÒ£ÓÚ¼ÅÃðÖ®ÖÐ¡£",
  "Èý½ç¿Õ¶ø°Ù¶ËÖÎ£¬Áù¸ù¾»¶øÇ§ÖÖÇî¡£",
  "ÈôÄË¼á³ÏÖª¾õ£¬Ðëµ±Ê¶ÐÄ¡£",
  "ÐÄ¾»Ôò¹ÂÃ÷¶ÀÕÕ£¬ÐÄ´æÔòÍò¾³½ÔÇå¡£",
  "ÕæÈÝÎÞÇ·ÒàÎÞÓà£¬ÉúÇ°¿É¼û¡£",
  "»ÃÏàÓÐÐÎÖÕÓÐ»µ£¬·ÖÍâºÎÇó¡£",
  "ÐÐ¹¦´ò×ø£¬ÄËÎªÈë¶¨Ö®Ô­¡£",
  "²¼»ÝÊ©¶÷£¬³ÏÊÇÐÞÐÐÖ®±¾¡£",
  "´óÇÉÈô×¾£¬»¹ÖªÊÂÊÂÎÞÎª¡£",
  "ÉÆ¼Æ·Ç³ï£¬±ØÐëÍ·Í··ÅÏÂ¡£",
  "µ«Ê¹Ò»ÐÄ²»¶¯£¬ÍòÐÐ×ÔÈ«¡£",
  "ÈôÔÆ²ÉÒõ²¹Ñô£¬³ÏÎªÃýÓï£¬·þ¶ü³¤ÊÙ£¬ÊµÄËÐé´Ê¡£",
  "Ö»Òª³¾³¾Ôµ×ÜÆú£¬ÎïÎïÉ«½Ô¿Õ¡£",
  "ËØËØ´¿´¿¹Ñ°®Óû£¬×ÔÈ»ÏíÊÙÓÀÎÞÇî¡£",
});

void create ()
{
  set ("short", "´óÑ©É½ÁéðÕÃÜÊÒ");
  set ("long", @LONG
[1;33mÕâÀï¾ÍÊÇµ±ÄêÈçÀ´·ð×æµÃµÀ³É·ðµÄµØ·½´óÑ©É½ÁéðÕ¶´ÃÜÊÒ,[2;37;0m
[1;33mÏÖÔÚÊÇ·ðÄ¸-[2;37;0m-[1;33m¿×È¸´óÃ÷ÍõÆÐÈøµÄµÀ³¡£¬[2;37;0m
[1;33mÕâÀïÏÉÆøËÄÒç£¬²»À¢Îªµ±ÊÀÐÞ·ðÕßÃÎÃÂÒÔÇóµÄÊ¥µØ¡£[2;37;0m
LONG);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kongque" : 1,
]));
  set("no_magic", 1);
  setup();
}
void init ()
{
  add_action ("do_canwu", "canwu");
  add_action("do_out","out");
add_action("do_action", ({"ji","cast"}));  
}
int do_action(string arg)
{
        write("Ã»ÓÐ²ÎÎò¾ÍÏëÅÜÁË?\n");
        return 1;
}
int do_canwu ()
{        object m;

  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("xiuluo/lingjiu_canwu");
  int j;

       if( who->query("xiuluo/lingjiu_ok") == 1 ) 
   return notify_fail ("ÄãÒÑ¾­ºÜÃ÷°×ÁË£¬Äã»¹ÐèÒª²ÎÎòÂð£¿\n");

  if (who->is_busy())
    return notify_fail ("ÄãÕýÃ¦×ÅÄØ£¡\n");

  message_vision ("$NÅÌÏ¥¶ø×ø£¬¿ªÊ¼²ÎÎòÁéðÕ¶´ÖÐµÄ°ÂÃî¡£\n",who);
  if (i >= size)
  {      
    message_vision ("\n$N³ÁË¼ÉÙÇê£¬¾õµÃÒÑ¾­ÁìÎòµ½ÁËÁéðÕ¶´ÖÐµÄÃØÃÜ¡£\n",who); 
    message_vision("$NÕ¾ÆðÉíÀ´£¬Ïò¶´¶¥ÖÐÐÄÍûÈ¥£¬¶ÙÊ±ÁéÌ¨Ò»Æ¬ÇåÃ÷(out dong)¡£\n", who);
    who->set("xiuluo/lingjiu_ok",1);  
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_canwu",5,who,i);
    call_out ("finish_canwu",j,who);
  }
  return 1;
}
void start_canwu (object who, int i)
{
//  message_vision ("\n$NÄîµÀ£º"+msgs[i]+"\n",who); 
//  message_vision ("\nÆ¬¿Ì£¬$N¿ªÊ¼²ÎÎòÁéðÕ¶´ÖÐµÄÃØÃÜ¡£\n",who); 
  who->set_temp("xiuluo/lingjiu_canwu",i+1);
}

void finish_canwu (object who)
{
  object where = environment(who);

  who->interrupt_me ();
  message_vision ("\n$N²ÎÎòÍê±Ï£¬Õ¾ÁËÆðÀ´£¬ËÆºõ»¹Ã»ÓÐÁìÎòµ½ÁéðÕ¶´ÖÐµÄÃØÃÜ¡£\n",who); 
  // much slower than normal speed, just a symbolic reward
  where->add("times",1);
  if (where->query("times") < 1)
  {
    who->add("potential",random(3)+1);
    tell_object(who,"Äã·¢¾õ×Ô¼ººÃÏóµÃµ½ÁËÊ²Ã´¶«Î÷Ò»Ñù£¡\n");
  }
}
int do_out(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="dong") return 0;
        write("ÄãÔËÁ¦Ë«±Û£¬Ë«ÊÖ·ö×ÅÒ»¿éÑÒÊ¯£¬´óºÈÒ»Éù£º¡°¿ª£¡¡±\n");
       if( me->query("xiuluo/lingjiu_ok") != 1 ) 
                {
                write("ÄãÃ»ÓÐ²ÎÎò³ö¶´ÖÐµÄ°ÂÃØ£¬ÎÞÂÛÈçºÎÊÇ³öµÄÈ¥µÄ¡£\n");
                return 1;
                };
        write("¶´¶¥¿ªÊ¼»º»º×ª¶¯£¬É²Ê±¼äÄã»Øµ½ÁËÁéÉ½½ÅÏÂ¡£\n");
        me->move("/d/qujing/lingshan/shanjiao");
        return 1;
}
