//edit bye lucas
inherit ROOM;

void create()
{
        set("long",@LONG 
此处是一处极高的悬崖，脚下就是汹涌澎湃的黑水河。站在此处，
惟见江水滔滔东去，日月奔流不止。远处江鸥点点，触景生悲。这
里险峻陡峭，凡人根本上不来，所以摩昂选择此处布阵扎营，以擒
拿进攻黑水鼋龙。
LONG );
        set("no_clean_up", 0); 
        set("outdoors", "heishui");
  set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"shan", 
        ]));
        set("objects", ([
             "/d/qujing/xihai/npc/xiejiang" : 2,
             "/d/qujing/xihai/npc/xiabing" : 2,
        ]));

        setup();
}

