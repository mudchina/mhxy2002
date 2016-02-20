// LLY@FYSY
inherit ROOM;

void create()
{
	set("short", "客栈");
	set("long", @LONG
一个很普通的客栈，门前一根一丈高的旗杆，上面挂著个灯笼，
上面写著“谢”，这是村中唯一的一个客栈，客栈不是很大，装饰
得也不怎样，但是生意却很不错，因为一年四季都不断的有江湖中
人经过这里，去神剑山庄挑战谢晓峰。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"croad1",
	]));
        set("objects", ([
                __DIR__"npc/waiter1" : 1,
        ]) );
	set("coor/x",-1035);

	set("coor/y",10);

	set("coor/z",0);
	setup();
replace_program(ROOM);

}
