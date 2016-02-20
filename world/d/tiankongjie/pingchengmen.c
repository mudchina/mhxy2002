// Room: /d/tiankongjie/pingchengmen.c

inherit ROOM;

void create()
{
        set("short", "平成门");
        set("long", @LONG
从这里就可以进入天空界了。天空界的大门。雄伟的天空界大门巍然耸立。宁静的气氛中洋溢着佛的禅宗。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"diyu.c",
  "southdown" : __DIR__"tianshoudao.c",
  "up" : __DIR__"tiankongshu-7.c",
]));
//  set("objects", ([ /* sizeof() == 4 */
//  __DIR__"npc/heimukai" : 1,
//]));

        setup();
        replace_program(ROOM);
}

