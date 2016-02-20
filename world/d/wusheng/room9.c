// changan wusheng
// room9.c

inherit ROOM;

void create()
{
  set ("short", "练功房");
  set ("long", @LONG

房中整齐摆放着十八般武器，而且在架上还陈列着各种仙家兵器。
不过最奇怪的是有一个金人在石台上，该金人比正常人大一点，
身上穿着整齐的盔甲，不知道有何用？
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"room7",
]));
set("objects", ([
        __DIR__"npc/jinren": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
        
        setup();
        replace_program(ROOM);
}
