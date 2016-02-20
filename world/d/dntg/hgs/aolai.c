//sgzl

#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "[33m°ÁÀ´¹ú[m");
set("long", @LONG
    
¶«Ê¤ÉñÖŞº£±ßÒ»Ğ¡¹ú¡£°ÁÀ´¹úÎ÷ÁÙ´óº££¬¶«¿¿»¨¹ûÉ½£¬Ö»ÊÇ
ÔÚÆä¼äÒ»¿éÏÁÕ­µÄÆ½Ô­µØ´øÉÏ½¨ÓĞÒ»×ù³Ç³Ø¡£Ò»Ìõ´óÂ·Ö±Í¨
ÄÏ·½£¬Â·ÉÏĞĞÈËÒ²ÊÇ´Ò´Ò¶ø¹ı¡£
LONG );


set("exits", ([
  "west"   : "/d/changan/aolaiws",
  "east"   : __DIR__"flowerfruit",
  "south"   : __DIR__"northgate",
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
