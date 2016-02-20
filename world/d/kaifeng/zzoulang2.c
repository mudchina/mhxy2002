// by cih 10/01/2002
// Room: /d/kaifeng/zzoulang

inherit ROOM;

void create ()
{
  set ("short","空中走廊");
  set ("long", @LONG

这条空中走廊由北到南贯穿整个府邸。天蓬元帅府的一切都尽览无
疑。这里向西望去隐隐看见有一座湖心亭。而东边则是天蓬元帅猪
老哥的书房了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zzoulang3",
  "south" : __DIR__"zzoulang",
]));

  set("outdoors","kaifeng");
  setup();
}
