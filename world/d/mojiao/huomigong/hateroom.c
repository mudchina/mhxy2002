
inherit ROOM;

void create()
{
        set("short", "精舍前");
        set("long", @LONG

穿过路旁的草地，四下观望，只见路边一栋精舍，建筑在翠竹之间，微风
过处，幽籁天成。不远处，则见道旁依山筑起一片小巧的楼阁，飞檐如凤，
画栋雕梁。当真有如皇宫一般。
LONG
        );
        set("exits", ([ 
    "north" : __DIR__"valley",
]));
        set("outdoors", "mojiao");

	setup();
        replace_program(ROOM);
}

