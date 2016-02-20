//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","迎客亭");
  set ("long", @LONG

蜀山剑派门前的迎客亭，从这里就能看到蜀山剑派的山门了。
亭子里有不少人，人们在这里围坐在一起，喝着西湖龙井，
谈古论今，别有一番风味。
LONG);

  set("exits", ([      
     "southdown" : __DIR__"zhanqiao",
       "northup" : __DIR__"shanmen",
 
 ]));
  set("objects", ([ 
    __DIR__"npc/youke" : 2,
    __DIR__"npc/liaoke" : 2,
    __DIR__"npc/oldzhang" : 1,
 ]));
  setup();
}









