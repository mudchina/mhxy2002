// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第九宫人马座");
        set ("long",
             @LONG
                         :$?
                          :X$$?
                       :uW$$$M
                    :!M$#$$$$~ 射手座呈现的是半人半马的型态，具有动物和人类
                       :W$M$? 双重面目，是个着名的先知、  医生和学者。他是希
                     :X$# ~R~ 腊着名大英雄杰生 (Jason)、亚齐里斯 (Achilles)和
                    :W$"   ~ 亚尼斯   (Aeneas)的抚养者。传说他是卡罗拉斯(Cron
                   x$M  us)和斐莱拉 (Philyra)之子 ,也是宙斯的父亲。他是在受惊
                 :H$"  吓後，把自己变为马身，其母斐莱拉受不了儿子半人半马的
                x$$~   怪模样，便变成了一棵菩提树。
    :::: :: : :W$?:: : :
    $$$$$$$$$$$$$$$$$$$$?
    M$$$$$$$$$$$$$$$$$$$?~
    ~ ~ ~ :$$~ ~  ~    ~
         X$?~
         ~~~                                 

LONG);
        set("exits", ([
        "northup"    :       __DIR__"rm2mj1",
        "eastdown"  :       __DIR__"tx2rm2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/renma" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("ren ma") && dir == "up" )
        return notify_fail("宙斯笑道:先过我这关再说！\n");
        return ::valid_leave(me, dir);
}
void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
