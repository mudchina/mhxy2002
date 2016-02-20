// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33m¶şÊ®°ËËŞµî[m");
  set ("long", @LONG

Õâ×ù´óµîÊÇ×¨Îª¶şÊ®°ËËŞÔìµÄ¡£¶şÊ®°ËÎ»ĞÇ¹ÙËäÎªÓñµÛÇÕ·â£¬Êµ
ÔòÀ´ÖÁ¸÷ÃûÉ½´ó´¨£¬ÎåºşËÄº£¡£Æ½Ê±²¢²»ÊÜÓñµÛ½ÚÖÆ£¬Ö»ÊÇÌìÍ¢
ÓĞÁËÖØ´óÊÂÇé²ÅĞûÕÙËûÃÇÉÏÌì¡£¶şÊ®°ËËŞµî±ãÊÇËûÃÇÉÏÌìÊ±µÄÂä
½ÅĞİí¬Ö®´¦¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nanmenting.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"stars/foxer" : 1,
  __DIR__"stars/acer" : 1,
  __DIR__"stars/smallfox" : 1,
   "/u/fly/npc/fly" : 1,
]));

  setup();
}
