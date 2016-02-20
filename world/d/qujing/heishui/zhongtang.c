//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "中堂");
  set ("long", @LONG 
这里是鼋龙的书房，鼋龙虽然僻处黑水，却着手下前去
东胜神州，大唐之国，购来四书五经，诗词歌赋，这里
的书籍也是汗牛充栋，多不胜数。书桌上有个紫铜狮子
镇纸(zhenzhi)，活灵活现，栩栩如生。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang6", 
]));
        set("objects", ([
                __DIR__"obj/tong":1,
        ]));


        setup();
} 

