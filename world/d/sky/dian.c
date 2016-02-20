// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33mÄÚµî[m");
  set ("long", @LONG
ÕâÀï¾ÍÊÇÓñµÛµÄ±¦×ùÁË£¬ÈÔÈ»ÊÇ¿ÕÎŞÒ»ÈË£¬±¦×ùºÀ¹âËÄÉä£¬Äã²»½ûÒ²Ïë
    ÉÏÈ¥×ø×ø¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
]));


  set("objects", ([ /* sizeof() == 1 */
]));

  setup();
}

void init()
{
        object me=this_player();
                remove_call_out("greeting");
                call_out("greeting",5, me);

}

void greeting(object me)
{            int kar,con;

        kar=me->query("kar");
        con=me->query("con");
        if( !me || environment(me) != this_object() ) return;

   message_vision("ºöÈ»Äã½ÅÉÏÒ»Õó×êĞÄµÄÌÛÍ´£¬Ò»Ö»È«ÉíÎÚºÚµÄ´ó¹·ÒÑ¾­ËÀËÀµÄÒ§×¡ÁËÄãµÄĞ¡ÍÈ
£¬Äã¸ÕÏë°ÚÍÑ£¬ÄÔºóÓÖ±»Ò»ÎïÔÒÖĞ£¡\n", me);
   message_vision("±³ºó´«À´Ò»¸ö²ÔÀÏµÄÉùÏ¢£º³¢³¢ÀÏ·ò½ğ¸Õ×ÁµÄÀ÷º¦£¡\n",me);  
  if (random(kar+con)<40)
 {      
   me->set_temp("death_msg","ÉÃ´³ÁéÏö±¦µî£¬ÖĞÏøÌìÈ®Óë½ğ¸Õ×Á°µËãËÀÁË¡£\n");
   me->die();
   me->save();}
   else  
  { me->unconcious();
   me->move("/d/sky/zhanyaotai");}
   return;
}
