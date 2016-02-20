//by yxm@hxxt.hz
inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short", BLK"ºÚ°µÖ®Ô¨"NOR);
  set ("long", @LONG
[1;31mÕâÀï¾ÍÊÇÍ¨Íù°¢ĞŞÂŞ½çÖ®Â·,Ò»ÌõÍ¨ÏòËÀÍö,[2;37;0m
[1;31mÍ¨ÏòÍ´¿à,Í¨Ïò×ï¶ñµÄºÚ°µÖ®Â·.[2;37;0m
[1;31mËÄÖÜÄ§ÆøÉ­É­,ÈÃÈË²»º®¶øÀõ![2;37;0m
LONG);
  set("exits", ([ /* sizeof() == 4 */
"enter" : "/u/tianlin/°¢ĞŞÂŞ½ç/lu2",
]));
  setup();
}
