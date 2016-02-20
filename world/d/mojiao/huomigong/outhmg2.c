
// create by qlwy 27/06/2001
// room: maojiao/outhmg0.c

inherit ROOM;

void create ()
{
        set ("short", "岩洞");
        set ("long", @LONG

这里火势好象小了点，不时还有阵阵的凉风吹了，饱受
火迷宫煎熬的你来到这才松了一口气，定眼一看风好象
是从南面吹进来的。

LONG);
        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"exit",
                "west"  : __DIR__"hmg"+sprintf("%d", random(7)),
                "north" : __DIR__"hmg"+sprintf("%d", 6+random(7)),
                "east"  : __DIR__"hmg"+sprintf("%d", random(7)),
]));
        setup();
}

int valid_leave (object me, string dir)
{
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
        if( me->query_temp("hmg10") ) me->delete_temp("hmg10");
        if( me->query_temp("hmg11") ) me->delete_temp("hmg11");
        if( me->query_temp("hmg12") ) me->delete_temp("hmg12");
        if( me->query_temp("hmg_ready_out") ) me->delete_temp("hmg_ready_out");
        return ::valid_leave(me, dir);
}

