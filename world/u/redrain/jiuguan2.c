//by swagger
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "翠花楼");
  set ("long", @LONG

这儿就是长安城最热闹的场所--翠花楼了。地处南来北往的人流中心，就
更加热闹有加。猜拳行令之声、笑骂声、叱喝声响成一片。也分不清那些
是良家百姓、哪些是响马强人。这里真说得上是龙蛇混杂。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "down" : "/u/redrain/jiuguan1",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/u/redrain/guinu" : 1,
]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "down" ) {
        if (objectp(present("gui nu", environment(me)))) {
            if (me->query("jinu")) {
        return notify_fail("龟奴奸笑了几声：没赎身就想跑？想的到美！\n");
        }
        }
        return ::valid_leave(me, dir);
}
}
