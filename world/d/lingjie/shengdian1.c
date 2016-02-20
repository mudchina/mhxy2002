#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"圣殿一层"NOR);
        set("long", @LONG
这里便是灵界的圣殿了,一眼望去,只见烟雾弥漫在圣殿的
周围。不时有几只奇怪的鸟飞过，一声声怪叫，不仅让人
有些毛骨悚然。
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian2",
                "down" : __DIR__"shengdian",
        ]) );
        set("objects", ([
                __DIR__"npc/ling":1,
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
}

int valid_leave(object me, string dir)
{       
        object a;
//        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("ling", environment(me))) && living(a) && me->query("family/family_name")!="灵界")
                return notify_fail("仙草-灵对你大喝一声：你不是本派的，进去找死吗！\n");

        return ::valid_leave(me, dir);
        }

        return 1;
}
