// changan wusheng
// room8.c

inherit ROOM;

void create()
{
  set ("short", "卧室");
  set ("long", @LONG

房中拜着一张床，上面整整齐齐地铺了一套被铺，不过所用之物
好像非凡间所有。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"room1",
]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);
        setup();
        
        setup();
        replace_program(ROOM);
}
