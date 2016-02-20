// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "三之图");
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
这里就是冥界三之图，是通往冥殿的必经之路
  
LONG);
                     
set("exits", ([
      "northdown": __DIR__"tu4",
            "southup": __DIR__"tu2",
    
        ]));

  set("objects", ([ 
 	"/d/mingjie/npc/jiduo":1,
        
]));

        setup();
}
