// changan wusheng
// room1.c

inherit ROOM;

void create()
{
  set ("short", "练功房");
  set ("long", @LONG

武圣门帝子练功的地方，有木人和铜人供弟子练功，而且还有茶
水间，累了的弟子都在茶水间里面休息侃谈。武圣门果然是一个
好地方！！！
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"room1",
]));
        set("no_fight", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
        "/obj/board/wsboard"->foo();
}

