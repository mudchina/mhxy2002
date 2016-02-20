//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "海底");
  set ("long", @LONG
西海海底洁净如镜，少有海藻、蔓藤，雪白的海沙晶莹地
铺在海底，美不胜收。群群游鱼悠闲自得地在你身边飘过，
前面不远处有一座巨大的宫殿，正在五彩珊瑚围绕中闪烁
生辉。
LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yecha" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"xihai",
  "southwest" : __DIR__"haidi2",
]));
        setup();
}

