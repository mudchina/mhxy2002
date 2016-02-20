//changlang1.c by yuahu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short",HIR "「" HIY "长廊" HIR "」" NOR);
	set ("long", @LONG

这是大殿西厢的一条长廊，西面是练武场。小廊上是木板铺地，
打扫的极为干净，走在上面发出吱吱的响声。走廊两面的木格内
雕着一些山水人物。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"westlianwu",
		"east" : __DIR__"dadian",
	]));

	setup();
}
