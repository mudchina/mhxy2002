//【蜀山派】mhxy-yushu 2001/2
//By tianlin@Mhxy for 2001.12.30/因为老和那个地方连接太乱了
inherit ROOM;
void create ()
{
  set ("short","小村口");
  set ("long", @LONG

举头向南望去，只见一带泥墙，几丛青篱，一条潺潺的小溪围着十几
间矮矮的茅屋，正是乌鸦嘴。巴蜀之地，往往百里路无有人烟，乌鸦
嘴虽然地处偏僻，但是在这里依稀可以听的到村子里的孩童的嬉闹声，
让人并无荒凉之感。东面是马棚，极目远望，西面有座高山，几朵
白云留连不去。
LONG);

  set("outdoors", 2);
  set("exits", ([ 
     "east" : "/d/gao/daotian2",
    "south" :  __DIR__"road1",
   ]));
 setup();
}






