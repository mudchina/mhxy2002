// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第十二宫双鱼座");
        set ("long",             @LONG
   ~?$$$$W:                x$$$$#
      ?$$$$u :           :$$$$#
        "$$$W           :$$$#~
          #$$$:        W$$$~
           #$$$       !$$$!                                             
            $$$X      $$$!   维纳斯和丘比特有一次被巨人泰峰（ Typhon）所
            M$$$:: ::H$$$  追逐，双双跳入幼发拉底河中，化身为鱼逃走。蜜妮
            !$$$$$$$$$$$$  华（ Mineave，雅典娜的别名）将鱼化为星辰置於天
            !$$$"#"""$$$8  上，以纪念这件事。
            H$$$     ?$$$
            $$$?     ~$$$!
           W$$$       M$$$:
          W$$$~        #$$$:
        :$$$#           ?$$$x:
      xW$$$?             "$$$$u
    !R$$$#                 "*$$$!
LONG);
        set("exits", ([
        "north"    :       __DIR__"topalace1",
        "southdown"  :       __DIR__"bp2sy2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangyu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shuang yu") && dir == "up"&&me->query("title")!="黄金战士"&&!wizardp(me) )
        return notify_fail("波士顿笑道:先过我这关再说！\n");
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
