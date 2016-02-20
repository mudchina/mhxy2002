
inherit ROOM;

void create()
{
        set("short", "恶魔食堂");
        set("long", @LONG
这里就是传说中的恶魔食堂了。里面不时飘出阵阵
香气,可在这阴森恐怖的灵界里,好象大家的食欲并
不太好,所以那里几乎每天没什么客人,只有几个跑
堂的不停的忙碌着。门口立着一块牌子（sign）。
LONG
        );
        set("exits", ([
	"out" :__DIR__ "lingjie6",
        "up" :__DIR__ "ricerm2",
        ]));

        set("item_desc",([
"sign":"饭卡系统已经完工，请灵界弟子使用以下方法购买：
	1、办一张新的饭卡，你的存款至少要有100元，输入“newcard”
	大师傅会将你的存款存入饭卡，并按10%自动提成。
	2、给饭卡充值。请前往灵界管理处存入即可。\n",
]));
	set("valid_startroom",1);
        set("objects", ([
                __DIR__"npc/shifu": 1,
        ]) );
        set("coor/x",60);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}

