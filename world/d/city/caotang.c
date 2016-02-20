//by tianlin@MHXY.2001.7.4ĞŞ¸Ä
inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short","Ô¬ÊÏ²İÌÃ");
        set ("long", @LONG

ÕâÀïÊÇÔ¬ÊØ³ÏÏÈÉúËãØÔ²â×ÖµÄµØ·½¡£ÌáÆğÔ¬ÊØ³Ï£¬³¤°²³ÇÖĞÎŞÈË²»Ïş£¬
ËûÄËÊÇµ±³¯ÇÕÌì¼àÌ¨ÕıÏÈÉúÔ¬Ììî¸µÄÊå¸¸¡£Ğ¡ÎİÀïÕûÈÕ·Ã¿ÍÂçÒï²»¾ø¡£
ÌÃÉÏ¹ÒÒ»·ù¶ÔÁª£¬ÄËÊÇ£º
            [35mÖªĞ×¶¨¼ª£¬¿ªÌ¸·çÓêÑ¸[2;37;0m
            [33m¶ÏËÀÑÔÉú£¬ÏÂ±Ê¹íÉñ¾ª[2;37;0m
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"baihu-w3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shouchen" : 1,
		__DIR__"npc/xiushi" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



