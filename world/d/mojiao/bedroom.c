inherit ROOM;
void create()
{
  set ("short", "书房");
  set ("long", @LONG

这里是风飞白的书房，也是他休息的地方，虽说不大但也很整洁
累了的话可以在这里好好的睡一觉。

LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"dating4",
]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);
        setup();
        replace_program(ROOM);
}
