// yudian 2000-11-13
#include <ansi.h>
inherit F_CLEAN_UP;
mapping hoodname=([
                      "(elder)": HIC "★荣誉玩家" NOR "  (elder)  ",
                     "(immortal)" : HIM "★客座巫师" NOR " (immortal) ",
                    "(apprentice)" : HIG "★巫师学徒" NOR "(apprentice)",
                    "(wizard)" : HIB "★巫    师" NOR "  (wizard)  ",
                        "(arch)" : HIG "★神    仙" NOR "   (arch)   ",
             "(admin)" : HIW "★逍 遥 仙" NOR "  (admin)   ",
]);

int level(mixed, mixed);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int j = 1;
        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
//      str = "◎ " + MUD_NAME + "目前共有" + chinese_number(sizeof(list)) + "位巫师：";
            str = HIM"〖仙侣情缘〗"HIY"·"HIG"知秋站"NOR"巫师组全家福";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        if (j%8) str += "\n";
                        str += sprintf("%-13s" NOR ": ", hoodname[hood]);
                        j = 1;
                }
        if (!(j % 8)) {
            str += sprintf("%14s", "");
                        j++;
                }
                str += sprintf("%-9s%s", capitalize(list[i]),
                        (j%8==7) ? "\n" : "");
        }
        me->start_more(str);
        return 1;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 < ob2?-1:1;
}

int help(object me)
{
write(@HELP
  指令格式 : wizlist
用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}
