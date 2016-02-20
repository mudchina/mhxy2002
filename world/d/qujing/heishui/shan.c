//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "陡峰");
  set ("long", @LONG
这里是黑水河边的一座陡峭山峰，远望山下，白云渺渺，
江水滔滔。威猛雄烈的黑水河在这看来也不过是一条弯
弯的小黑带罢了。仰头上视，山势凶险，看来是不能往
上攀登了。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"hean2",
  "up" : __DIR__"xuanya",
]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "up")
    return notify_fail ("山势陡峭，你怎么努力都是爬不上去的。\n");
  return ::valid_leave(who,dir);
}

