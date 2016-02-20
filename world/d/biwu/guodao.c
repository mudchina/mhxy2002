// Room: /u/biwu/guodao.c
// Date: bye linxue([1;37m¡÷—©[2;37;0m) Fri Apr 30 09:45:05 1999
inherit ROOM;

void create()
{
	set("short", "…Ωµ¿");
	set("long", @LONG
-----------’‚ «“ªº‰ ≤˜·“≤√ª”–µƒø’∑øº‰°£---------------------
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"gate",
  "northup" : __DIR__"guodao1",
]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
