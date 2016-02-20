// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "二之图");
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
这里就是冥界二之图，是通往冥殿的必经之路
  
LONG);
                     
set("exits", ([
      "northdown": __DIR__"tu3",
            "southup": __DIR__"tu1",
    
        ]));

  set("objects", ([ 
 	"/d/mingjie/npc/meilusi":1,

        ]));

        setup();
}
