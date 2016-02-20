//Cracked by Roath

// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string *gift_ranking = ({"下下之选","下等", "中下", "中等", "中上", "上等", "上上之选"});

string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string ="□□□□□□□□□□□□□□□□□□□□□□□□□";

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points,year,obstacles;
	int i;

	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) 
	{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} 
	else
		return notify_fail("只有巫师能察看别人的状态。\n");

	my = ob->query_entire_dbase();

	line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );

	if( ob->query("fake_age"))
	{
		line += sprintf(" 你是一%s%s岁的%s%s，%s生。\n\n",
		ob->query("unit"),
		chinese_number(ob->query("age")), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
	}
	else
	{
		line += sprintf(" 你是一%s%s岁的%s%s，%s生。\n\n",
		ob->query("unit"),
		chinese_number(ob->query("age")),
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
	}

        if( wizardp(me) )
        {
		line += sprintf(
			" 定力：[%s]  容貌：[%s]  胆识：[%s]  福缘：[%s]\n"
			" 体格：[%s]  根骨：[%s]  悟性：[%s]  灵性：[%s]\n\n",
		display_attr(my["cps"], ob->query_cps()),
		display_attr(my["per"], ob->query_per()),
		display_attr(my["cor"], ob->query_cor()),
		display_attr(my["kar"], ob->query_kar()),
		display_attr(my["str"], ob->query_str()),
		display_attr(my["con"], ob->query_con()),
		display_attr(my["int"], ob->query_int()),
		display_attr(my["spi"], ob->query_spi()));
        }
	else if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
                        >= RANK_D->grade_dx(BLU "初领妙道" NOR) ) 
	{
		line += sprintf(
			" 体格：[%s]  根骨：[%s]  悟性：[%s]  灵性：[%s]\n\n",
		display_attr(my["str"], ob->query_str()),
		display_attr(my["con"], ob->query_con()),
		display_attr(my["int"], ob->query_int()),
		display_attr(my["spi"], ob->query_spi()));
	}

	if( mapp(my["family"]) ) 
	{
		if( my["family"]["master_name"] )
			line = sprintf("%s 你的师父是%s。\n", line, my["family"]["master_name"] );
	}

	if (ob->query("married")) 
	{
		if (ob->query("gender")=="女性") 
		{
			line += " 你的丈夫是" + ob->query("couple/name")+"。\n\n";
		}
		else 
		{
			line += " 你的妻子是" + ob->query("couple/name")+"。\n\n";
		}
	}
	else 
	{
		if (ob->query("gender")=="女性")
			line += " 你目前待字闺中。\n\n";
		else line+=" 你目前是光棍儿一条。\n\n";
	}


	line += " <气血>  " + tribar_graph(my["kee"], my["eff_kee"],
my["max_kee"], HIR) + "\n";
	line += " <精神>  " + tribar_graph(my["sen"], my["eff_sen"],
my["max_sen"], HIB) + "\n\n";

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	if(wizardp(this_player())) 
	line += sprintf(" 战斗攻击力 " HIW "%d (+%d)" NOR "\t\t战斗防御力 " HIW "%d (+%d)\n\n" NOR,
	attack_points/100 + 1, ob->query_temp("apply/damage"),
		(dodge_points + (weapon? parry_points: 
		(parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));

	line += " <食物>  " + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
	line += " <饮水>  " + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n\n";

	obstacles = ob->query("qujing/number");
	if(obstacles)
		line += sprintf(" 你西行求取真经已过了"RED"%s关"NOR"。\n", chinese_number(obstacles));
	line += sprintf(" 你到目前为止总共杀了 %d 个人，其中有 %d 个是其他玩家。\n\n", 
		my["MKS"] + my["PKS"], my["PKS"]);
        
	if(ob->query("kill/pkgain") ) 
	{ 
		line +=sprintf(" ＰＫ道行增加： %s  \n", COMBAT_D->chinese_daoxing(ob->query("kill/pkgain")));
		if(!ob->query("kill/pklose") && !ob->query("kill/nkgain") ) line+="\n";
	}
	/*
	if(ob->query("kill/pklose") ) 
	{
		line +=sprintf(" ＰＫ道行减少： %s\n", COMBAT_D->chinese_daoxing(ob->query("kill/pklose")));
		if(!ob->query("kill/nkgain") ) line+="\n";
	}
	*/
	if(ob->query("kill/nkgain") ) 
	{
		line +=sprintf(" ＮＫ道行增加： %s\n\n", COMBAT_D->chinese_daoxing(ob->query("kill/nkgain")));
	}

	line += sprintf(" 道行境界：%s", RANK_D->describe_dx(ob->query("daoxing")) );
//	line += sprintf("\t\t武学境界：%s\n", RANK_D->describe_exp(ob->query("combat_exp")) );
	line += sprintf("　　　　　　　武学境界：%s\n", 
		RANK_D->describe_exp(ob->query("combat_exp")) );
	line += sprintf(" 法力修为：%s", RANK_D->describe_fali(ob->query("max_mana")) );
//	line += sprintf("\t\t内力修为：%s\n", RANK_D->describe_neili(ob->query("max_force")) );
	line += sprintf("　　　　　　　内力修为：%s\n", 
		RANK_D->describe_neili(ob->query("max_force")) );

	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;

        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*25/max)*2-1]
                + ((eff > val) ?
blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}

int help(object me)
{
        write(@HELP
指令格式 : score
           score <对象名称>                   (巫师专用)

这个指令可以显示你或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。

see also : hp
HELP
    );
    return 1;
}

