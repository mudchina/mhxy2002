// /d/guzhanchang/pomiao.c
inherit ROOM;
int do_out();
void create()
{
        set("short", "ÃÏÕ‚ÃÏ");
         set ("long", @LONG
 "
                     .                          +
           +                                                    .
                                     ___       .
     .                        _.--"~~ __"-.
                           ,-"     .-~  ~"-\              .
              .          .^       /       ( )      .
                    +   {_.---._ /         ~
                        /    .  Y                            .
                       /      \_j                      +
        .             Y     ( --l__
                      |            "-.                   .
                      |      (___     \
              .       |        .)~-.__/             .           .
                      l        _)
     .                 \      "l
         +              \       \
                         \       ^.
             .            ^.       "-.           -Row         .
                            "-._      ~-.___,
                      .         "--.._____.^
       .                                         .
LONG);
                     
set("exits", ([
                
        ]));
  set("objects", ([
             __DIR__"npc/tianzun" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

