//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ºóÉ½Ğ¡Ôº");
        set("long", @LONG
ÕâÊÇºóÉ½µÄÒ»×ùĞ¡Ôº£¬²¼ÖÃ¼ò¼òµ¥µ¥£¬³ıÁËÒ»´²¡¢Ò»×À¡¢Ò»ÒÎ¡¢Ò»ÆÑÍÅ£¬
ÔÙÒ²Ã»ÓĞ±ğµÄÊ²Îï¡£±È½ÏÒıÈË×¢Ä¿µÄÊÇÇ½ÉÏ¹Ò×ÅÒ»°Ñ½£¡£ÕâÀï¾ÍÊÇÎäµ±¿ªÉ½
×æÊ¦ÕÅÈı·áµÄÁ·¹¦ËùÔÚ¡£
LONG );
        set("exits", ([
                "north" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
                __DIR__"npc/zhang" : 1,
        ]));
        create_door("north", "ÖñÃÅ", "south", DOOR_CLOSED);
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
