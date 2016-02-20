// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "四之图");
         set ("long", @LONG
 ,--------,'  
|    _     |   
|  .' `.   |  
|  `._.'   | 
|          
|__________\---------
                     ,-,-,-,-,
                             -,-,-,-,
                                     -,-,-==
这里就是冥界四之图，是通往冥殿的必经之路
  
LONG);
                     
set("exits", ([
      "northdown": __DIR__"tu5",
            "southup": __DIR__"tu3",
    
        ]));

  set("objects", ([ 
   	"/d/mingjie/npc/tana":1,
      ]));

        setup();
}
