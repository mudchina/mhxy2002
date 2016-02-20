// changan wusheng
// shijie5.c

inherit ROOM;

void create()
{
  set ("short", "Ê¯½×·");
  set ("long", @LONG

¾­¹ı´óµî£¬×ßÈëÕâÀï£¬·ç¾°·ÂÈçÏÉ¾³£¬ÓëÉ½Ç°µÄÊ¯Â·¼òÖ±ÊÇÁ½¸ö
½ØÈ»²»Í¬µÄ¸Ğ¾õ¡£Ì§Í·ÍüÈ¥£¬Ò»×ù¸ßËÊÈçÔÆµÄÇÍ±Ú¶¥Ìì¶øÁ¢¡£
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"shijie6",
"south": __DIR__"room1",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

