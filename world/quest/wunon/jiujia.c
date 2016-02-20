// zhujia.c 铸甲房
// 星星lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "龙泉酒家");
        set("long", @LONG
这是全国闻名的龙泉酒店的大厅。全国的美食在这里都能
吃到,如果你身上有做菜的材料,你可以去东面的厨房里做
菜.....
LONG
        );

        set("exits", ([
                "north" : "d/city2/dongcha1",
                "east" : __DIR__"shaocai",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

