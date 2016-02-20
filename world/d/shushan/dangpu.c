//【蜀山派】mhxy-yushu 2001/2
#include <room.h>
inherit HOCKSHOP;
void create ()
{
  set ("short","不宰人当铺");
  set ("long", @LONG

沿街的铺面挑着“当”字招牌,素以买卖公平见称。里面有一个高高的柜台,
当铺的老板就站在柜台后面,眯着小眼看着来的客人。东边是村里小路。当
铺的墙上有一块匾(bian)。
LONG);
  set("item_desc", ([ 
  "bian" : "
本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
客官可以在这里：
    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
    ＊	卖断(sell)		＊
    ＊	购买(buy) 用list查看。  ＊
    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
各种货物，铜钱、银两、黄金、银票一概通用。
"]));
  set("objects", ([ /* sizeof() == 2 */
   __DIR__"npc/laoban" : 1,
 ]));
  set("exits", ([ 
     "east" : __DIR__"road2",
 ]));
 set("no_clean_up", 1);
 setup();
}
int clean_up()
{
      return 0;
}







