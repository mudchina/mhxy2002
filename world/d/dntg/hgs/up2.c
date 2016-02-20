//sgzl

#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "[0;32mÁÖ¼äĞ¡Â·[m");
set("long", @LONG
    
»¨¹ûÉ½ÖĞµÄÒ»ÌõÁÖ¼äĞ¡Â·¡£ÕâÀï¸ğÌÙ¾À½á£¬¹ÅÄ¾²ÎÌì£¬¾øÉÙ
ÈËĞĞ£¬Ö»ÓĞÒ»Ğ©ºï×ÓÔÚÊ÷¼äµ´À´µ´È¥¡£»¨¹ûÉ½É½ÊÆĞÛÎ°¶ø²»
ÏÕ¾ş£¬ÔÚÉ½¼äĞĞ×ß²¢²»³ÔÁ¦¡£ÔÙÍùÉÏºÜ¿ì¾Íµ½É½ÑüÁË¡£
LONG );


set("exits", ([
  "northup"   : __DIR__"entrance",
  "westdown"   : __DIR__"up1",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
