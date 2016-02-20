// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "¼¦ÎÑ×ßµÀ");
  set ("long", @LONG

        Äã×ßÔÚ¼¦ÎÑµÄ×ßµÀÉÏ£¬µ½´¦¶¼ÊÇ¼¦½ĞµÄÉùÒô£¬¶«ÃæÊÇ¸ö[1;32m¹«Ô°[m
    ¿ÉÒÔÈ¥É¢É¢²½£¬Î÷ÃæÊÇÒ»¸ö[1;32mÔË¶¯³¡[m¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"gy",
         "west": __DIR__"ydc",
          "north": __DIR__"road4",
         "south": __DIR__"road6",
]));

        setup();
}
