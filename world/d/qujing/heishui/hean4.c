//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "河岸");
  set ("long", @LONG
黑水河，水沫浮来如积炭，浪花飘起似翻煤。此水，即牛羊
不饮，虽鸦雀难飞。 牛羊不饮嫌深黑， 鸦雀难飞怕渺弥。
水面波涛涌起，堆出阵阵黑沫，令人望而生厌。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"hean3",
  "east" : __DIR__"hean5",
]));
        set("outdoors", "heishui");


  setup();
}

