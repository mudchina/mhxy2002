//2001.5.22
//by yxm
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set ("short", HIW"Çî¼«Ä§¶´"NOR);
  set ("long", @LONG
ÕâÀï¾ÍÊÇ¹ØÑºÄ§·ðÎÞÌìµÄµØ·½£¬ºÚ°µÖ®Ô¨µÄµØµ×¡£
[1;31m      Çî[2;37;0m
[1;31m      ¼«[2;37;0m
[1;31m      Ä§[2;37;0m
[1;31m      ¶´[2;37;0m
LONG);

  set("objects", ([ 
     __DIR__"npc/wutian" : 1,
]));
        setup();
}
