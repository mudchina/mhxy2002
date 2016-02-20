// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "极乐净土");
         set ("long", @LONG
             .        ___---___                    .
       .              .--\        --.     .     .         .
                    ./.;_.\     __/~ \.
                   /;  / `-'  __\    . \
 .        .       / ,--'     / .   .;   \        |
                 | .|       /       __   |      -O-       .
                |__/    __ |  . ;   \ | . |      |
                |      /  \\_    . ;| \___|
   .    o       |      \  .~\\___,--'     |           .
                 |     | . ; ~~~~\_    __|
    |             \    \   .  .  ; \  /_/   .
   -O-        .    \   /         . |  ~/                  .
    |    .          ~\ \   .      /  /~          o
  .                   ~--___ ; ___--~
                 .          ---         .              -JT

冥王哈迪斯住的地方-----人人向往的极乐净土

LONG);
                     
set("exits", ([
                "southdown": __DIR__"mi",
            
        ]));
 
  set("objects", ([ 
	"/d/mingjie/npc/mingwang":1,
     
   ]));
       setup();
}
