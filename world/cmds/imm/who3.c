// COMMAND who3.c
// Last modified by zeus@刀剑笑 Dec.30 1999

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object ob, *ob_list;
    int i;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG" 玩家      膂力-后天 悟性-后天 根骨-后天 身法-后天 资质-后天 福缘-后天 容貌-后天\n"NOR;
    str += "———————————————————————————————————————————————————————\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        str += sprintf(NOR"%-10s  ",ob->name());
        str += sprintf(HIB"%-2d:  ",ob->query("str"));
        str += sprintf(HIB"%-2d   ",ob->query_str());
        str += sprintf(HIR"%-2d:  ",ob->query("int"));
        str += sprintf(HIR"%-2d   ",ob->query_int());
        str += sprintf(HIG"%-2d:  ",ob->query("con"));
        str += sprintf(HIG"%-2d   ",ob->query_con());
        str += sprintf(HIY"%-2d:  ",ob->query("dex"));
        str += sprintf(HIY"%-2d   ",ob->query_dex());
        str += sprintf(HIB"%-2d:  ",ob->query("spi"));
        str += sprintf(HIB"%-2d   ",ob->query_spi());
        str += sprintf(HIC"%-2d   ",ob->query("kar"));
        str += sprintf(HIC"%-2d   ",ob->query_kar());
        str += sprintf(HIC"%-2d   ",ob->query("per"));
        str += sprintf(HIC"%-2d \n"NOR,ob->query_per());
    }
    str += "———————————————————————————————————————————————————————\n";
    str = sprintf("%s共有 %d 位使用者连线中。\n", str, sizeof(ob_list));
    me->start_more(str);
    return 1;
}
int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;
        if( wizardp(ob2) && !wizardp(ob1) ) return 1;
        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2)
                        - (int)SECURITY_D->get_wiz_level(ob1);

        return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
指令格式：who3

玩家信息查询。
HELP
        );
        return 1;
}            

