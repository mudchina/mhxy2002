//sgzl

#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "[32m»¨[33m¹û[35mÉ½[m");
set("long", @LONG
    
´ËÉ½ÄËÊ®ÖŞÖ®×æÂö£¬ÈıµºÖ®À´Áú£¬×Ô¿ªÇå×Ç¶øÁ¢£¬ºèÃÉÅĞºó
¶ø³É¡£Õæ¸öºÃÉ½£¡ÓĞ´Ê¸³ÎªÖ¤¡£¸³Ô»£º

¡¡¡¡¡¡¡¡ÊÆÕòÍôÑó£¬³±Ó¿ÒøÉ½ÓãÈëÑ¨£»
¡¡¡¡¡¡¡¡ÍşÄşÑşº££¬²¨·­Ñ©ÀËò×ÀëÔ¨¡£

LONG );


set("exits", ([
  "northup"   : __DIR__"up1",
  "west"   : __DIR__"aolai",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
