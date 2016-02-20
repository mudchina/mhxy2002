// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33mÁéÏö±¦µî[m");
  set ("long", @LONG
ÕâÀï¾ÍÊÇÓñµÛËùÔÚµÄÁéÏö±¦µîÁË.µîÉÏµ±ÕæÊÇÏ¼¹âÍòµÀ,ÈğÆøÇ§Ìõ.
ÏÉ¹ÙÏÉ½«ÃÇÁĞÔÚÒ»ÅÔ,±±ÉÏ´¦ÕıÊÇÓñµÛÀÏ¶ùµÄ±¦×ù.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dianmen2.c",
"northup" : __DIR__"neidian.c",
]));


  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/julingshen" : 1,
  __DIR__"npc/erlang" : 1,
  __DIR__"npc/lijing" : 1,
  __DIR__"npc/guard"  : 5, 
]));

  setup();
}
int valid_leave(object me, string dir)
{
        object a;
        if( wizardp(me)) return 1;

        if (dir == "northup") {
                if(objectp(a=present("erlang zhenjun", environment(me))) && living(a))
                return notify_fail("¶şÀÉÉñÉíĞĞÒ»ÉÁ,µ²ÔÚÁËÄãµÄÃæÇ°¡£\n");
                if(objectp(a=present("li jing", environment(me))) && living(a))
                return notify_fail("Àî¾¸ÉíĞĞÒ»ÉÁ,µ²ÔÚÁËÄãµÄÃæÇ°¡£\n");
return ::valid_leave(me, dir);
        }

        return 1;
}
