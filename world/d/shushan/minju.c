//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
   set ("short", "民居");
   set ("long", @LONG

这里是乌鸦嘴的一个普通民居，很显然这家一贫如洗，其实乌鸦嘴的人都不富
裕。家里除了一个土炕,就只有几把椅子了。在屋子里的的一个角落里放着几
件耕田的工具。其他的什么也没有了。
LONG);
   
   set("exits", ([ 		
       "east" : __DIR__"road3",
   ]));
   set("objects", ([ 		
      "d/city/npc/boy" : 1,
      "d/city/npc/girl" : 1,
]));

        setup();
}



