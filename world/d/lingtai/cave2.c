// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// cave2.c

inherit ROOM;

void create ()
{
  set ("short", "[0;33mÉ½¶´[m");
  set ("long", @LONG

ÈÌ×ÅÁìÈËÖÏÏ¢µÄĞÈÆø£¬Äã×ê½øÒ»¸ö¶´ÖĞ£®¶´¿ÚËä²»´ó£¬ÀïÃæ
È´»¹¿í³¨£®µ«ÂúµØÀÇ¼®£¬µ½´¦ÊÇ¶¯Îï¹ÇÍ·£¬»¹ÓĞÒ»Ğ©±»Ëº³É
ËéÆ¬µÄÊ¬Ìå¡£ÄÏ·½ÊÇÒ»ÌõÒõ°µµÄĞ¡Â·£¬Í¨ÏòÒ»´¦²»ÖªÃûµÄµØ
·½¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youngwolf.c" : 2,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"cave1",
]));

  setup();
}
