// changan wusheng
// indanlu.c

inherit ROOM;

void create()
{
  set ("short", "九脚丹炉内");
  set ("long", @LONG

一个很大的丹炉，里面火光通明，火中居然有一个人在那里。
LONG);
set("exits", ([ /* sizeof() == 4 */
"out": __DIR__"room1",
]));
set("objects", ([
               "/d/wusheng/npc/hufa": 1]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

