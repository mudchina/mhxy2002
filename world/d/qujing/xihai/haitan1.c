inherit ROOM;

void create ()
{
  set ("short", "海滩");
  set ("long", @LONG
这里是西海海滩。举目眺望，远处夕阳将落，残辉满天，
照得海上金蛇万条。水天一色之处，几点孤鸥在暮归的
渔帆上流连往返。水波粼粼，残阳瑟瑟，好一幅碧海落
日图。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"yandong",
  "west" : __DIR__"haitan2",
]));

        set("outdoors", "xihai");

  setup();
}

