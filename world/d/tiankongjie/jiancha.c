// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "通道");
  set ("long", @LONG

这里有天空界的启蒙师傅。正邪不能并存。自己斟酌考虑吧。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : "/d/changan/southseashore",
  "up" : __DIR__"bianjing",
]));
  set("objects", ([//sizeof() == 2
    __DIR__"npc/yiping" : 1,
__DIR__"npc/heimukai" : 1,
  ]));
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "bian") return 1;
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    if (verb == "cast") return 1; //by cjl
    if (verb == "fly") return 1; //by cjl
        return 0;
}

int valid_leave(object me, string dir)
{
    object guard, *inv, letter;
    int i;

    if(dir != "up")
        return ::valid_leave(me, dir);
    inv=all_inventory(me);
    i=sizeof(inv);
    me->delete_temp("condition/carrying_player");
    if(objectp(present("yiping", environment(me))))
   guard=present("yiping", environment(me));
    if(!guard) return ::valid_leave(me,dir);
    while (i--)
    {
        if (userp(inv[i]))
            me->add_temp("condition/carrying_player", 1);
        continue;
    }
    if(me->query_temp("condition/carrying_player"))
    {
        return notify_fail(CYN "背个人上天空界？累不累呀？\n"NOR);
    }
    if (!(letter=present("shu xin", me)
       && letter->query("header")=="天空界的人。") 
     && me->query("family/master_id")!="rigao yiping"
&& me->query("family/master_id")!="heimu kai"
&& me->query("family/master_id")!="li jia"
&& me->query("family/master_id")!="yintuo luo"
&& me->query("family/master_id")!="jixiang tian"
&& me->query("family/master_id")!="xie wu"
&& guard)
    {
        return notify_fail(CYN "呵呵，现在可不行哟。不是天空界的可不能进去哟。\n"NOR);
    }

    //finally...
    return ::valid_leave(me, dir);
}


