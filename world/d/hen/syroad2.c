// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "ÉÌÒµ½Ö");
  set ("long", @LONG

        ÕâÀï·Ç³£ÈÈÄÖ£¬ÓĞ½ÌÌÃ£¬¾Æ°É£¬½ÌÌÃ£¬ÄãÔÚÕâ¿ÉÒÔ×¬µ½ºÜ¶àµÄ
    Ç®£¬Ö»ÒªÄã¿Ï¸É»î£¬×¬Ç®ÊÇÃ»ÓĞÎÊÌâµÄÀ­£¬±±ÃæÊÇÒ»¼Ò[1;31mÂÃ¹İ[m£¬ÄÏÃæ
    ÊÇÒ»¸ö[1;31m´óÅ©³¡[m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad1",
         "west": __DIR__"syroad3",
          "north": __DIR__"luguan",
         "south": __DIR__"nongchang",
]));

        setup();
}
