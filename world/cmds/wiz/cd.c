//By tianlin@mhxy for 2001.10.8
//部分优化
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir;

	seteuid(geteuid(this_player(1)));
	//add by jackyboy 98/12/10
	//阻止不可读的目录和文件被显示出来。

	if( !arg )
		arg = user_path(me->query("id"));
	dir = resolve_path(me->query("cwd"), arg);
	if(file_size(dir)!=-2) return notify_fail(WHT"没有这个目录。\n"NOR);
	if(dir[strlen(dir)-1]!='/') dir += "/";
	write(RED"改变当前目录为："NOR+YEL+dir+NOR"\n");
	me->set("cwd", dir);
	return 1;	
}

int help(object me)
{
	write(@HELP
指令格式 : cd <子目录名>, cd .. , and cd

将目前参考的目录移至指定的子目录或回到上一主目录; 亦可直接回到自己工作目录。
HELP
	);
	return 1;
}
