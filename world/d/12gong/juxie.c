// by HAPP@YSZZ
#include <ansi.h>
inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第四宫巨蟹座");
        set ("long", @LONG
               :XxuxuX:::
        :uWW$$$$$$$$$$$$$$$Wix:
     :U$$$$$#""~~      ~~""##$$$ix      宇宙之神爱上了狩猎女神後
   !W$$$$$$$$$Wi:             ~~#*$W::  终日和她追逐於森林之中
  !$$*"~    ~"T$$$:                ~#8: 当狩猎女神生下一女儿
  $$?          ~$$$          :          神之后相当愤怒
 !$$            X$$    XWW$$$$$$$Wu:    派九头巨蟹去杀害母女两人
 !$$:       :  ~8$$  !$$$?~     ~?*$W:  狩猎女神为了保护自己的女儿
  ?$$X        !W$$! !$$!           #$8  勇敢的和巨蟹抟斗因而受伤
   ~T*$$WWW$$$$*!~  !$$            !$$  神之后被她的母爱所感动
       ~~"~!~       !$$X  :        W$$  让小女孩升空成了巨蟹星座 ......
 !W::                ?$$Wx:     :!W$$!
  ~#$WU::             ~#*$$$WWW$$$$#~
     "#$$$Wxx::          ::W$$$$$#~
        ~"#$$$$$$$$$$$$$$$$$$#"~

LONG);


        set("exits", ([
        "eastup"    :       __DIR__"jx2sz1",
        "southdown"  :       __DIR__"sz2jx2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/juxie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("12gong/juxie","done"))
        return ::valid_leave(me, dir);
        if (dir == "eastup" ) {
        if (objectp(present("ju xie", environment(me)))&&!wizardp(me))
        return notify_fail("阿提米斯:先过我这关再说！\n");
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
