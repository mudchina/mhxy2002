//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG 
这里是河神府的厨房。四处是活蹦乱跳的鲜鱼美虾，生猛海
鲜。鼋龙生性奢侈，贪图口腹之欲，所以力求食物精美可口。
所以这里的每样食物都是按照东海龙宫的标准所制。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang3",
]));

        set("objects", ([
       "/d/qujing/xihai/obj/xiaren" : 1,
       "/d/qujing/xihai/obj/xierou" : 1,
       "/d/qujing/xihai/obj/fish" : 1,
       "/d/qujing/xihai/obj/baoyu" : 1,
        ])); 

        setup();
} 

