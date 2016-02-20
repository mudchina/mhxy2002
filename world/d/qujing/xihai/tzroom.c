inherit ROOM;

void create()
{
        set("short", "龙子居");
        set("long", @LONG
这里是西海龙宫皇太子摩昂的居所。摩昂生性好武，这里也摆满
了各种武器。墙上壁前，都是天下奇兵。走进这里，只见漫天寒
光，气势逼人，一个勇武魁梧的龙族青年手舞钢叉，正用心研究
龙宫绝技风波叉法。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"zoulang5",
        ]));
         set("objects", ([
                __DIR__"npc/taizi":1,
        ]));
        setup();
}

