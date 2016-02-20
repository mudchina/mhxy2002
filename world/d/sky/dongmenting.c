// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
//dongmenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "[35m¶«ÃÅÌü[m");
        set("long", @LONG

½øÁË¶«ÌìÃÅ£¬ÒÑ¾­¿ÉÒÔ¿´µ½Ò»×ù×ùÌì¹¬·Å×ÅÆß²ÊÏ¼¹â£¬ºöÒşºöÏÖ
ÓÚÔÆÕÚÎíÈÆÖ®ÖĞ¡£Ò»×ù°×ÓñÇÅÍäÍäÇúÇúµØÏò±±ÑÓÉì£¬¶«Î÷Á½±ß¸÷
ÓĞÒ»×ù´óµî£¬Ò²²»ÖªÊÇ¸ÉÊ²Ã´ÓÃµÄ£¬Äã¿ÉÒÔÒşÔ¼Ìıµ½¶«±ßµîÄÚË»
Ë»ÂíÃù¡£
LONG
        );
 
        set("exits", ([
                "east" : __DIR__"dongtian",
     "north":__DIR__"yumajian",
        ]));
 
        create_door("east", "¶«ÌìÃÅ", "west", DOOR_CLOSED);
 
        set("objects", ([
                __DIR__"npc/tong-nan" : 2,
        ]));
 
        setup();
}
