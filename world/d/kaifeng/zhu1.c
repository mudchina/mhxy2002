// by cih 10/01/2002
// Room: /d/kaifeng/zhu1

inherit ROOM;

void create ()
{
  set ("short", "香路");
  set ("long", @LONG

一条小路沿着湖边蜿蜒盘绕，西边的湖水浑浊一点，风吹过湖水荡漾
杨柳微拂，在湖水上晃动着长长的倒影。不时有莺歌鸟鸣声声传来，
令人心旷神怡。其实这是八戒为了怀念在高老庄和高小姐在一起的日
子私自把开封东湖圈了一块起来修成的。并取名为这不伦不类的香路。

LONG);

  set("exits", ([
        "north" : __DIR__"zhu2",
  "west" : __DIR__"huting",
        "southeast" : __DIR__"zketing",
        "southwest" : __DIR__"zhu3",
      ]));
  set("objects", ([
        __DIR__"npc/zhangmen" :  1,
      ]));

  set("outdoors", "kaifeng");

  setup();
}


