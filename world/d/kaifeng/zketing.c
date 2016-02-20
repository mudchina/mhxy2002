// by cih 10/01/2002
// Room: /d/kaifeng/zketing
inherit ROOM;

void create ()
{
    set ("short","客厅");
	set ("long", @LONG

这里就是天蓬的客厅了。四周有几扇木窗，都是上明下暗的
的雕花格子。北面正中靠壁挂着一张画。你仔细一看：乖乖
可不的了！上面居然画着一个硕大的猪头！！画的下放放着
一张八仙桌。桌子旁边有两排太师椅。屋子的正中还有一个
大大的黄金香炉。
LONG);

	set("exits", 
	([ //sizeof() == 4
  "up" : __DIR__"zzoulang3",
  "northwest" : __DIR__"zhu1",
  "east" : __DIR__"neitang",
	]));
	
	set("objects", 
	([ //sizeof() == 1
  __DIR__"npc/zhubing" : 1,
	]));

	set("valid_startroom", 1);

	setup();
}

