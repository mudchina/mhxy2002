// ¹ÅÄ¹Èë¿Ú
inherit ROOM;
void create()
{
set("short","[36mĞŞĞĞÊÒ[m");
set("long",@LONG

    Ç§Íò²»ÒªĞ¡¿´ÁËÕâ¸öµØ·½£¬Ïëµ±ÄêÉÌ´ú½áÊøµÄÊ±ºò£¬æ§¼¸
¾ÍÔÚÕâ¸öµØ·½Îª×Ô¼ºÑ¡ºÃÁËÎÑ£¬ÕâÃ´¶àÄêÀ´ËıÒ»Ö±¶ãÔÚÕâ¸öµØ
·½ĞŞĞĞ£¬ÓÚÊÇµ±½ñÇ¬À¤£¬ÄÜÓëÖ®Æ¥µĞµÄºÜÉÙÁË£¬ÏÖÔÚÕâ¸öµØ·½
ÓÖ³ÉÁËÖÚ¶àĞ¡ºüÀêĞŞĞĞµÄµØ·½£¬¿ÉÄÜÓĞ³¯Ò»ÈÕËûÃÇÒ²ÄÜÏóæ§¼¸
Ò»Ñù·ç¹â¡££¨xiuxing£©

LONG);
set("exits", ([
       "east" : __DIR__"road3",
]));
set("no_clean_up",0);
set("sleep_room",1);
set("if_bed",1);
setup();

}
void init()
{
add_action("do_xiuxing","xiuxing");
}

int do_xiuxing()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("ÄãÕıÃ¦×ÅÄØ¡£\n");
   if((string)me->query("family/family_name")!="ĞùÔ¯¹ÅÄ¹")
      return notify_fail("Äã²»ÊÇÎÒÃÇ ĞùÔ¯¹ÅÄ¹µÄ£¬ÓÃ²»×ÅÀ´ÎÒÃÇÕâĞŞĞĞ¡£\n");
 if(me->query("faith")>200||me->query("combat_exp")>100000)
      return notify_fail("ÄãÒÑ¾­²»ĞèÒªÔÚÕâÖÖµØ·½ĞŞĞĞÁË.\n");
tell_object(me,"ÄãÅÌÍÈ×øÏÂ£¬ÅÅ³ıĞÄÖĞÖÖÖÖÔÓÄî£¬¶ÙÊ±Äã¸Ğ¾õ×Ô¼º·Â·ğ½øÈëÁËÏÉ¾³\n");

   me->start_busy(5);
   me->add("faith",1);
   me->improve_skill("spells",2);
   me->receive_damage("kee",50);
   me->receive_damage("sen",50);
message_vision("$N¾õµÃ·¨Êõ½ø²½ÁË!\n",me);
   return 1;
}
