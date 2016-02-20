//by tianlin 2001.5.1

#include <ansi.h>
inherit F_CLEAN_UP;

int report()
{
      write("梦幻西游("HIR"当机原因"NOR")：");
      write(read_file("/log/static/shutdown"));
    return 1;
}

int main()
{
	report();
//          write("\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : dangji
 
这个指令告诉你这个MUD为什么当机。
 
HELP
    );
    return 1;
}


