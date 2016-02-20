// Room: /d/city/jiaowai8.c
//星星lywin4/29

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小树林");
    set("long", @LONG
这是长安郊外的一片小树林，落英缤纷，蜂歌蝶舞，朝露夕光，沁人
心脾。呼朋唤友开怀欢乐正其时。周围小树颗颗健美，上有无数的小鸟小
雀在树梢上欢歌，一点也不怕人。这正是个打鸟（da）的好机会。
LONG );
    set("exits", ([
        "east" : "/d/kaifeng/east1",
        "west" : __DIR__"dongmen",
    ]));
    set("no_clean_up", 0);
    set_temp("wayao1",1);
    set("outdoors", "yangzhou");
    setup();
}

void init()
{
        add_action("do_da", "da");
}


int do_da()
{
        object me;
        int i, kar, cps, bb,mm;
        me = this_player();

        if(me->is_busy())
             return notify_fail("你还是等弓装好了箭再打鸟吧！\n");

        if(me->query("kee")<10)
             return notify_fail(HIR"你还是先休息一下吧，射箭也要用力气哟。。\n"NOR);

                           me->start_busy(3);
        message_vision("$N拿起儿时玩耍用的小弓小箭，瞄准树上的小雀射去......\n", me);

               message_vision("$N只听树上一阵鸟儿急鸣…\n",me);
        kar = me->query("kar");
        
        if (random(kar)>15) {
                message_vision("$N打到一只"HIW"百灵鸟。\n"NOR, me);
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",100+bb);
                        tell_object(me,"你得到了100点经验\n");
                }
       me->receive_damage("kee", 10);
                bb=(int)me->query("potential");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        me->set("potential",40+bb);
                        tell_object(me,"你得到了40点潜能\n");
                }

                return 1;
        }
        
        if (random(kar)>10) {
                message_vision("$N打到一只"HIY"金丝雀。\n"NOR, me);
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",80+bb);
                        tell_object(me,"你得到了80点经验\n");
                }
       me->receive_damage("kee", 10);
                bb=(int)me->query("potential");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        me->set("potential",bb+30);
                        tell_object(me,"你得到了30点潜能\n");
                }

                return 1;
        }
        
        if (random(kar)>8) 
            {
               message_vision("$N打到一只"HIG"鹦鹉。\n"NOR, me);
                bb=(int)me->query("combat_exp");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                        else {
                        tell_object(me,"你得到了50点经验\n");
                        me->set("combat_exp",50+bb);
                }
            me->receive_damage("kee", 10);  
                
                bb=(int)me->query("potential");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        me->set("potential",bb+20);
                       tell_object(me,"你得到了20点潜能\n");
               }

               return 1;
       }

        if (random(kar)>5) 
            {
               message_vision("$N打到一只"YEL"麻雀。\n"NOR, me);
                bb=(int)me->query("combat_exp");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                        else {
                        tell_object(me,"你得到了10点经验\n");
                        me->set("combat_exp",20+bb);
                }
            me->receive_damage("kee", 10);  
                
                bb=(int)me->query("potential");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        me->set("potential",bb+10);
                       tell_object(me,"你得到了20点潜能\n");
               }

               return 1;
       }
        else 
           {
                me->receive_damage("kee", 10);  
                message_vision("$N什么也没打到。\n",me );
     }

        return 1;
}

