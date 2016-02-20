//by tianlin 2001.7.4

inherit ROOM;

void create()
{
  set ("short", "大树顶");
  set ("long", @LONG

站在这大树的顶端，山风阵阵，空气清新．向山顶仰望，隐
约看到一片房屋在一股淡淡的紫气笼罩之下．
LONG);
set("exits", ([ /* sizeof() == 4 */
"down": __DIR__"shijie8"
]));
        set("objects",([
                __DIR__"obj/guoshi" : 1,
        ]));
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


