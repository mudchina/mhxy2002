//By tianlin@mhxy for 2001.9.18

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "Ë´Íõ½Ö");
  set ("long", @LONG

Ë´Íõ½ÖÄÏ±±Ë«ÏòÍ¨ĞĞ£¬Óë³ÇÀïµÄÁíÒ»Ìõ´ó½ÖÒ¢Íõ½Ö²¢ĞĞ£¬´©¹ı¿ª·âµÄ
ÄÖÊĞÇøµØ´ø¡£½ÖµÀÓÉÒ»É«ÇàÊ¯³¤ÌõÆÌ³É¡£½ÖµÄÁ½±ßÊÇ¸÷ÖÖ¸÷ÑùµÄ¸®Õ¬
µêÆÌ£¬Î÷±ßÓĞÒ»ÕĞÅÆ£º¡°[37m´º[35m´¼[33m²è[36mÕ»[2;37;0m¡±¡£

LONG);

  set("exits", ([
        "southeast" : __DIR__"tieta",
        "north" : __DIR__"shun4",
        "west" : __DIR__"chunchun",
      ]));

  set("outdoors", __DIR__);

  setup();
}


