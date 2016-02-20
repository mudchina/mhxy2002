//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "海底");
  set ("long", @LONG
这里是西海之下。此处地势并不太深，四周倒还比较明亮，
几道天光从头顶的海面中投下来，照的到处亮堂堂的。一
条黄花鱼哗啦一声从你旁边游过，小小的尾巴啪地拂在你
脸上。
LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiabing" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"haidi1",
  "southdown" : __DIR__"haidi3",
]));
        setup();
}

