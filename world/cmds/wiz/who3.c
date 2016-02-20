// who3.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object ob, *ob_list;
    int i;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG" 玩家      悟性-后天 根骨-后天 灵性-后天 膂力-后天 福缘 容貌\n"NOR;
    str += "——————————————————————————————————\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        str += sprintf(NOR"%-10s  ",ob->name());
        str += sprintf(HIR"%-2d:  ",ob->query("int"));
        str += sprintf(HIR"%-2d   ",ob->query_int());
        str += sprintf(HIG"%-2d:  ",ob->query("con"));
        str += sprintf(HIG"%-2d   ",ob->query_con());
        str += sprintf(HIY"%-2d:  ",ob->query("spi"));
        str += sprintf(HIY"%-2d   ",ob->query_spi());
        str += sprintf(HIB"%-2d:  ",ob->query("str"));
        str += sprintf(HIB"%-2d   ",ob->query_str());
        str += sprintf(HIC"%-2d   ",ob->query("kar"));
        str += sprintf(HIM"%-2d \n"NOR, ob->query("per"));
    }
    str += "——————————————————————————————————\n";
//    str = sprintf("%s共有 %d 位使用者连线中。\n", str, sizeof(ob_list));
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

