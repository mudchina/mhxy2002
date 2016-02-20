// Room: /d/tiankongjie/diyu.c

inherit ROOM;

void create()
{
        set("short", "地狱血池");
        set("long", @LONG
到处都是赤红的颜色。到了这里你似乎领悟到了死亡也就是重生的意义。
LONG
        );
        set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiewu" : 1,
]));


        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"pingchengmen",
]));

        setup();
        replace_program(ROOM);
}

