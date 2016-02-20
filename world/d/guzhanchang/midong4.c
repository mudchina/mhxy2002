// midong4.c

inherit ROOM;

void falldown(object,object);

void create ()
{
  set ("short", "密室");
  set ("long", @LONG
这里光线极为微弱，你勉强地看见洞里隐隐约约的一些东西，

                       .r""    .F        ^"4.                     
                    .@"        $           .d$b.                  
                  z$b.        J"        .d$$$$$$$c                
                .$$$$$$bc.    $    .e$$$$$$$$$$$$$$c              
               d$$$$$$$$$$$$bdbe$$$$$$$$$$$$$$$$$$$$$.            
              d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$b           
             $$$$$$$$$$$$$$$$     $$$$$$$F*$$$$$$$$$$$$$$          
            $$$$$$$$$$$$$$$$       $$$$$%3   ^"**$$$$$$$$$.        
           d$$$$$$$$$$$$$$$          $$$$$$$$$$$$$$$$$$$$$$b  
LONG);

  set("exits", ([
        "down" : __DIR__"tian4",
      ]));
  set ("sleep_room",1);
  set("objects", ([
        __DIR__"obj/fali"  : 1,
      ]));

  setup();
}










