//By tianlin@mhxy for 2002.1.27从新修改

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第三宫双子座");
        set ("long", @LONG
  W$$Wu                :uW$$W
  $$ "*$i             W$#~ $$
   #$x ~$W:          $$~ x$#
    ~*$W$$$:       !$$$i$*~
       !$$$$WWiWiWW$$$$~
        $$$$$~~~~~$$$$W~
        $$$$$!   !$$$$8     神话故事中几乎找不到和双子星座有关的传说。在埃及
        $$$$$W   8$$$$8  它的名称为「孪子星」，是以这星座中最明亮的两颗星卡
        $$$$$$  ~$$$$$$  斯达 (Castor)和波利克斯 (Pollux)命名，这两颗星另外还
        $$$$$$   $$$$$8  有两组名称，分别为海克利斯 (Hecules)、阿波罗 (Apollo)
        $$$$$$   $$$$$8  ，崔特勒玛 (Tritolemus)、艾逊 (Iasion)。埃及人观念中
        $$$$$M   $$$$$8  的孪子座为幼童，而非一般常见的成人形象。
        $$$$$!   !$$$$8
        $$$$$xuuu:$$$$8
      :u$$$$*######$$$$u:
    x$$#$$$~       ~$$$#$W::
  :$$~ x$#           *$: ~$W
 !$$ uW$"             "$iu $$
 ~#**#~~               ~~#**#

LONG);


        set("exits", ([
        "southup"    :       __DIR__"sz2jx1",
        "westdown"  :       __DIR__"jn2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangzi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("12gong/shuangzi","done"))
        return ::valid_leave(me, dir);
        if (dir == "southup" ) {
        if (objectp(present("shuang zi", environment(me)))&&!wizardp(me))
        return notify_fail("阿雷斯冷笑一声：先过我这关再说！\n");
        }   
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
    if (verb == "zhaohuan") return 1;
    return 0;
}
