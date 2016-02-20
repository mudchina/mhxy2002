//BY tianlin@mhxy for 2002.3.7,描述胡乱一写,hehe

inherit ROOM;

void create ()
{
  set ("short", "龙宫密室");
  set ("long", @LONG

这里是一个不算很大的地方，一眼就能看出
这个地方已经很长时间没有来过人了，就在
这时你发现一个非常庞大的东西在你周围，
你慢慢开始紧张起来。
LONG);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/sihai" : 1,
]));
        set("water", 1);
        setup();
}
