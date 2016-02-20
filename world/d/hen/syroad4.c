// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "ÉÌÒµ½Ö");
  set ("long", @LONG

        ÕâÀï·Ç³£ÈÈÄÖ£¬ÓĞ½ÌÌÃ£¬¾Æ°É£¬½ÌÌÃ£¬ÄãÔÚÕâ¿ÉÒÔ×¬µ½ºÜ¶àµÄ
    Ç®£¬Ö»ÒªÄã¿Ï¸É»î£¬×¬Ç®ÊÇÃ»ÓĞÎÊÌâµÄÀ­£¬±±ÃæÊÇÒ»¼Ò[1;35m·¥Ä¾³¡[m£¬ÄÏÃæ
    ÊÇ×¨ÃÅ[1;35m°ÚµØÌ¯µÄµØ·½[m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad3",
         "west": __DIR__"syroad5",
          "north": __DIR__"famu",
         "south": __DIR__"ditan",
]));

        setup();
}
