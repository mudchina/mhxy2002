// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "ÉÌÒµ½Ö");
  set ("long", @LONG

        ÕâÀï·Ç³£ÈÈÄÖ£¬ÓĞ½ÌÌÃ£¬¾Æ°É£¬½ÌÌÃ£¬ÄãÔÚÕâ¿ÉÒÔ×¬µ½ºÜ¶àµÄ
    Ç®£¬Ö»ÒªÄã¿Ï¸É»î£¬×¬Ç®ÊÇÃ»ÓĞÎÊÌâµÄÀ­£¬±±ÃæÊÇÒ»¼Ò[1;33m²ÍÌü[m£¬ÄÏÃæ
    ÊÇÒ»¸ö[1;33m½ÌÌÃ[m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad2",
         "west": __DIR__"syroad4",
          "north": __DIR__"canting",
         "south": __DIR__"jiaotang",
]));

        setup();
}
