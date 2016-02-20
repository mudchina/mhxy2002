// dump.c (should be admin cmd?)
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
	string dump;
	seteuid(geteuid(me));
	write(RED"正在Dump．．．\n"NOR);
	dumpallobj();
	dump = read_file("/obj_dump");
	me->start_more(dump);
	write(GRN"．．．Dump完成！\n"NOR);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : dump
 
把所有内存中的物件的状态dump到根目录的一个叫做
OBJ_DUMP的文件中。

HELP
    );
    return 1;
}
 
