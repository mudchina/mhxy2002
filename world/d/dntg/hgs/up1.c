//sgzl

#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "[0;32mÁÖ¼äĞ¡Â·[m");
  set("long", @LONG
    
»¨¹ûÉ½ÖĞµÄÒ»ÌõÁÖ¼äĞ¡Â·¡£ÕâÀï¸ğÌÙ¾À½á£¬¹ÅÄ¾²ÎÌì£¬¾øÉÙ
ÈËĞĞ£¬Ö»ÓĞÒ»Ğ©ºï×ÓÔÚÊ÷¼äµ´À´µ´È¥¡£»¨¹ûÉ½É½ÊÆĞÛÎ°¶ø²»
ÏÕ¾ş£¬ÔÚÉ½¼äĞĞ×ß²¢²»³ÔÁ¦¡£
LONG );


set("exits", ([
  "northup"   : __DIR__"shanlu1",
  "eastup"   : __DIR__"up2",
  "southdown"   : __DIR__"flowerfruit",
]));


set("objects", ([
  __DIR__"npc/monkey2"   : 1,
  __DIR__"npc/monkey1"   : 1,
]));



set("outdoors", 1);

setup();
}
