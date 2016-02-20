// tian5.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "µÚ¾ÅÖØÌì¡¤Áé·ğÌì");
  set ("long", @LONG

                         s________________s         
                        /LLLLLLLLLLLLLLLLLL\        
    []__[]             ^^||======||======||^^             []__[]
    []==[]_[]__[]__[]__[]||[]__[]||[]__[]||[]__[]__[]__[]_[]==[]
    []==[]|__|__|__|__|__|__|©³©¥©¥©¥©·_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_©§[1;31m¾Å[1;37mÖØÌì[0m©§__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__|©»©¥©¥©¥©¿_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|__/       \__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__||        | |_|__||__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__©°©´©°©´_|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|©¸©¼©¸©¼|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]
                     µÀÓïÎò    ·ğĞÄÎò    ÏÉÔµÎò
ÕâÀï¾ÍÊÇµÚ¾ÅÖØÌì¡¤Áé·ğÌì¡¤
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"midong9",
  "south" : __DIR__"road9",

]));
  set("objects", ([
             __DIR__"npc/tianjiang" : 2,
        ]));
        set("no_clean_up", 0);
        setup();

}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me=this_player();
        
        if( !arg || (arg!="sky" && arg!="Ìì") )
                return notify_fail("ÄãÒªÅÀÊ²Ã´£¿\n");
        if(me->is_busy())
                return notify_fail("ÄãºÜÃ¦£¬ÅÀÊ²Ã´Ñ½£¡\n");

        message_vision("$N´êÁË´êÊÖ£¬Ë³×ÅÔÆÂ·ÍùÉÏÅÀ... \n", me);
        me->start_busy(3);

        if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
                call_out("faila", 3, me);
                return 1;
        }

        if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=100 ){
                call_out("faila", 3, me);
                return 1;
        }

        call_out("success", 3, me);
        return 1;
}
int success(object me)
{
        message_vision("$NÔ½ÅÀÔ½¸ß£¬½¥½¥ÒşÈëÁËÔÆÖĞ ... \n", me);
        me->move("/d/guzhanchang/ge");
        me->receive_damage("kee", 400);
        me->receive_damage("sen", 400);
        message_vision("$NÂıÂıµÄÅÀÁËÉÏÀ´¡£\n", me);
        return 1;
}
int faila(object me)
{

        tell_object(me, "ÄãÊÖÉÏÒ»¸ö²»ÎÈ£¬´ÓÔÆÖĞµôÁËÏÂÀ´ ... \n");
        tell_room(environment(me), me->name()+"»ÎÓÆÓÆµÄ´ÓÔÆÖĞµôÁËÏÂÀ´¡£\n", ({me, me}));
        
me->unconcious();
        return 1;
}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("tianjiang", environment(me))) && living(a) )
                return notify_fail("Ìì½«ºÃÏó²»Ô¸ÈÃÄã¹ıÈ¥£¡\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}







