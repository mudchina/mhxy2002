// giveall.c
//by tianlin 2001/5/1
/*请不要连续使用本命令，特别是在人多的时候，会给系统带来很大负担*/

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string what)
{
    object ob, *ob_list, ob1;
    int i;
    string str;
    
    if(!what) return notify_fail("指令格式 giveall 物品路径\n");
    
    if( sscanf(what, "%*s.c") != 1) return notify_fail("路径不合法，无法找到物品。\n");
    
    if( file_size(what) < 0 )
		return notify_fail("没有这个档案(" + what + ")。\n");    
    
    seteuid(getuid());

    ob_list = users();

    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob1 = new(what);
        ob1 -> move(ob); 
        tell_object(ob, "突然间你看到一个人,呀!原来是南瓜派人送东西来了!赶快看看是什么吧.\n" );
                     
    }
    str = sprintf("共有 %d 位玩家得到了%s。\n", sizeof(ob_list), what->query("name"));    
    me->start_more(str);
    return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家一件物品。
HELP
        );
        return 1;
}
