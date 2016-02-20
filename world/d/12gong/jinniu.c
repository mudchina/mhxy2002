//By tianlin@mhxy for 2002.1.27,从新修改

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第二宫金牛座");
        set ("long", @LONG
   uiWW!             !WWu:
     :W$$#~             ~"*$$X
   :W$$#                   ~$$$!
   $$$!                      #$$!
  !$$#                       ~$$$
  $$$!                        $$$
  !$$W                       :$$$
   $$$W                     :W$$T  □  □经希腊哈莫尼亚地方的贝纳斯河，国王贝
   ~#$$$W: ::WWWWWWWWWX  :uW$$$#~ 纳斯有位美丽的公主赫洛蓓，有一天，，公主和
     ?$$$$$$$$*#*#*#*$$$$$$$$#~ 侍女们到野外摘花，玩耍，突然出现一只如雪花般
       ~"*$$$$~      #$$$*#"~ 洁白的牛，以级温柔的眼光望著赫洛蓓，其实这只牛
          W$$~        #$$~: 是仰慕公主美色的宙斯变的。一开始公主的确大吃一惊，
         !$$R         ~$$! 但仍走向温驯的牛只身旁，轻轻抚摸它。由于公牛显得
          #$$!        W$$  非常乖巧而温驯，于是公主就放心的爬到牛背上试骑，忽
           #$$W :   :$$$~ 然间牛奔跑了起来，最后跳进爱琴海。公主紧抱著牛，海
            ~$$W   :$$# 里生物皆出来向宙斯行礼，公主终于知道牛是宙斯的化身，
             ~#$$WW$$# 到了克里特岛后，就和宙斯举行婚礼，化身为牛的宙斯和赫
               "###?~ 洛蓓公主过著幸福的日子。

LONG);


        set("exits", ([
        "westup"    :       __DIR__"jn2sz1",
        "northdown"  :       __DIR__"by2jn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jinniu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("12gong/jinniu","done"))
        return ::valid_leave(me, dir);
        if (dir == "westup" ) {
        if (objectp(present("jin niu", environment(me)))&&!wizardp(me))
        return notify_fail("阿弗罗迪蒂笑道:先过我这关再说！\n");
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
