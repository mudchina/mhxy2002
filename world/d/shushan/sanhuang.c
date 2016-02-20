//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","三皇殿");
  set ("long", @LONG

这里是蜀山剑派的大殿，是会客的地点。供着元始天尊、太上道
君和天上老君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着
几个蒲团。南边是甬道，北边是天师洞。
LONG);
   set("exits", ([      
       "north" : __DIR__"tianshi",
       "south" : __DIR__"yongdao",
  ]));
  setup();
}









