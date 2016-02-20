// huifu.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        int length;

        if( me!=this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s", arg)!=1 )
                return notify_fail("指令格式：huifu <使用对象>\n");
        
        if( !objectp(ob = present(arg, environment(me))) )
                return notify_fail("你只能恢复你身边使用者的状态。\n");

        ob->remove_all_enemy();

        message_vision(GRN "$N对$n大喝一声“不许动！”$n左看了右看，上看了下看最后乖乖的停手了。\n" NOR, me, ob);
        
      ob->setup();

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : ding <某人>

停止指定对象当前的战斗。

HELP
    );
    return 1;
}