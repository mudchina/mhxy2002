// LLY@FYSY
inherit ROOM;

void create()
{
	object con, item;

	set("short", "农家");
	set("long", @LONG
谢家村并不因为和神剑山庄有着关系而富贵繁华，这个民居就能证明
一切了，木板门虚掩著，屋内空无一人，摆设的都是男耕女织所须的工具和
几样生活必需品，但墙上都挂着一柄铁剑，这也许就是和别的农家不同的地
方了把。
LONG
	);
	set("exits", ([
		"south" : __DIR__"croad1",
	]));
	set("coor/x",-1035);

	set("coor/y",20);

	set("coor/z",0);
	setup();
}


