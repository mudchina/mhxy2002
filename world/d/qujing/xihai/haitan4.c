inherit ROOM;

void create ()
{
  set ("short", "海滩");
  set ("long", @LONG
“海上生明月，天涯共此时”，良夜风宵，清露淡云，海
空上一轮皎洁的圆月缓缓升起。在幽蓝的天幕下，金黄的
沙滩也仿佛融化于这万籁俱静中。惟有声声蟋蟀，仍在波
涛声中低语唱和。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"haitan3",
  "south" : __DIR__"xihai",
]));
        set("outdoors", "xihai");


  setup();
}

