// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[31m´óµîµîÃÅ[m");
  set ("long", @LONG

Õâ¾ÍÊÇÁéÏö±¦µîµÄµîÃÅÁË,ÃÅÉÏ¸ß¸ß¹Ò×ÅÒ»¿éØÒ,ÉÏÃæ¿Ì×ÅÓĞ
¡¸ÁéÏö±¦µî¡¹ËÄ¸ö´ó×Ö,ÖÜÎ§ÓĞÒ»Ğ©Ìì±øÌì½«.ÔÙÍù±±¾ÍÊÇÕıµîÁË.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dadian",
   "south" :__DIR__"bridge",
]));


  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tian-bing" : 3,
  __DIR__"npc/tian-jiang" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
   if (dir == "north" ) {
        if (objectp(present("tian jiang", environment(me))))
   return notify_fail("Ìì½«ºÈµÀ:Î´µÃ±İÏÂĞûÕÙ,²»µÃÈëµî!!\n");
        if (objectp(present("tian bing", environment(me))))
       return notify_fail("Ìì±øº°µÀ£ºÎÒ¼Ò½«¾ü²»ÔÚ£¬Ğ¡ÈË²»¸Ò·ÅÄú½øÈ¥£¡\n");
}
       return ::valid_leave(me, dir);
}
