//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "河岸");
  set ("long", @LONG
眼前就是西天路上有名的黑水河了。层层浓浪，迭迭浑波，
层层浓浪翻乌潦，迭迭浑波卷黑油，这水黑成这样，真令
人难以想象其中还有生灵存活，这水，这浪，比之流沙河，
也毫不逊色。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"hean1",
  "southup" : __DIR__"shan",
  "east" : __DIR__"hean3",
]));
        set("outdoors", "heishui");


  setup();
}

