// by HAPP@YSZZ

inherit ROOM;
 int block_cmd(string);
void create ()
{
        set ("short", "第十一宫宝瓶座");
        set ("long",             @LONG
 :i$$$$Wx     xoW$$$$$Wu:      xi$$$$$Wx:     :ui:
 "#*$$$$$$WW$$$*#"#$$$$$$$$WW$$$**$$$$$$$$WeW$$*#
  : ~ #$$$$$*"~     ~#$$$$$$#"~    "#$$$$$$*#"
                       ~                        ~
 :xW$$Wi      :xiW$$$Wi::       iW$$$Wu:       :u:
 !$$$$$$$Wooo$$$*#$$$$$$$$Wooo$$$$$$$$$$$iuooW$$#
     "*$$$$$$#~     "*$$$$$$$#"   ~"*$$$$$$$*"~
        ~"~            ~~"~           ~~~
            特洛伊的王子干尼梅德是个黄金般的美少年，有一天他在牧羊时，
        突然被宙斯变成的老鹰捉到奥林帕斯，负责嫁给海克力斯的西碧公主    
        原所担任的斟酒工作。在古代的罗马，当太阳的位置在这个星座的第
        一个月为雨季，所以定名为水瓶。

LONG);
        set("exits", ([
        "southup"    :       __DIR__"bp2sy1",
        "westdown"  :       __DIR__"mj2bp2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baoping" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
        if ( present("bao ping") && dir == "up" )
        return notify_fail("乌拉诺斯笑道:先过我这关再说！\n");
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
