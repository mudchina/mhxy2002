// EDIT BY LUCAS
inherit ROOM;


void create()
{
        set("short", "密室");
        set("long", @LONG
这里是鼋龙的密室，四周密不透风，连个小窗户也没有。地上
粘慢了一个个的小田螺，青苔遍屋，看来很久没人来过了，一
个老人被一条手臂粗的铁索穿了琵琶骨，关在这里，满脸都是
悔恨哀伤之情。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "out" : __DIR__"zhongtang",
        ]));
         set("objects", ([
                __DIR__"npc/heshen":1,
        ]));
        setup();
}

