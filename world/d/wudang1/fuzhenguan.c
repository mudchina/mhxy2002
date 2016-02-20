//Room: fuzhenguan.c 复真观五层楼
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","复真观五层楼");
      set("long",@LONG
复真观五层楼构造奇特，其间有十二根梁枋交叉重叠，下面仅用
一柱支撑，即有名的“一柱十二梁”。在这里俯瞰群山，烟云迷离，
远望金顶，一柱擎天，为观景胜地。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"taizipo",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
