// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "¼¦ÎÑ×ßµÀ");
  set ("long", @LONG

        Äã×ßÔÚ¼¦ÎÑµÄ×ßµÀÉÏ£¬µ½´¦¶¼ÊÇ¼¦½ĞµÄÉùÒô£¬¶«ÃæÊÇ¸ö[1;32m·ç¾°Çø[m
    ¿ÉÒÔÈ¥É¢É¢²½£¬Î÷ÃæÓĞ¸ö[1;32mKTV°üÏá[m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"fjq",
         "west": __DIR__"ktv",
          "north": __DIR__"road5",
         "south": __DIR__"road7",
]));

        setup();
}
