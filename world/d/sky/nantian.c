// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "[33mÄÏÌìÃÅ[m");
  set ("long", @LONG

ÕâÀï¾ÍÊÇÌì¹¬µÄÄÏÃÅ£¬Ö»¼û½ğ¹âÍòµÀ£¬ÈğÆøÇ§Ìõ¡£ÄãÒ»Ê±¼ä¾õ
µÃÓĞĞ©²»ÖªËù´ë£¬¶¨ÁË¶¨Éñ£¬²Å·¢ÏÖÃÅÊÇÁğÁ§Ôì¾Í£¬±¦Óñ×±³É¡£
ÆøÅÉ·Ç·²¡£½øÁËÕâÒ»µÀÃÅ£¬¾ÍÊÇÌì¹¬ÁË¡£ÍùÃÅÄÚÍûÈ¥£¬Ö»¼ûÔÆ
ÕÚÎíÈÆ£¬Ò»×ù×ù¹¬µîÒşÒşÔ¼Ô¼µØ¿´²»´óÇåÎú¡£Ôö³¤ÌìÍõÊÖ³Ö³¤
Ç¹£¬Õı´ø×Å¼¸¸öÌì±øÌì½«ÔÚÕâÀïÑ²Âß¡£

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/zz-tianwang" : 1,
//  __DIR__"npc/tian-ding2" : 1,
//  __DIR__"npc/tian-ding1" : 1,
  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"sw1",
  "north" : __DIR__"nanmenting",
  "east" : __DIR__"se1",
//
    
]));
create_door("north", "ÄÏÌìÃÅ", "south", DOOR_CLOSED);

  setup();
}
 
int valid_leave(object me, string dir)
{
 
        if (dir != "north") {
                return ::valid_leave(me,dir);
        }
 
 
        if (objectp(present("zengzhang tianwang", environment(me)))) {
 
                if (me->query("combat_exp")<100000) {
return notify_fail(HIY"Ôö³¤ÌìÍõ¶ÔÄãËµµÀ£º" + RANK_D->query_respect(me) +"ËÆºõ»¹Î´ÈëÏÉµÀ£¬»ØÈ¥¶àÏÂµã¿à¹¦°É¡£\nÄãÂú»³Ê§ÍûµÄÀë¿ªÁË¡£\n"NOR);

                }
                else {
return notify_fail(HIY"Ôö³¤ÌìÍõ¶ÔÄã¹°ÊÖ×÷ÁË¸öÒ¾£ºÕâÎ»" + RANK_D->query_respect(me) +"£¬ÊµÔÚ¶Ô²»Æğ¡£ÌìÍ¥ÕıÔÚ×¼±¸ó´ÌÒ´ó»á£¬Ôİ²»½Ó´ıÍâ¿Í¡£\n¿´À´µÃÏÂ´ÎÁË¡£\n"NOR);
                }
        }
return ::valid_leave(me,dir);
}
