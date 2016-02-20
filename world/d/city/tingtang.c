// Room: /d/pingan/tingtang
inherit ROOM;

void create ()
{
  set ("short", "厅堂");
  set ("long", @LONG
这儿是南城客栈的厅堂，几桌客人在高兴的吃着东西，不时有猜拳行令
的声音传进你的耳朵，你惊奇的发现他们虽然谈笑风声，却感觉不到一般的
酒楼那种吵闹的气氛。
LONG);

  //set("objects", ([ /* sizeof() == 1 */
  //__DIR__"npc/guanshi" : 1,
//]));
  set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"kezhan",
]));
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);

  setup();
  replace_program(ROOM);
}
