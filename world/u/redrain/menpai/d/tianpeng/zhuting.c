#include <ansi.h>

inherit ROOM;
void create ()
{
      set ("short", HBMAG+HIY" ´äÖñÍ¤ "NOR);
  set ("long", @LONG

          [1;32m  ´ä   Öñ   Í¤   [2;37;0m

ÕâÀïÊÇÓÉ´äÖñ×ö³ÉµÄÍ¤×Ó£¬ÕâÀï±ğ¾ßÒ»¸ñ£¬
¸ßÀÏ×¯µÄÈıĞ¡½ã´äÀ¼£¬¾­³£×øÔÚÕâÀïµÄÖñÒÎ
ÉÏÓÎÀÀÖñÁÖÖĞµÄ¾°É«¡£

LONG);

  set("exits", ([
              "out" : __DIR__"zhulin7",
      ]));
  set("objects", ([
        __DIR__"npc/lan"   : 1,
        __DIR__"npc/cui"   : 1,
      ]));

  setup();
}


