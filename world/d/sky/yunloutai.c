// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "[31mÔÆÂ¥Ì¨[m");
  set ("long", @LONG

´ËÄË¹¬ÉÏÒ»Ğ¡Ì¨£¬Ô¶ÍûÏÉ¾³£¬¼û½ğ¹âÍòµÀ¹öºìÏ¼£¬ÈğÆøÇ§ÌõÅç×Ï
ÑÌ¡£Ô¶ÉÏ³¤ÇÅ±ÌÎíÃÉ£¬Ìì¹¬±¦µîÓ³ÔÆ¹â¡£µ±ÕæÊÇÌìÉÏ×ÔÀ´ÓĞÏÉ¾³£¬
²»¶éÈË¼äµãÎÛÄà¡£
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "down": __DIR__"yunlou",
  ]));
  set("objects",([
        __DIR__"npc/leigong":1,
        ]));
  set("outdoors", 1);
  setup();
}


