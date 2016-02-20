// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
//dongmenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "[0;33mÓùÂí¼à[m");
        set("long", @LONG

ÓùÂí¼à¼àÄÚ²»´ó£¬°ÚÉèÒ²ÊÇÆ½³£¡£ÓĞ¼àØ©µä²¾¶şÈËÁ½±ßÊÌÁ¢£¬ÒÔ
±¸ÓĞÌì½«À´Õ÷ÓÃÂíÆ¥¡£¶«ÓĞÄ¾ÃÅÒ»ÉÈ£¬ÃÅºó±ãÊÇÓùÂí¼àÖĞÂí³¡£¬
Òş¼ûÁ¦Ê¿À´»Ø´ß°ì£¬¿¥ÂíÔÜÌã²»Ï¢£¬ºÜÊÇÈÈÄÖ¡£
LONG
        );
 
        set("exits", ([
                "south" : __DIR__"dongmenting",
        ]));
    set("no_fight",1);
   set("no_magic",1);
 
        set("objects", ([
                __DIR__"npc/jiancheng" : 1,
     __DIR__"npc/dianbu": 1,
        ]));
 
        setup();
}
