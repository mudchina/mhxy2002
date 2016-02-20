// Room: /d/wiz/menpai_room
inherit ROOM;

void create ()
{
  set ("short", "梦幻西游工作室");
  set ("long", @LONG

   一间很普通的房子,光线明亮,地方也很宽敞.只是地上的杂志有点.....
门的左边是一张电脑桌，上面有一台小奔三和一些电脑杂志和几本PLAYBOY书.
墙角有一张能睡四人的大水床,在这里......这个这个.......
LONG);
/*
梦幻西游现有门派如下：

仙：南海普陀，方寸灵台，万剑之尊蜀山
妖：陷空山无底洞，大雪山，枯松涧火云洞，乱石山碧波潭
中：将军府，月宫，龙宫，地府
*/

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wizroom",
"south" : __DIR__"xoxroom",
]));
  set("light_up", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/menpai_bbs", "???");
}
> 