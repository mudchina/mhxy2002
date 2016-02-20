// changan wusheng
// guangchang.c

inherit ROOM;

void create()
{
  set ("short", "广场");
  set ("long", @LONG

一个足足可以容纳上千人的大广场，望前一看，硕大的金匾就挂
在那栋建筑的大门上，金匾上写着三个大字——〖武帝殿〗
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"room1",
"southdown": __DIR__"shijie4",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

