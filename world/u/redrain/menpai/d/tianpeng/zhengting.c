#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", HBRED" ÌìÅî¸®ÕıÌü "NOR);
  set ("long", @LONG

ÕâÀï²¼ÖÃµÄÆÄÎªÓÅÑÅ£¬¼¸¸ö¼Ò½«Õ¾Á¢Á½ÅÔ£¬Ò²ĞíÊÇÒòÎªÃ»
ÓĞÈËËµ»°£¬ÌüÉÏµÄÆø·ÕºÜÑÏËà¡£

              [1;37m  Ìì    Åî    ¸®    µÚ[2;37;0m

LONG);

  set("exits", ([
          "north"   : "/d/tianpeng/lu",
        "west"   : "/d/kaifeng/shuaifu",
               "south" : __DIR__"pianting",
      ]));
  set("objects", ([
        __DIR__"npc/zhangmen"   : 1,
      ]));

  setup();
}


