// changan wusheng
// room6.c

inherit ROOM;

void create()
{
  set ("short", "帝王殿");
  set ("long", @LONG

整个殿堂从建筑风格、建筑用料、装修布局都与天上的天宫很相
似。殿堂四周九彩祥云围绕飘渺，从里面还透出阵阵庄严之气，
不禁令人起敬。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"room7",
"south": __DIR__"shijie9",
]));
set("objects", ([
        "/d/wusheng/npc/zhangmen": 1]));
        set("no_clean_up", 0);
        set("outdoors", 1);
  set("valid_startroom", 1);
        setup();
}


