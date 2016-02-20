//modify by ken
//2001.7.7
#include <room.h>
inherit ROOM;
int can_enter=1;
void create ()
{
        set ("short", "人塔");
        set ("long", @LONG

进了这里，你发现只有一个很大的箱子.......
 
LONG);
        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"tower",
        ]));        
        set("no_clean_up", 1);
        can_enter=1;

        setup();
}


void init()
{
        add_action("do_break", "break");

        if( query("started") != 1 )
        {
                set("started", 1);
           call_out("generate_dan", 20000+random(80)*360);
        }
}

void generate_dan()
{
        remove_call_out("generate_dan");
        set("available", 1);
}

void reset_enter()
{
    can_enter=1;
}

int do_break(string arg)
{
        object me, dan;
        int sen;

        me = this_player();
//        notify_fail("你大喝一声，把箱子给打开了！但是里面什么也没有。\n");
        
        if(me->is_busy()) return 0;
        sen=me->query("sen");
        if(sen<110) return 0;
        sen-=100;
        me->set("sen",sen);
        sen=(me->query("combat_exp")+me->query("max_mana"))/2;
        if(sen<10000) return 0;
        if( query("available") == 1 )
        {
                set("available", 0);
                dan = new(__DIR__"obj/huwan");
                dan -> move(this_object());
                message_vision("$N大喝一声，把几千斤的箱子举了起来，发现了一颗闪光的东西。\n", me);

                remove_call_out("generate_dan");
                call_out("generate_dan", 36000+random(100)*360);//15 hours

                return 1;
        }
        else
        { 
                if( can_enter && 
                        (string)me->query("zhangmen/base_name") 
                        == "/d/mojiao/npc/zhangmen")
                {
                        message_vision("一道金光一闪，$N被罩了进去。\n", me);
                        me->move(__DIR__"tower");

                        // mon 10/19/20
                        // can only enter again after a while.
                        can_enter=0;
                        call_out("reset_enter",1200+random(1200));
                        return 1;
                }
                else return 0;
        }
}

int clean_up()
{
        return 0;
}
