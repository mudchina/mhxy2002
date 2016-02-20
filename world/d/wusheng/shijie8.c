// changan wusheng
// shijie8.c

inherit ROOM;

void create()
{
  set ("short", "石阶");
  set ("long", @LONG

终于走到尽头了，站在峭壁地下而望，感觉不禁悚然。峭壁下还
有一棵大树(tree)，一个老人就在树下歇凉。
LONG);
set("item_desc", ([ /* sizeof() == 1 */
       "tree" : "一棵万年大数，高耸如云，不知道是什么品种，树上还结满了果。\n",
]));
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"xuanya0",
"southdown": __DIR__"shijie7",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{       
	object me;
        me=this_player();

        if ( !arg || ((arg != "tree") ))
                return notify_fail("你要摇什么？\n");
        else
                message_vision("$N扎了个马步，抱住宽大的树干，像猴子般就爬了上去。\n",me);
                me->move("/d/wusheng/uptree");
		me->receive_damage("kee", 20);
		tell_room( environment(me), "数叶晃了几下，一个人爬了上来。\n", ({me}));

                return 1;
}


