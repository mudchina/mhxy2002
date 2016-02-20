//By tianlin@mhxy for 2002.1.20

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[33mÏÉÊ¯[m");
  set ("long", @LONG

ÕâÀïÊÇ»¨¹ûÉ½ÑüµÄÒ»¿éÆ½µØ¡£Ò»µÀÆÙ²¼´ÓÉ½¶¥·ÉÁ÷Ö±ÏÂ£¬
ĞºÈëÒ»ÑÛÉîÌ¶£¬µ±ÕæÊÇ£º¡°Ò»ÅÉ°×ºçÆğ£¬Ç§Ñ°Ñ©ÀË·É¡±¡£
ÆÙ²¼±ßÉÏÓĞÒ»¿é´óÊ¯Í·£¬Ïà´«ÎªÌìµØÁéÆøËù»¯¡£²»ÖªÊÇË­ÔÚ
ÉÏÃæ¿ÌÁËÒ»Ê×Ê«£º

¡¡¡¡¡¡¡¡[44m[1;33m»ìãçÎ´·ÖÌìµØÂÒ£¬Ã£Ã£ÃìÃìÎŞÈË¼û¡£[2;37;0m

            [1;35m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
            [1;35m¡ù                    [2;37;0m[1;35m¡ù
            [1;35m¡ù      [2;37;0m[1;31m»¨[1;33m ¹û [1;36mÉ½[2;37;0m      [2;37;0m[1;35m¡ù
            [1;35m¡ù                    [2;37;0m[1;35m¡ù
            [1;35m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
                 
¡¡¡¡¡¡¡¡[41m[1;37m×Ô´ÓÅÌ¹ÅÆÆºèÃÉ£¬¿ª±Ù´Ó×ÈÇå×Ç±æ¡£[2;37;0m

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/ourhome/npc/longear" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"houshan1",
  "southdown" : __DIR__"up2",
]));

  setup();
}


void init()
{
   add_action("do_push", "push");
}

int valid_leave(object me, string dir)
{
   object mbox;

   if( mbox = me->query_temp("mbox_ob") ) {
     tell_object(me, "Äã½«ĞÅÏä½»»Ø¸øÓÊ²î¡£\n");
     destruct(mbox);
   }
   return 1;
}

void check_trigger()
{
   object room;

   if( (int)query("left_trigger")==3
   &&   (int)query("right_trigger")==5
   &&   !query("exits/down") ) {
     message("vision", "ÏÉÊ¯ºöÈ»·¢³öÔşÔşµÄÉùÒô£¬Â¶³öÒ»¸öÏòÏÂµÄ½×Ìİ¡£\n",
        this_object() );
if( !(room = find_object(__DIR__"inner_shuiliandong")) )
room = load_object(__DIR__"inner_shuiliandong");

     if( room = find_object(__DIR__"inner_shuiliandong") ) {
set("exits/down", __DIR__"inner_shuiliandong");
        room->set("exits/up", __FILE__);
        message("vision", "ÏÉÊ¯ºöÈ»·¢³öÔşÔşµÄÉùÒô£¬Â¶³öÒ»¸öÏòÉÏµÄ½×Ìİ¡£\n",
          room );
     }
     delete("left_trigger");
     delete("right_trigger");
     call_out("close_passage", 10);
   }
}

void close_passage()
{
   object room;

   if( !query("exits/down") ) return;
   message("vision", "ÏÉÊ¯ºöÈ»·¢³öÔşÔşµÄÉùÒô£¬½«ÏòÏÂµÄÍ¨µÀ¸Ç×¡ÁË¡£\n",
     this_object() );
   if( room = find_object(__DIR__"inner_shuiliandong") ) {
     room->delete("exits/up");
     message("vision", "ÏÉÊ¯ºöÈ»·¢³öÔşÔşµÄÉùÒô£¬ÏòÉÏµÄÍ¨µÀÓÖ»º»ºµØ±»¸Ç×¡ÁË¡£\n",
        room );
   }
   delete("exits/down");
delete("left_trigger");
delete("right_trigger");
}


int do_push(string arg)
{
   string dir;
   object me=this_player();

   if( !arg || arg=="" ) return 0;

   if( arg=="stone" ) {
     write("ÄãÊÔ×ÅÍÆ¶¯ÏÉÊ¯£¬ËÆºõ¿ÉÒÔ×óÓÒ»¬¶¯....\n");
delete("left_trigger");
delete("right_trigger");
     return 1;
   }
   if( sscanf(arg, "stone %s", dir)==1 ) {
     if( dir=="right" ) {
if(query("exits/down")) return notify_fail("ÏÉÊ¯ÒÑ¾­±»ÍÆ¿ªÁË¡£\n");
        message_vision("$N½«ÏÉÊ¯ÍùÓÒÍÆ...£¬ºöÈ»¡¸¿¦¡¹Ò»ÉùÏÉÊ¯ÓÖÒÆ»ØÔ­Î»¡£\n", me);
        add("right_trigger", 1);
        check_trigger();
        return 1;
     } else if( dir=="left" ) {
if(query("exits/down")) return notify_fail("ÏÉÊ¯ÒÑ¾­±»ÍÆ¿ªÁË¡£\n");
        message_vision("$N½«ÏÉÊ¯Íù×óÍÆ...£¬ºöÈ»¡¸¿¦¡¹Ò»ÉùÏÉÊ¯ÓÖÒÆ»ØÔ­Î»¡£\n", me);
        add("left_trigger", 1);
        check_trigger();
        return 1;
     } else {
        write("ÄãÒª½«ÏÉÊ¯ÍùÄÄ±ßÍÆ£¿\n");
        return 1;
     }
   }
}


void reset()
{
   ::reset();
   delete("left_trigger");
   delete("right_trigger");
}

