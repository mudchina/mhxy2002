//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "[0;35mĞ¡ÏªÇ°[m");
set("long", @LONG
    
ÑÓ×ÅÉ½Â·Ò»×ª£¬Ò»ÌõÇå³ºµÄĞ¡Ïª³öÏÖÔÚÄãµÄÃæÇ°¡£
²ÓÀÃµÄÑô¹âÕÕÒ«ÏÂ£¬Ğ¡ÏªÖĞ²¨¹âÉÁÉÁ£¬²»Ê±»¹ÓĞ
¼¸ÌõÓã¶ùÌø³öË®Ãæ£¬Ê¹ÄãÕæÏëµ½ÏªÖĞÓÎ(swim)Ò»
·­¡£
LONG );


set("exits", ([
  "east"   : __DIR__"shanlu2",
]));


set("objects", ([
  __DIR__"npc/cihu"   : 1,
  __DIR__"npc/huabao"   : 1,
]));



set("outdoors", 1);

setup();
}


void init()
{
add_action("do_swim", "swim");
}

int do_swim()
{
object me = this_player();

message_vision("$N×İÉíÔ¾ÈëĞ¡Ïª¡£\n", me);
me->move(__DIR__"xiaoxi");
message_vision("Ö»¼ûĞ¡ÏªÖĞË®»¨ËÄ½¦£¬¼¸ÌõĞ¡ÓãÌøÁËÆğÀ´¡£\n", me);
return 1;
}

