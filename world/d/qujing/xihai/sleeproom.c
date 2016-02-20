//edit by lucas

inherit ROOM;

void create()
{
        set("short", "客房");
        set("long", @LONG
这里是西海龙宫的客房，幽静安宁，没有任何打搅，
一进来就让人想睡觉。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"zoulang6",
        ]));
        set("sleep_room",1);

        setup();
}

