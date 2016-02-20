// link
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"果林"NOR);
        set("long", @LONG
这片果林向东通向灵界圣殿前的草坪，向南便是灵界掌门的住处了，
一般都比较冷清，但最近因为芒果熟了，虽然品种很差，滋味儿也
不好，但还是有不少人在这里偷偷摸摸的摘芒果吃。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shengdian",
  "south" : __DIR__"zmroom",
 ]));
        set("objects", ([
        __DIR__"npc/gongren" : 1,
			]) );
        set("item_desc",([
"tree":"这是一棵结着一大堆青黄不接的芒果的芒果树。\n",
]));
	set("valid_startroom",1);
        set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("do_zhai", "zhai");
        add_action("do_zhai", "摘");
}
int do_zhai(string arg)
{
        object ob;
        object me;

        me = this_player();

 if ( !arg || ( arg != "芒果" ) ) {
 return notify_fail("你要摘什么？\n");
   }
 else 
 {
  if(random(10)) {
    message_vision("$N踮起脚，想从树上摘下一个芒果来，但一个不稳丛树上摔了下来！\n",me);
    me->unconcious();
    return 1;
  }
  message_vision("$N踮起脚，从树上摘下一个芒果来。\n",me);
  ob = new(__DIR__"obj/mangguo");
  ob->move(me);
  return 1;
 }
return 1;
}