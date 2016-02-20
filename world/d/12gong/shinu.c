// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第六宫室女座");
        set ("long", @LONG
   !$$$$$!:i$$$$$W: :W$$$$Wu:  uWW$WWu
    ~$$$$W$*" ~$$$$W$#~ !$$$$W$$#*$$$$:
     $$$$$~    $$$$$~    $$$$$?~  !$$$
     $$$$!     $$$$$     $$$$!    W$#
    ~$$$$!     $$$$!     $$$$~  u$*~      根据罗马神话，处女座又名艾思翠诗
     $$$$!     $$$$!     $$$$ :W$"   (Astraes)，为天神丘比特和希蜜丝女神的
     $$$$~     $$$$H     $$$$W$#~  女儿，是正义女神。黄金时代末期，人类触犯
     $$$$      $$$$!     $$$$#~ 了她，於是大怒之下回到天庭。
    ~$$$$!     $$$$H    :$$$$
    !$$$$!     $$$$!  :W$$$$$
    !$$$$!    !$$$$R i$$~$$$$
   ~**###*~  ~#**#*#W$#  $$$!
                    $$  X$$!
                    $W:W$$~
                    *$$*#

LONG);


        set("exits", ([
        "westup"    :       __DIR__"sn2tc1",
        "northdown"  :       __DIR__"sz2sn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shinu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shuang zi") && dir == "up" )
        return notify_fail("赫尔梅斯冷笑：先过我这关再说！\n");
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
