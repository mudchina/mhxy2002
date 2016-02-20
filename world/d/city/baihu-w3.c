//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","°×»¢´ó½Ö");
        set ("long", @LONG

ÕâÀïÒÑÊÇ°×»¢´ó½ÖµÄÎ÷¶Î£¬±±ÃæĞ¡ÏïÀïÒşÔ¼¿´µ½Ò»×ù´óµÄ²İÌÃ£¬ÌÃÍâ
¹ÒÒ»À¶²¼»Ï×Ó£¬ÉÏĞ´Ò»¸ö[33m¡°ØÔ¡±[2;37;0m×Ö¡£ÄÏÃæÏïÖĞÒ»ĞĞÍáÁø£¬´¦´¦ÃñÕ¬£¬
¼¸¸öĞ¡Í¯ÔÚÏïÖĞÍæË£¡£
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"beiyin1",
                "north" : __DIR__"caotang",
                "west" : __DIR__"ximen",
                "east" : __DIR__"baihu-w2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



