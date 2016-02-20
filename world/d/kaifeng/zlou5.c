// by cih 10/01/2001
// Room: /d/kaifeng/zlou2

inherit ROOM;

void create ()
{
  set ("short", "天蓬楼");
  set ("long", @LONG

天蓬楼内结构精洁宽敞，塔内布置精美，给人以清静肃穆
之感。四周开有龛窗，塔内有楼梯直通上下。这里似乎是
非同寻常的场所。

LONG);

  set("objects", ([
        __DIR__"npc/zhubajie" : 1,
      ]));

  set("exits", ([
        "down" : __DIR__"zlou4",
      ]));

  setup();
}






