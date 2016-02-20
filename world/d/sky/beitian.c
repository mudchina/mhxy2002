// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
//beitian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "[31m±±ÌìÃÅ[m");
  set ("long", @LONG

    ÕâÀïÊÇÌì¹¬µÄ±±ÃÅ¡£Óñ»Ê´óµÛµÄ±¦×ùÊÇ×ø±±³¯ÄÏµÄ£¬ËùÒÔ³ıÁËÓĞ
ÌØÊâÊ¥Ö¼»òÓñµÛµÄÇ×ĞÅÖ®Íâ£¬Ã»ÈË¸Ò´ÓÕâÀï³öÈë¡£±ÈÆğÄÏÌìÃÅÀ´£¬±±
±ß¿É¾ÍÀäÇå¶àÁË¡£ËäÈ»Èç´Ë£¬±±ÌìÃÅÔìµÄ¿ÉË¿ºÁ²»º¬ºı¡£ÏÊºìµÄ´óÃÅ
ÉÏÏâ×ÅÉÁÉÁ·¢¹âµÄÍ­¶¤£¬ÏÔµÃÍşÎä·Ç·²¡£»¤¹úÌìÍõÁì×Å´óÁ¦Ìì¶¡ºÍÖÚ
Ìì±ø£¬Ò»Ë¿²»¹¶µÄÑ²Âß×Å¡£

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("objects", ([ /* sizeof() == 4 */
//  __DIR__"npc/tian-ding2" : 1,
//  __DIR__"npc/tian-ding1" : 1,
  __DIR__"npc/hg-tianwang" : 1,
  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nw1",
  "south" : __DIR__"beimenting",
  "north" : __DIR__"yun",
  "east" : __DIR__"ne1",
]));
create_door("south", "±±ÌìÃÅ", "north", DOOR_CLOSED);

  setup();
}

int valid_leave(object me, string dir)
{
 
        if (dir == "north") {
           message_vision ("$N×İÉíÌøÈëÔÆº£ÖĞ£¡\n",me);
           return ::valid_leave(me,dir);
        }
        if (dir != "south") {
                return ::valid_leave(me,dir);
        }
 
 
if (objectp(present("huguo tianwang", environment(me)))) {
 
if (me->query("combat_exp")>100000) 
return notify_fail(HIY"»¤¹úÌìÍõ¶ÔÄã¹°ÊÖ×÷ÁË¸öÒ¾£ºÕâÎ»" + RANK_D->query_respect(me) +"£¬ÊµÔÚ¶Ô²»Æğ¡£ÈôÏë½øÈ¥»¹ÊÇ´ÓÄÏÃÅ×ß°É¡£\n¿´À´ÕâÀï²»ÄÜ½ø¡£\n"NOR);
else
return notify_fail(HIY"»¤¹úÌìÍõÀ÷ÉùËµµÀ£º´ËÄËÌì¹¬ÖØµØ£¬ÏĞÔÓÈËµÈ²»µÃÈëÄÚ£¡\nÄãÂú»³Ê§ÍûµÄÀë¿ªÁË¡£\n"NOR);
        }
return ::valid_leave(me,dir);
}

