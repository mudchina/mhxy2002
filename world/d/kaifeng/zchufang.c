// Room: /d/kaifeng/zchufang
// by cih 10/01/2002
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "Ë§¸®³ø·¿");
  set ("long", @LONG

ÕâÀïÊÇÌìÅîÔªË§¸®ÃÅÈËµÜ×ÓÃÇ³Ô·¹µÄ³¡Ëù¡£ÒòÎªÔªË§¸®µÄ
µÜ×Ó¶¼ÌØ±ğµÄÄÜ³Ô£¬ËùÒÔÕâÀï°Ú×Å¸÷ÖÖ¸÷ÑùµÄÊ³Îï¡£·½±ã
ÔªË§¸®µÄµÑ×Ó¿ÉÒÔËæÊ±ËæµØµÄÀ´³Ô¡£

            [1;37m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[2;37;0m
            [1;37m¡ù                    ¡ù[2;37;0m
            [1;37m¡ù[2;37;0m      [1;33mÃÀÊ³²Í¹İ[2;37;0m[1;37m      ¡ù[2;37;0m
            [1;37m¡ù                    ¡ù[2;37;0m
            [1;37m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[2;37;0m

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shuaifu",
]));
  set("objects", ([ /* sizeof() == 4 */
  "/d/obj/food/bao3" : 3,
  "/d/obj/food/baozi" : 3,
  "/d/obj/food/chahu" : 3,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
int valid_leave()
{
        if((present("bao", this_player())))
            return notify_fail("ÔªË§ÓĞÁî£ºÎªÁËÖíµÜ×ÓµÄ½¡¿µ£¬Ö»ÄÜ³ÔÍêÁËÔÚ×ß£¡\n");
    return ::valid_leave();
}
