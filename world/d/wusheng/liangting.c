// changan wusheng
// liangting.c

inherit ROOM;

void create()
{
  set ("short", "忠义亭");
  set ("long", @LONG

一个用八条三个人都抱不过的大木做支撑建造而成的石亭，柱子
上好像有墨迹。传说这里曾有许多忠义烈士留词于亭子的木柱上，
但因为年久长矣，上面的字已经模糊不清，甚至看不见。
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"shijie3",
]));
        set("no_clean_up", 0);
        set("outdoors", 0);
        setup();
}

