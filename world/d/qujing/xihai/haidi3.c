//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "海底");
  set ("long", @LONG
这里是西海海底，四周渐渐有些昏暗了，几道天光从头顶的海面中
投射下来，此时也不那么瑰丽了，昏沉沉的犹如天边的晚霞。一只
海星在洁白的海沙上爬过，留下一条长长的痕迹。
LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiejiang" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"haidi2",
  "southwest" : __DIR__"haidi4",
]));
        setup();
}

