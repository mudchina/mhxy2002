// by cih 10/01/2002
// Room: /d/kaifeng/neitang

inherit ROOM;

void create ()
{
  set ("short", "内堂");
  set ("long", @LONG

虽然说这里是内堂，但除了桌子就没有别的了。连把椅子也没有。唉！
看来这位猪哥哥的思想真是异于常人啦！！这里其实更本就是条小路
不晓得八戒为什么把它这北到花园南向书房的路改成房子？？

LONG);

  set("exits", ([
        "west" : __DIR__"zketing",
        "southeast" : __DIR__"zshufang",
        "northwest" : __DIR__"huayuan1",
      ]));
  set("objects", ([
        "/d/obj/misc/tables" : 3,
      ]));

  setup();
}


