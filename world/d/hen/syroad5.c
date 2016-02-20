// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "ÉÌÒµ½Ö");
  set ("long", @LONG

        ÕâÀï·Ç³£ÈÈÄÖ£¬ÓĞ½ÌÌÃ£¬¾Æ°É£¬½ÌÌÃ£¬ÄãÔÚÕâ¿ÉÒÔ×¬µ½ºÜ¶àµÄ
    Ç®£¬Ö»ÒªÄã¿Ï¸É»î£¬×¬Ç®ÊÇÃ»ÓĞÎÊÌâµÄÀ­£¬±±ÃæÊÇÒ»¼Ò[1;36m¹¤µØ[m£¬ÄÏÃæ
    ÊÇ×¨ÃÅ[1;36má÷ÁÔµÄµØ·½[m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad4",
         "west": __DIR__"syroad6",
          "north": __DIR__"gongdi",
         "south": __DIR__"shoulie",
]));

        setup();
}
