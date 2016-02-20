//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "河岸");
  set ("long", @LONG
这黑水河虽鸟兽绝迹，但花草倒还茂盛。岸上芦苇知时节，
滩头花草斗青奇。湖泊江河天下有，溪源泽洞世间多。人生
皆有相逢处，谁见西方黑水河！
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hean4",
  "northeast" : __DIR__"road4",
]));
        set("outdoors", "heishui");


  setup();
}

