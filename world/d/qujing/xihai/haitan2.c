inherit ROOM;

void create ()
{
  set ("short", "海滩");
  set ("long", @LONG
时近正午，烈日当头，炎阳炽炽。海滩上万物都已消失无
踪。海鸥懒洋洋地飞着，时而掠过水面，与其说是捕食，
不如说是为了享受那片刻的清凉。就连一只小小的贝壳，
也躲在它那厚实的甲壳中，避开阳光的煎熬。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"haitan1",
  "southwest" : __DIR__"haitan3",
]));
        set("outdoors", "xihai");


  setup();
}

