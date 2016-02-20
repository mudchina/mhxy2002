//by swagger
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "翠花楼");
  set ("long", @LONG

这儿就是长安城最热闹的场所--翠花楼了。地处南来北往的人流中心，就
更加热闹有加。几个小姐正奶声奶气的和客人打情骂俏、猜拳喝酒。老板
娘数着手中的银票，正偷偷的笑。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southwest" : "/d/city/zhuque-s1",
  "up" : "/u/redrain/jiuguan2",
]));
  set("objects", ([ /* sizeof() == 2 */
  "u/redrain/laobao" : 1,
]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  setup();
}


