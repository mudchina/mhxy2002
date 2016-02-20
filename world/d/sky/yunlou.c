// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "[0;31mÔÆÂ¥µî[m");
  set ("long", @LONG

ÔÆÂ¥µîÄËÊÇÍĞËşÌìÍõÖ®¹«ÎñÌÃ£¬ÍĞËşÌìÍõÄËÊÇÌì½çÔªË§£¬ÔÆÂ¥µî
ÊµÄËÊÇÌì½çÖ®¾üÊÂÖĞÊà¡£ÀÈÏÂ½«¾üÌìÍõÁ½ÅÔÁĞ£¬É±ÆøÌÚÌÚ£¬ÌÃÇ°
Ò»¶Ô½ğÖòÈ¼£¬Ö¸µã¹âÃ÷¡£
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "up" : "Ì¨ÉÏ°×ÔÆÈÆÈÆ£¬Ê²Ã´Ò²¿´²»Çå³ş¡£\n",
]));

  set("exits", ([ /* sizeof() == 1 */
    "up": __DIR__"yunloutai",
    "south": __DIR__"yongdao",
  ]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/julingshen" : 1,
]));

  setup();
}


int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("juling shen", environment(me))) && living(a) )
                return notify_fail("¾ŞÁéÉñ¶ÔÄã´óºÈÒ»Éù£ºÎØ£¬ÓëÎÒÉÁ¿ª£¡\n");

        return ::valid_leave(me, dir);
        }

        return 1;
}

