//by tianlin@MHXY. 2001.7.4

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", HIR"三 "+HIY"花 "+HIB"堂"NOR);
        set ("long", @LONG

三花堂是城中名声恶劣的一个帮会，堂中的人大多是些亡命之徒，烧
杀抢劫，欺压百姓，无恶不做。而官府却很难抓到把柄而将其除之。
正中有三座虎皮大椅，是三位堂主坐的，旁边立了几个面目凶恶的打
手。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"beiyin2",
		"north" : __DIR__"tang",
		"west" : __DIR__"sanhua-mishi",
	//	"south" : __DIR__"tang2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tangzhu1" : 1,
		__DIR__"npc/fei1" : 2,
		__DIR__"npc/fei2" : 2,
        ]));


        setup();
	replace_program(ROOM);
}


