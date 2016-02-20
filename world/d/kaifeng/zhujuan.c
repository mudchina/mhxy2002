// by cih 10/01/2002
// Room: /d/kaifeng/zhujuan
inherit ROOM;

void create ()
{
  set ("short", "猪圈");
  set ("long", @LONG

你一脚踏进来，只觉得一股熏天臭气扑面而来，你定神一看：原来
这里是个猪圈，里面有很多小猪。此间的小猪都是八戒精心挑选的
无敌小猪。准备看看谁最有发展前途好收一个和自己一样的徒弟。
不过不管怎么说，他们怎么跟八戒差别那么大？？八戒那么干净，
而这些小猪却。。。。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"huayuan6",
]  ));

  setup();
}
