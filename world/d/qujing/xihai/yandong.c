inherit ROOM;

void create ()
{
  set ("short", "海崖");
  set ("long", @LONG
这里是西海海边悬崖上的一处。这里四处都是大大小小的
岩洞，不知通向哪里。下面海潮汹涌，一波一波地扑向海
边的礁石，激起漫天银化，铺天盖地，仿佛要将大自然的
威力显诸于世人面前。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"haitan1",
]));

        set("outdoors", "xihai");

  setup();
}

