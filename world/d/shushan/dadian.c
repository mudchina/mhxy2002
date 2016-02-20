//dadian.c by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void init();

void create()
{
  set("short",HIR "「"HIY "正殿" HIR "」" NOR);
  set("long", @LONG

走进这里，突感一阵肃穆之意，正殿中十分空旷，殿顶高悬八盏
金灯，两旁是精壮佩剑武士剑气森严逼人。正中设一宝座，前有
一雕花檀木案，宝座后立有一扇玉屏。
LONG);
        set("exits", 
        ([ //sizeof() == 4
               "south" : "/d/shushan/xiaoyuan",
              "northup" : "/d/shushan/dating",
               "west" : "/d/shushan/changlang1",
               "east" : "/d/shushan/changlang",
            ]));
               set("objects", 
        ([ //sizeof() == 1
               "d/shushan/npc/dizi" : 1,
               "d/shushan/npc/dizi1" : 1,
               "d/shushan/npc/songer": 1,
               "d/shushan/npc/zhangmen": 1,

    ]));       
  
        setup();
}

