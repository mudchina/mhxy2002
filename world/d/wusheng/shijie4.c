// changan wusheng
// shijie4.c

inherit ROOM;

void create()
{
  set ("short", "石阶");
  set ("long", @LONG

大青石铺的路，清石给上山的人踏得光亮如镜。石路两旁还长满
了各种鲜花和灌木，风景之美不禁让人却步留连。前面看见一座
魁丽堂皇的建筑物，不知是什么宫殿，不觉让人加快脚步。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"guangchang",
"southdown": __DIR__"shijie3",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

