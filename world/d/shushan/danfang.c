//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short", "丹房");
  set ("long", @LONG

这里是蜀山剑派的炼丹房，东北角堆着一些干茅草，有一石灶上
架设一金丹炉，青烟袅袅,两个小童正在炼丹。
LONG);

  set("exits", ([
        "east"    : __DIR__"westway4",
      ]));
  set("objects", ([
        __DIR__"obj/danlu"    : 1,
        __DIR__"npc/zhuiyunzi" : 1,
      ]));
  setup();
}

