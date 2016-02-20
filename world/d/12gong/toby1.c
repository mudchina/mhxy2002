// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向白羊宫的路上，只见前面可以看到美丽的白羊宫耸立在奥林
匹亚峰上！
LONG);


        set("exits", ([
        "southup"    :       __DIR__"toby2",
"southwest" : "/d/southern/wutai/shanjiao",
        ]));

        set("outdoors", "12gong");
        setup();
}
