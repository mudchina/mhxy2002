inherit ROOM;

void create()
{
	set("short", "比武大会会场");
	set("long", @LONG
描述待改!
描述待改!
描述待改!
描述待改!
描述待改!
描述待改!
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "比武须知:
    jump 跳上擂台
待续
",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/referee" : 1,
]));
	set("no_beg", 1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pintai",
  "up" : __DIR__"leitai",
  "out" : __DIR__"gate",
]));
	set("no_clean_up", 0);
	set("no_death_penalty", 1);
        setup();
}

void init()
{
   add_action("do_quit", "quit");
     add_action("do_gogo", "out");
}
int do_quit()
{
  write("你在比武大会期间不能退出．．．．！\n");
  return 1;
}

int do_gogo()
{
        object me;
        me = this_player();
        me->set_temp("marks/allow_biwu",0);
        return 0;
}
