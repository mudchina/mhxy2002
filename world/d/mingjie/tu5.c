// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "五之图");
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
      "northdown": __DIR__"dian",
            "southup": __DIR__"tu4",
    
        ]));

  set("objects", ([ 
   	"/d/mingjie/npc/xipo":1,
      ]));

        setup();
}
