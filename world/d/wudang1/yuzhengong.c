//Room: yuzhengong.c 遇真宫
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","遇真宫");
      set("long",@LONG
这里是进入武当山的第一道宫宇遇真宫，宽敞无比，可容千人食宿，
是进香客的一大歇脚处。三丰真人曾在此结庵修炼，因此宫中供着张三
丰真人像。由于张真人闭关已久，外人不知其是否仍在人间，民间传说
他已得道仙逝，立像膜拜。
LONG);
      set("objects", ([
          __DIR__+"npc/zhixiang": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"shijie1",
          "southup"  : __DIR__"wdbl",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
