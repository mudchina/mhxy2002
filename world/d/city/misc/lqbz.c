//Cracked by Roath
inherit ROOM;
void create ()
{
  set ("short", "黄色笑话");
  set ("long", @LONG

这是黄色笑话书屋，如果您是男性而且又在18岁以上就可以来到这里
看书啦，书的内容不算很扯蛋，只是挺有趣的，请大家来这里看书吧!	

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/city/changan",

]));
  set("objects", ([ /* sizeof() == 2 */
]));
  set("no_fight", 1);
  set("no_magic", 1);
  

  setup();
  call_other("/obj/board/xiaohua_b", "???");
}
