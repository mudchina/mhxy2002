// changan wusheng
// shijie1.c

inherit ROOM;

void create()
{
  set ("short", "石阶");
  set ("long", @LONG

大青石铺的路，清石给上山的人踏得光亮如镜。石路两旁还长满
了各种鲜花和灌木，风景之美不禁让人却步留连。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"shijie2",
"east" : "/d/changan/zhongnan",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

