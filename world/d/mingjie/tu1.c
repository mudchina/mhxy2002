// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "一之图");
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
这里就是冥界一之图，是通往冥殿的必经之路
  
LONG);
                     
set("exits", ([
      "northdown": __DIR__"tu2",
            "northup": __DIR__"ba1",
    
        ]));

  set("objects", ([ 
 	"/d/mingjie/npc/yisi":1,
       ]));

        setup();
}
