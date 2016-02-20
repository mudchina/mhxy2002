// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "ÉÌÒµ½Ö");
  set ("long", @LONG

        ÕâÀï·Ç³£ÈÈÄÖ£¬ÓĞ½ÌÌÃ£¬¾Æ°É£¬½ÌÌÃ£¬ÄãÔÚÕâ¿ÉÒÔ×¬µ½ºÜ¶àµÄ
    Ç®£¬Ö»ÒªÄã¿Ï¸É»î£¬×¬Ç®ÊÇÃ»ÓĞÎÊÌâµÄÀ­£¬±±Ãæ¿ÉÒÔ[1;36m×öĞ©¼ÒÎñ»î[mw£¬
    ÔÚÄÏÃæÄã¿ÉÒÔ¸ø±ğÈË[1;36mµ±±£Ä·[m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"road4",
         "west": __DIR__"syroad2",
          "north": __DIR__"jiawu",
         "south": __DIR__"baomu",
]));

        setup();
}
