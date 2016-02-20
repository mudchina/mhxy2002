//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "布云亭");
  set ("long", @LONG 
花谢花飞花满天，这等陆上景致，想不到在这里也可看见。
鼋龙穷奢极侈，花高价买来百花绿树，插于布云亭中，如
果水中也有狂蜂浪蝶的话，这里一定是萤飞蝶舞，鸟语花
香。
LONG);

  set("water", 1);
  set("exits", ([ 
  "south" : __DIR__"dayuan",
])); 
        set("objects", ([
                __DIR__"npc/yaowang" : 1,
        ])); 
        setup();
} 

