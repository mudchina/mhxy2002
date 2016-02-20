// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "[33mÁéÏö±¦µî[m");
  set ("long", @LONG
ÕâÀï¾ÍÊÇÓñµÛËùÔÚµÄÁéÏö±¦µîÁË.µîÉÏµ±ÕæÊÇÏ¼¹âÍòµÀ,ÈğÆøÇ§Ìõ.
ÏÉ¹ÙÏÉ½«ÃÇÁĞÔÚÒ»ÅÔ,±±ÉÏ´¦ÕıÊÇÓñµÛÀÏ¶ùµÄ±¦×ù.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dianmen.c",
  "northup" : __DIR__"dian.c",
]));


  set("objects", ([ /* sizeof() == 1 */
]));

  setup();
}

int valid_leave(object me, string dir)
{  object *inv, container;
    int sizeinv;
  if (dir !="northup")
   return ::valid_leave(me, dir);
   
     if (dir == "northup") 
     inv=all_inventory(me);
     sizeinv=sizeof(inv);
    while (sizeinv--)
   {
       if (userp(inv[sizeinv]))
       {
     container=inv[sizeinv];
     break;
       }
       if (inv[sizeinv]->is_container())
       {
     container=inv[sizeinv];
     break;
       }
       continue;
   }
   if (container)
   {
       message_vision(HIC"¿ÕÖĞ´«À´ÁøËæ·çµÄÉùÒô£ºÄã´ø×ÅÄÇ"+container->name()+
           HIC"½øÈ¥¸ÉÊ²Ã´£¡£¿ÏëÃÉ»ì¹ı¹Ø£¿£¿\n"NOR,me);
        return notify_fail("");

    }
     return ::valid_leave(me, dir);
 
   }


