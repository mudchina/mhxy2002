//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "河底");
  set ("long", @LONG 
这里是黑水河之底。从上面看此河水色漆黑，但从下往上看，
水色确是清亮透彻，水中空空荡荡，连一条小鱼也没有。只
有岸上的残枝枯草，在水中飘来荡去。 前面水波流荡，仿佛
可以看到一座府邸。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"hedi3",
  "north" : __DIR__"hedi5",
]));
        setup();
}


