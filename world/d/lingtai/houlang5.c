// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "[0;33mÁÖÖĞÄ¾Îİ[m");
  set ("long", @LONG

³¤ÀÈµÄ¾¡Í·ÏÖ³öÒ»¸öĞ¡Ä¾Îİ£¬Ä¾Îİ´ÓÍâ±ß¿´ÆğÀ´²»´ó£¬ÖÜÎ§Ò²ºÜ
°²¾²£¬Ìı²»µ½Ò»Ë¿ÉùÏì¡£Ææ¹ÖµØÊÇ´ÓÄ¾°åµÄ·ìÏ¶ÖĞÍ¸³ö¼¸Ğíºì¹â¡£
ÕıÃæÒ»ÉÈÄ¾ÃÅ½ô±Õ¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"houlang4",
  "enter": __DIR__"room",
]));

  setup();
}
/*
void init()
{
        add_action("do_knock", "knock");
}

int do_knock(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "door") ))
                return notify_fail("ÄãÒªÇÃÊ²Ã´£¿\n");

   message_vision("$NÇáÇáµÄÀ­ÆğÃÅÉÏµÄÍ­»·£¬£¢Å¾£¬Å¾£¢µØ¿ÛÁËÁ½ÏÂ¡£\n",me); 
   message_vision("ÃÅ±»ÇáÇáÀ­¿ª£¬×ß³öÎ»ÖĞÄêµÀÈË£¬ÉÏÏÂ´òÁ¿ÁË$NÒ»·¬¡£\n",me);
   if((string)me->query("family/family_name")=="·½´çÉ½ÈıĞÇ¶´") {
        if(((int)me->query("combat_exp") < 100000)) {
        message_vision("ÖĞÄêµÀÈË¶Ô$NĞ¦µÀ£ºµÀĞÖÒ²À´°İ¼û×æÊ¦Âğ£¿\n",me);
        message_vision("$NËæ×ÅÖĞÄêµÀÈË×ßÁË½øÈ¥¡£\n",me);
                   tell_room( environment(me), "ÃÅÓÖÇáÇáµÄ¹ØÉÏÁË¡£\n",({me}));
                   me->move("/d/lingtai/room");
                   tell_room( environment(me), me->name() + "×ßÁË½øÀ´¡£\n",({me}));
        return 1;
        }
     message_vision("$NËæ×ÅÖĞÄêµÀÈË×ßÁË½øÈ¥¡£\n",me);
     tell_room( environment(me), "ÃÅÓÖÇáÇáµÄ¹ØÉÏÁË¡£\n",({me}));
                me->move("/d/lingtai/room");
     tell_room( environment(me), me->name() + "×ßÁË½øÀ´¡£\n",({me}));
                return 1;
     }
        message_vision("ÖĞÄêµÀÈËÖåÁËÖåÃ¼Í·£ºÇĞÄª¾ÃÁô£¬ÈÅÎÒ×æÊ¦ÇåĞŞ£¡\n", me);
   message_vision("$NËæ×ÅÖĞÄêµÀÈË×ßÁË½øÈ¥¡£\n",me);
        tell_room( environment(me), "ÃÅÓÖÇáÇáµÄ¹ØÉÏÁË¡£\n",({me}));
        me->move("/d/lingtai/room");
        tell_room( environment(me), me->name() + "×ßÁË½øÀ´¡£\n",({me}));


   return 1;

}


*/
