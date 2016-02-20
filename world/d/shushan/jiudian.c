//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create()
{
  set ("short", "香喷喷酒店");
  set ("long", @LONG

乌鸦嘴就属这里看起来还比较豪华,在外面就可以闻到酒店的饭菜酒香。这家
酒楼新开不多时，烹调甚是得法，在这里饮酒的座客甚多。酒店里挂着一个
牌子(paizi),初来的客人可以看看。
LONG);
  set("item_desc", ([ 
  "paizi" : "
    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
    ＊	本店吉日开张            ＊
    ＊	欢迎五湖四海的朋友光临  ＊
    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
 "]));
  set("exits", ([ 
  "northwest" : __DIR__"road2",
  ]));
  set("objects", ([
    __DIR__"npc/jiuboss" : 1,
  ]));
  setup();
}
