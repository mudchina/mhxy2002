//changan city
// [lsg 2000/11/16]
inherit ROOM;
#include <ansi.h>;

void create ()
{
 set ("short", HBRED+HIW"月牙儿皇宫"NOR);
        set ("long", @LONG

  宁静的天空中，微风袭袭，一朵朵巨大的云彩围绕着月牙儿皇宫
金碧辉煌的宫殿是皇宫的主人麦克小狼劳累了一天最想去的地方
宫殿里的小桥，厅阁，花园.....处处留下了宫殿主人相爱的身影.......
LONG);
        set("exits", 
        ([ //sizeof() == 2
                "wiz" : "/d/wiz/wizroom",
                "kz" : "/d/city/kezhan",
                "enter" : "/u/pkyou/workroom",
                        ]));

        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



