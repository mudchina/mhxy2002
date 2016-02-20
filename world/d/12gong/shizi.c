// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第五宫狮子座");
        set ("long", @LONG
                ::::
           :uW$$$$$$$$Wx:
         :W$##""""#R$$$$$X
        X$?          "$$$$X
       X$?             #$$$:
       $$!              M$$
       R$8:             !$$     传说中和这星座有关的表徵是位於希腊之尼米安
       ~$$$W:           !$?  (Nimean)谷地的一头狮子，在一次搏斗中被海克
      :X$$$$$W:         MM   利思杀死。
    :H$$###R$$$X:      :$!
   :$$"      ?$$W      HM
   $$!        ?$$:     $$
  !$$         !$$      $$X
   R$W:      :8$!      M$$WxX!
    #$$WuxxxW$$?        R$$$"
      "#R$$$#"           "#R
LONG);


        set("exits", ([
        "northup"    :       __DIR__"sz2sn1",
        "eastdown"  :       __DIR__"jx2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shizi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shi zi") && dir == "up" )
        return notify_fail("阿波罗冷笑：先过我这关再说！\n");
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
