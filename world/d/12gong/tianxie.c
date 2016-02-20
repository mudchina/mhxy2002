// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第八宫天蝎座");
        set ("long",
             @LONG
      iWWW:  :W$WW   :xW$Wx
     W$$$$ :$$$$$$X u$$$$$$
    W$$$$$W$#~$$$$$$$?~$$$$!       天后朱娜命天蝎从阴暗的地底爬出来，攻击欧立
   X$?$$$$$?  M$$$$#   $$$$~ 安（ Orion,戴安娜所锺情的猎人，後化为猎户星
  H$! $$$$!   8$$$$    $$$$! 座）。另外一次，天蝎施放毒气攻击正驾着太阳
  ~~  $$$$    8$$$8    $$$$~ 神马车经过的菲顿，而使丘比特有机会发射雷电
      $$$$~   8$$$8    $$$$! ，将奔跑中的太阳车击毁。
      $$$$    M$$$8    $$$$!
      $$$$    8$$$8    $$$$~
      $$$$    M$$$8    $$$$!       Xi
      $$$$    8$$$8    $$$$!      X$R
      $$$$    R$$$8    $$$$~    xW$$!
      $$$$    #$$$M    $$$$   W$$$$$
                       $$$$     $$$8
                       $$$$!  :$$  $
                       ~#$$$oW$#

LONG);
        set("exits", ([
        "eastup"    :       __DIR__"tx2rm1",
        "southdown"  :       __DIR__"tc2tx2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tianxie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("tian xie") && dir == "up" )
        return notify_fail("哈迪斯笑道:先过我这关再说！\n");
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
