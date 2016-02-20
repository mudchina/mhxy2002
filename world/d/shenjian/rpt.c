// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{        object con, item;

        set("short", "右偏厅");
        set("long", @LONG
屋中的桌上还摆着一幅出自名家之手的狂草，四面皆是各种
画，还有几个书柜，里面放满了各种书籍，看来这里是供客人消
遣的地方了。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"xw",
  "west" : __DIR__"dt",
]));
set("objects", ([
		__DIR__"npc/swordman" : 1,
                __DIR__"obj/bookshelf" : 1,
          	]));

        set("coor/x",-1300);

	set("coor/y",260);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
void reset()
{
        object          *inv;
        object          con, item, item2, item3, item4;
        int             i;

        ::reset();
        con = present("书柜", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/fybook");
                item2 = new(__DIR__"obj/fybook2");
                item3 = new(__DIR__"obj/fybook3");
                item4 = new(__DIR__"obj/zizhuan");
                item->move(con);
item2->move(con);item3->move(con);
	}
}
