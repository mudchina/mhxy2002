inherit ROOM;
#include <ansi.h>

void create()
{       
set("short", "红雨行宫");
set("long", @LONG       
                 ◇红雨行宫◇

    这儿就是孤狼的行宫大殿。殿里金光闪烁、瑞霭如云、紫气环
绕、雕龙绘凤。正中是一张用黄金制成的电脑桌，上面放着一台正
在工作的奔腾Ⅳ型电脑， 边上零零散散的放着许多照片(photo)和
信件(letter)。
LONG);  
set("valid_startroom",1);
set("no_steal", "1");
        set("exits", ([
                "kz" : "/d/city/kezhan",
                "out" : "/d/city/zhuque-s1",
        ]));
        set("objects", 
        ([// sizeof() == 1
//                "/u/redrain/ronger" : 1,
        ]));
set("item_desc", ([
                "photo" : HIC "\n一些非常漂亮的女孩的照片。\n" NOR,
                "letter" : HIG "\n这是其中的一封信，大致的内容写的是：\n" NOR + HIC "孤狼，我爱你，我愿为你付出一切，只求你不要抛弃我........\n\n" NOR + HIC "                             酒井法子\n" NOR + HIC "                            06/24/2001 \n" NOR
        ]));
setup();
  call_other("/obj/board/menpai_b", "???");
}
