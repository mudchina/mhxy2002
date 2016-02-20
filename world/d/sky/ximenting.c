// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
//ximenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "[33mÎ÷ÃÅÌü[m");
        set("long", @LONG
ÏÖÔÚÕûĞŞÖĞ¡£
LONG
        );
 
        set("exits", ([
                "west" : __DIR__"xitian",
        ]));
 
        create_door("west", "Î÷ÌìÃÅ", "east", DOOR_CLOSED);
 
        set("objects", ([
                __DIR__"npc/tong-nan" : 2,
        ]));
 
        setup();
}
