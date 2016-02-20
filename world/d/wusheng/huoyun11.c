// changan wusheng
// baiyu11.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "»ğÔÆ¶´");
  set ("long", @LONG

¶´ÄÚºì¹âÉÁÉÁ£¬ÕóÕóÊŞÃùÔÚ¶´ÄÚ»Øµ´£¬Ë¿Ë¿ĞÈÎ¶´ßÈËÓûÔÎ¡£
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north": __DIR__"huoyun"+sprintf("%d",random(20)),
  "northeast": __DIR__"huoyun"+sprintf("%d",random(20)),
  "northwest": __DIR__"huoyun12",
]));

  set("no_clean_up", 1);
  setup();
}
int clean_up()
{
      return 0;
}
