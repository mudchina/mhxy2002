// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "¼¦ÎÑ×ßµÀ");
  set ("long", @LONG

        Äã×ßÔÚ¼¦ÎÑµÄ×ßµÀÉÏ£¬µ½´¦¶¼ÊÇ¼¦½ĞµÄÉùÒô£¬¶«ÃæÓĞÒ»¼Ò[1;32mÒ½Ôº[m
    £¬Î÷ÃæÓĞ¸ö[1;32mÃÄµÇ·å[m£¬Ç§Íò²»Òª´í¹ıÅ¶¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"yy",
         "west": __DIR__"mdf",
          "north": __DIR__"road6",
         "south": __DIR__"jw",
  ]));

        setup();
}
