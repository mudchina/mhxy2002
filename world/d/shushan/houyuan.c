//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
	set ("short", "后院");
	set ("long", @LONG

这里是蜀山的后院,这里空荡荡的什么也没有,只有两个弟子
在这里站着。再往北走就是蜀山的金鞭崖了。
LONG);

	set("exits", 
	([    
       "northup" : __DIR__"houshan",
       "south" : __DIR__"houdian",
       ]));
       set("objects", ([         
         __DIR__"npc/hdizi" : 2,
       ]));
       setup();
}
int valid_leave(object me, string dir)
{
    if ( dir == "northup" ) {
        if(objectp(present("di zi", environment(me))))
            return
notify_fail("蜀山弟子说道:后面是蜀山金鞭崖最好不要去！\n");
    }
    return ::valid_leave(me, dir);
}
