// by cih 10/01/2002
// Room: /d/kaifeng/zhu2
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "余恨亭");
  set ("long", @LONG

余恨亭上有六角，上刻金龙彩凤，麒麟辟邪。这个亭子不是用来
下棋观风景的。而是每当我们的八戒哥哥想起长娥妹妹的时候就
到这里来长叹：“多情自古空余狠，此恨绵绵无绝期”的。。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
 // "/d/bibotian/npc/table" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhu1",
]));
//      
        set("water", 1);
//  
  setup();
}

/* 不晓得诸位看过张卫健演的西游记没？里面的猪哥哥就爱这两句。。呵呵 */

