//Last modify by vikee.
//2000.12.15

#include <ansi.h>
inherit F_CLEAN_UP;

string chinese_daoxing(int gain);
string status_color(int current, int max);

int main(object me, string arg)
{
        object ob;
        mapping my;
        int dao,x,i;
        string str;
        seteuid(getuid(me));
        
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("您要察看谁的状态？\n");
        } 
		else return notify_fail("只有巫师才可以察看别人的状态。\n");

        my = ob->query_entire_dbase();

        printf(NOR CYN"┏━━━━━━━━━━━━━━"HIY"个"HIR"·"HIY"人"HIR"·"HIY"档"HIR"·"HIY"案"NOR CYN"━━━━━━━━━━━━┓\n"NOR,);
        printf(NOR CYN"┃"NOR WHT" 个人状态"NOR CYN" 姓 名："NOR WHT"%-12s "NOR CYN" 性别："NOR WHT"%-10s "NOR CYN"I D："NOR WHT"%-13s"NOR CYN"┃\n"NOR,ob->name(),ob->query("gender"),"["+capitalize(ob->query("id"))+"]");
        printf(NOR CYN"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"NOR);
        printf(NOR CYN"┃"NOR WHT"〖 气血 〗%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],my["max_kee"]),my["eff_kee"]*100/my["max_kee"]);
        printf(NOR WHT"  〖 内力 〗%s%7-d/%7-d(+%4d)"NOR CYN"┃\n"NOR,status_color(my["force"], my["max_force"]), my["force"], my["max_force"],my["force_factor"]);
        printf(NOR CYN"┃"NOR WHT"〖 精神 〗%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],my["max_sen"]),my["eff_sen"]*100/my["max_sen"]);
        printf(NOR WHT"  〖 法力 〗%s%7-d/%7-d(+%4d)"NOR CYN"┃\n"NOR,status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],my["mana_factor"]);
        if(my["food"]*100/ob->max_food_capacity()>100) str=HIC+"很饱";
        else if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"正常";
        else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"缺食";        
		else if(my["food"]*100/ob->max_food_capacity()>30) str=CYN+"缺食";
        else if(my["food"]*100/ob->max_food_capacity()>10) str=HIR+"缺食";
        else str=RED+"饥饿";
        printf(NOR CYN"┃"NOR WHT"〖 食物 〗%s%7-d/%7-d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));
        printf(NOR WHT"  〖 武学 〗%s%18-d    "NOR CYN"┃\n"HIG,HIY,(int)ob->query("combat_exp"));        
        if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"很饱";
        else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"正常";
        else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"缺水";
        else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"缺水";
        else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"缺水";
        else str=RED+"饥渴";
         printf(NOR CYN"┃"NOR WHT"〖 饮水 〗%s%7-d/%7-d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));
        printf(NOR WHT"  〖 潜能 〗%s%14-d "NOR CYN"       ┃\n"NOR,HIG,(int)ob->query("potential") - (int)ob->query("learned_points"));
        printf(NOR CYN"┃"NOR WHT"〖 官职 〗%s%21-d "NOR,HIG,(int)ob->query("office_number"));
        printf(NOR WHT"  〖 杀气 〗%s%20-d "NOR CYN" ┃\n"HIG,HIR,(int)ob->query("bellicosity"));
	
		dao=(int)ob->query("daoxing");       
        printf(NOR CYN"┃"NOR WHT"〖 道行 〗%s%52-s    "NOR CYN"┃\n"NOR,HIM,chinese_daoxing(dao));    
		if (ob->query("degree"))
		{
		printf(NOR CYN"┃"NOR WHT"〖 官拜 〗%s%52-s                  "NOR CYN"┃\n"NOR,HIW,ob->query("degree"));
        printf(NOR CYN"┗━━━━━━━━━━━━━━"HIY"个"HIR"·"HIY"人"HIR"·"HIY"档"HIR"·"HIY"案"NOR CYN"━━━━━━━━━━━━┛\n"NOR);
		}
		else
		{
		printf(NOR CYN"┃"NOR WHT"〖 官拜 〗%s%52-s    "NOR CYN"┃\n"NOR,HIW,"未入仕途");
        printf(NOR CYN"┗━━━━━━━━━━━━━━━"HIY"M"HIR"·"HIY"H"HIR"·"HIY"X"HIR"·"HIY"Y"NOR CYN"━━━━━━━━━━━━━┛\n"NOR);

		}
        //printf(NOR WHT"  〖 官拜 〗 %s "NOR CYN"  \n"NOR,ob->query("degree"));

        printf("\n");   
        return 1;
}

string status_color(int current, int max)
{
        int percent;
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return CYN;
        if( percent >= 10 ) return HIR;
        return RED;
}


string chinese_daoxing(int gain) {
            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"年";
             if(day) str=str+chinese_number(day)+"天";
             if(hour) str=str+chinese_number(hour)+"时辰";
             if(gain==0) str="未入道途";
             return str;
}


int help(object me)
{
        write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}
 
