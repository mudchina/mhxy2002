// ¹ÅÄ¹Èë¿Ú
#include <login.h>
#include <room.h>

inherit ROOM;
void create()
{
set("short","[32mÈë¿Ú[m");
set("long",@LONG

    ÄãÒ²²»ÖªµÀ×Ô¼ºÏÖÔÚÔÚÊ²Ã´µØ·½£¬ËµÊÇÌìÉÏ£¬¿ÉÊÇ×Ô¼º¸Õ²Å
ÊÇÍùµØÏÂ×ªµÄ£¬Äã²»½û¸Ğ¶¯Ò»ÖÖÄªÃûµÄ¿Ö¾å£¬Èç¹ûÃ»ÓĞµ¨Á¿µÄ»°
£¬Äã»¹ÊÇ»ØÈ¥ÎªºÃ£¬ÕâÀï²»ÊÇ»îÈË×¡µÄµØ·½¡£

LONG);
set("exits", ([
         "up" : "/d/eastway/bingma",
         "in" : __DIR__"road1",
]));
set("valid_startroom",1);
setup();

}

