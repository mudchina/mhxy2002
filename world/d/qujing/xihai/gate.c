//edit by lucas

inherit ROOM;

#include <ansi.h>;

void create()
{
        set("short", "宫门");
        set("long", 
"这里是西海龙宫的大门，用一整块汉白玉雕成。缀以无数各色宝
石，看来光是这扇门就已经价值连城。人言“何愁龙王无宝！”诚
不我欺。宫门外站着几个威风凛凛的卫士，看来是不会轻易让人进
去的。门上以红宝石镶嵌着着四个大字。"HIR"

                          西海龙宫
\n"NOR);
  set("water", 1);
        set("exits", ([
                "south"  : __DIR__"haidi5",
                "northup"  : __DIR__"yanwu",
        ]));
        set("objects", ([
                __DIR__"npc/huwei" : 3,
        ]));
        setup();
} 

