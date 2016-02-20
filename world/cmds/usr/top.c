//By tianlin@mhxy for 2002.1.12
//我今天突然想把显示改成20个player而不是以前的15个了,hehe
//sigh还是改回去了,hehe

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        
        object *list,*ob;
        int i;
        string msg;

      ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
        list = sort_array(ob, (: top_list :));
      msg =  "\n            　　　┏ "BLINK+HBBLU+HIW+CHINESE_MUD_NAME"在线高手排行榜"NOR" ┓\n";
      msg += "┏━━━━━┯━━━┻━━━━━━━━┯━━━┻━━━┯━━━━┯━━━━┓\n";
      msg += "┃  名次　  │      高        手      │　 门    派　 │ 评  价 │ 级  别 ┃\n";
      msg += "┠─────┴────────────┴───────┴────┴────┨\n";
    for (i = 0 ;i < 10 ; i++) {
if( i >= sizeof(list)) 
    msg += "┃暂时空缺。│　　　　        　　    │　　　　      │    　  │ 　     ┃\n";
        else {
            if( !list[i] ) continue;
            if( !list[i]->query("id") ) continue;
            if(list[i] == me) msg += BMAG HIW;
                  msg += sprintf("┃   "HIG"%-5s"NOR"  │"HIW"%-12s"NOR"  "HIY"%-10s"NOR"│"BMAG""HIC"%-14s"NOR"│"HIB"%8d"NOR"│"HIR"%8d"NOR"┃\n"NOR,chinese_number(i+1),list[i]->query("name"),"["+
        capitalize(list[i]->query("id"))+"]", list[i]->query("family")?  list[i]->query("family/family_name"):"普通百姓",
        get_score(list[i]),get_score(list[i])/100);
                }
                         }
        msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
      //  msg += "  " + NATURE_D->game_time() + "记。\n";
//修改成日常时间,以前的我自己都看不大明白,现在修改.hehe
	 msg += "  " + BJTIME_D->chinese_time(1,ctime(time())) + "记。\n";
        msg += "  你的综合评价是"HBBLU+HIG+get_score(me)+NOR"! \n"NOR;
        write(msg);
        return 1;

}

int top_list(object ob1, object ob2)
{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);

      return score2 - score1;
}

int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;

        reset_eval_cost();
        skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
        ski  = keys(skills);
        for(i = 0; i<sizeof(ski); i++) {
                        tlvl += skills[ski[i]];
                        }  // count total skill levels
        score = tlvl/(i+1);
        score += ob->query("max_force")/10;
        score += ob->query("max_mana")/10;
        score += ob->query("str") + ob->query("int") + ob->query("spi") + ob->query("con");
        score += (int)ob->query("combat_exp")/5000;
        score += (int)ob->query("daoxing")/5000;

        return score;
}

int help(object me)
{
write(@HELP
指令格式 : top 
 
这个指令可以让你知道在线十大高手是哪些，别去惹他们。 
 
HELP
    );
    return 1;
}
