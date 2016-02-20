//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "海底");
  set ("long", @LONG 
你眼前一亮，只见前面一座巨大无比的宫殿耸立在万水围拱中。
金玉为梁，白玉为柱，水晶为砖，珍珠为饰。十步一廊，九步
一阁，龙檀插炉，月泪飘香。龙女歌妃，红袖添香。玉人珠泪，
轻歌曼舞。虽人间帝王也不得此豪华矣！
LONG);
  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gate",
  "east" : __DIR__"haidi4",
]));
        setup();
}

