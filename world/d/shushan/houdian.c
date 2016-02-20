//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
	set ("short", "后殿");
	set ("long", @LONG

后殿亦是宽敞素雅，只是空空荡荡地没放什么东西。再往北就是
蜀山的后院了。东西各有一条后廊通向天师洞。
LONG);

	set("exits", 
	([    
       "north" : __DIR__"houyuan",
	 "east" : __DIR__"houlang1",
        "west" : __DIR__"houlang",
       ]));
       setup();
}
