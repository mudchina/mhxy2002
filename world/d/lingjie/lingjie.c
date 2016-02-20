inherit ROOM;

void create()
{
        set("short", "灵界之巅");
        set("long", @LONG
这里传说是灵界的最高处,也是灵界唯一的入口了,
到了这里已没有了天,地,人,唯一有的只是灵了。
LONG
        );
        set("no_clean_up", 0);

        set("exits",([
        "east" : "d/city/kezhan",
        "eastdown" : __DIR__"rukou",
]));
        setup();
        replace_program(ROOM);
}
