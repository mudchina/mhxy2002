
// create by qlwy 28/06/2001
// room: maojiao/hmg10.c

inherit ROOM;

void reset_path(object);
void create ()
{
        set ("short", "火岩洞");
        set ("long", @LONG

这里跟外面的火迷宫又不一样,火焰特别的高,岩浆不停的流向四面
八方，似乎竟是这个火迷宫热力的源泉。

LONG);
        set("exits", 
        ([ //sizeof() == 4
                "southeast" : __DIR__"hmg0",
                "southwest" : __DIR__"hmg4",
                "northwest" : __DIR__"hmg6",
                "northeast" : __DIR__"hmg8",
]));
        setup();
}

void init()
{
        object me=this_player();
        me->add_temp("hmg10",1);
        if( me->query_temp("hmg_ready_out")==1 && me->query_temp("hmg10")<3 )
        call_out("send_out", 5, me);
        if( me->query_temp("hmg10")>=3 )
        {
                reset_path(me);
                call_out("free_send", 5, me);
        }
}

void reset_path(object me)
{
        me = this_player();
        if( me->query_temp("hmg0") ) me->delete_temp("hmg0");
        if( me->query_temp("hmg1") ) me->delete_temp("hmg1");
        if( me->query_temp("hmg2") ) me->delete_temp("hmg2");
        if( me->query_temp("hmg3") ) me->delete_temp("hmg3");
        if( me->query_temp("hmg4") ) me->delete_temp("hmg4");
        if( me->query_temp("hmg5") ) me->delete_temp("hmg5");
        if( me->query_temp("hmg6") ) me->delete_temp("hmg6");
        if( me->query_temp("hmg7") ) me->delete_temp("hmg8");
        if( me->query_temp("hmg8") ) me->delete_temp("hmg8");
        if( me->query_temp("hmg9") ) me->delete_temp("hmg9");
        if( me->query_temp("hmg11") ) me->delete_temp("hmg11");
        if( me->query_temp("hmg12") ) me->delete_temp("hmg12");
        return;
}

void send_out(object me)
{
message_vision("突然从火岩洞里面喷出一股热浪，$N慌不及待的找了个出口躲开了。\n",me); 
        me->move(__DIR__"outhmg"+sprintf("%d",random(4)));
message_vision("一股热浪，把$N冲到这来了。\n",me); 
        return;
}

void free_send(object me)
{
        me->set_temp("hmg10",0);
  message_vision("突然从火岩洞里面喷出一股热浪，$N慌不及待的找了个出口躲开了。\n",me); 
        me->move(__DIR__"hmg"+sprintf("%d",random(13)));
        message_vision("一股热浪，把$N冲到这来了。\n",me); 
        return;
}

int valid_leave (object me, string dir)
{
        if( me->query_temp("hmg10")>=3 || me->query_temp("hmg_ready_out") )
        return notify_fail("火岩洞里到处是岩浆，气温袭人，你竟不知道往那个方向走才好。\n");
        return ::valid_leave(me, dir);
}

