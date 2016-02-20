// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33mÄÏÃÅÌü[m");
  set ("long", @LONG

½øÁËÄÏÌìÃÅ£¬ÒÑ¾­¿ÉÒÔ¿´µ½Ò»×ù×ùÌì¹¬·Å×ÅÆß²ÊÏ¼¹â£¬ºöÒşºöÏÖ
ÓÚÔÆÕÚÎíÈÆÖ®ÖĞ¡£Ò»×ù°×ÓñÇÅÍäÍäÇúÇúµØÏò±±ÑÓÉì£¬¶«Î÷Á½±ß¸÷
ÓĞÒ»×ù´óµî£¬Ò²²»ÖªÊÇ¸ÉÊ²Ã´ÓÃµÄ£¬Äã¿ÉÒÔÒşÔ¼Ìıµ½¶«±ßµîÖĞÓĞ
Ğú»©Ö®Éù£¬ËÆºõÈË²»ÉÙ¡£Á½¸öĞ¡ÄĞº¢ÕıÔÚÉ¨µØ¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"nantian.c",
  "west": __DIR__"xidian",
  "north" : __DIR__"bridge.c",
  "east" : __DIR__"28xiu-dian.c",
]));

create_door("south", "ÄÏÌìÃÅ", "north", DOOR_CLOSED);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-nan" : 2,
]));

  setup();
}
