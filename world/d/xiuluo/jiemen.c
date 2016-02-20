//2001.5.22
//by yxm
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set ("short", HIW"°¢ĞŞÂŞ½çÖ®ÃÅ"NOR);
  set ("long", @LONG
ÃÅ¿Ú´£Á¢Á½×ù¶ñ¹íËÜÏñ£¬ÕÅÑÀÎè×¦£¬ÁîÈË²»º®¶øÀõ£¡
ÕâÀï¾ÍÊÇ´«ËµÖĞµÄ°¢ĞŞÂŞ½çÈë¿Ú£¬Ö»¼ûÃÅÉÏĞ´×Å£º
[1;31m      ½ø     Íò[2;37;0m
[1;31m      ´Ë     ½Ù[2;37;0m
[1;31m      ÃÅ     ²»[2;37;0m
[1;31m      Õß     ¸´[2;37;0m
LONG);
set("exits", ([ /* sizeof() == 1 */
"north" : "/u/tianlin/°¢ĞŞÂŞ½ç/lu1",
]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/egui" : 2,
]));
        setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north") {
        if (objectp(present("xiuluo egui", environment(me))))
        return notify_fail("ĞŞÂŞ¶ñ¹í¹Ö½ĞµÀ£º¡°Äã¸øÀÏ×ÓÕÒËÀÂğ£¿¾¹¸ÒÀ´ÎÒ°¢ĞŞÂŞ½ç£¡\n");
        }

        return ::valid_leave(me, dir);
        }
