// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "Èü³¡´óÃÅ");
  set ("long", @LONG

         ÕâÀïÍ¨Ïò¸÷¸ö±ÈÎäÈü³¡£¬Èç¹ûÄãÑøÁËĞÇ¿ÕÕ½¶·¼¦²»À´Ò»Õ¹
     ÄãµÄĞ¡¼¦µÄ·ç²Ê£¬ÕæÊÇÌ«ÒÅº¶ÁË£¬µ±È»ÁË£¬Èç¹ûÄãÔÚ±ÈÈüÖĞ»ñÊ¤
     »áÓĞ´ó½±µÄ£¬±ÈÈüÃ¿[1;32mÎå[mĞ¡Ê±¾ÙĞĞÒ»´Î¡£

LONG);

  set("outdoors", "changan");
  set("exits", ([ /* sizeof() == 4 */
         "north" : __DIR__"jw",
         "enter":__DIR__"baoming",
]));

        set("no_clean_up",1);
        setup();
}

