// changan wusheng
// room4.c

inherit ROOM;

void create()
{
  set ("short", "降龙殿");
  set ("long", @LONG

降龙罗汉的大殿，降龙罗汉就正座在大殿正中，他是武圣门其中
一位尊者。
LONG);
set("exits", ([ /* sizeof() == 4 */
"southeast": __DIR__"room1",
]));
set("objects", ([
        __DIR__"npc/xianglong": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}
