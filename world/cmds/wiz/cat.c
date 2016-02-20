//By tianlin@Mhxy for 2002.1.2.修改

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return notify_fail("你想要显示那个档案?\n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("没有这个档案。\n");
	cat(file);
 CHANNEL_D->do_channel( this_object(), "sys",
sprintf("〓监视〓-> 巫师：%s(%s) 正在察看(cat) %s文件 \n",me->name(1), geteuid(me),file ,  ));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : cat <档案>

此指令可让你直接读取某档案之程式。
HELP
    );
    return 1;
}
