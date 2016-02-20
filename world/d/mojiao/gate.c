#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIW"魔教"NOR);
     set("long",

"一座高大火红色的建筑，在高高的砖台上和两边边门相呼应\n"
"洞前立着一个巨大的石碑：\n"



   "                                   \n"
"              "+HIY+"□□□□□□□□□□□□\n"+NOR+""
"              "+HIY+"□                    □\n"+NOR+""
"              "+HIY+"□    飞龙山火龙洞    □\n"+NOR+""
"              "+HIY+"□                    □\n"+NOR+""
"              "+HIY+"□□□□□□□□□□□□\n"+NOR+""
);
  set("exits", ([ /* sizeof() == 3 */
          "west" : __DIR__"road5",
          "enter": __DIR__"dating",
]));
   set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yun" : 1,
 __DIR__"npc/zhangmen" : 1,
 __DIR__"npc/guard" : 3,
  ]));
 setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "enter" ) {
        if (objectp(present("zhang men", environment(me)))) {
        if((string)me->query("family/family_name")=="魔教") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("掌门大师兄喝道：里面闲人免进！\n");
        }
        }
        return ::valid_leave(me, dir);
}
