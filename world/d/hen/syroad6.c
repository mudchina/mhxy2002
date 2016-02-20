// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "ÉÌÒµ½Ö");
  set ("long", @LONG

        ÕâÀï·Ç³£ÈÈÄÖ£¬ÓĞ½ÌÌÃ£¬¾Æ°É£¬½ÌÌÃ£¬ÄãÔÚÕâ¿ÉÒÔ×¬µ½ºÜ¶àµÄ
    Ç®£¬Ö»ÒªÄã¿Ï¸É»î£¬×¬Ç®ÊÇÃ»ÓĞÎÊÌâµÄÀ­£¬±±ÃæÊÇÒ»¼Ò[1;34mÄ¹µØ[m£¬ÄÏÃæ
    ÊÇ[1;34m¼Ò½Ì·şÎñÖĞĞÄ[m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad5",
         "west": __DIR__"meirong",
          "north": __DIR__"mudi",
         "south": __DIR__"jj",
]));

        setup();
}
