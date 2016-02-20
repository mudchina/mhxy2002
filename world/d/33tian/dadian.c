// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/33tian/west1
inherit ROOM;

void create ()
{
  set ("short", "兜率宫");
  set ("long", @LONG
这就是离恨天兜率宫了.此宫位于三十三天之上,一向是太上
老君的住所.宫中有一座大药炉,几个青衣童子正在药炉旁煽火,
到处都弥漫着一股芬芳的丹药气息.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"doushuai-gate",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laojun": 1,
]));
  setup();
}
