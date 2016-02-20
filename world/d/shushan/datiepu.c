//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","打铁铺");
  set ("long", @LONG

乌鸦嘴的打铁铺,老板是个打铁的好手，很多好兵器都出自
老板之手，不少江湖豪杰都到这里买兵器,江湖上人们称他
为“张巧手”。因此在江湖上也名不虚传。
LONG);

  set("exits", ([ 
     "west" : __DIR__"xiaoxiang",
 ]));
 set("objects", ([ 
  __DIR__"npc/daboss" : 1,
 ]));
 set("no_clean_up", 0);
 setup();
}






