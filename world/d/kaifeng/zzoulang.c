// by cih 10/01/2002
// Room: /d/kaifeng/zzoulang

inherit ROOM;

void create ()
{
  set ("short","空中走廊");
  set ("long", @LONG

空中走廊乃是猪八戒取经归来，因见诸佛菩萨大都光彩照人。而自
己却有些天生的缺陷，所以在帅府里特别修建了这条空中走廊以增
加自己的祥和之气。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zzoulang2",
  "down" : __DIR__"shuaifu",
]));

  set("outdoors","kaifeng");
  setup();
}
