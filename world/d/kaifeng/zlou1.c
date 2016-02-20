// by cih 10/01/2001
// Room: /d/kaifeng/zlou1

inherit ROOM;

void create ()
{
  set ("short", "天蓬楼");
  set ("long", @LONG

以天蓬名字命名的四层高塔，采用异域的设计模式，整座
塔的塔身十分雄伟，底座宽大，造型简洁庄严神秘。方塔
底座有门，门楣上有石刻画。不用说画上肯定是个大猪头
了。画上还有一块匾(bian)。上面好像写着什么。

LONG);


  set("item_desc", ([
     "bian": " 净坛 \n"
        ]));

  set("exits", ([
        "enter"    : __DIR__"zlou2",
        "south" : __DIR__"huayuan4",
      ]));

  setup();
}






