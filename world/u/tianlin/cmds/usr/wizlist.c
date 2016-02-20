//By tianlin@Mhxy for 2002.3.10
//修改加入离线时间,和连线时间

#include <ansi.h>
inherit F_CLEAN_UP;
string *mission,*titlemission; 
string get_titlemission( string );
string fill_blank(string type, int num);
string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD });
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}
int level(mixed, mixed);
string get_mission( string );
string query_time(int time);
void create() { seteuid( getuid() ); }
int main(object me, string arg)
{
 //       int i;
        int i, inv=0;
        string *list, hood="", str, msg, scr, att, showtime;
        int bos_n, adm_n, arc_n, ang_n, wiz_n, app_n, gen_n, imm_n,eld_n, j, k, time, day, hour, min;
        object login,ob,body,exit;
        mission = explode(read_file("/adm/etc/renwu"), "\n");
        titlemission = explode(read_file("/adm/etc/job"), "\n");
       list = sort_array(SECURITY_D->query_wizlist(), (: level :));
        //得到各种级别巫师的个数。
        for(i=0; i<sizeof(list); i++) {
                switch (wizhood(list[i])) { 
                        case "(admin)"          :adm_n++;break;
                        case "(arch)"           :arc_n++;break;
                        case "(wizard)"         :wiz_n++;break;
                        case "(apprentice)"     :app_n++;break;
                        case "(immortal)"       :imm_n++;break;
                        case "(elder)"          :eld_n++;break;
                }
        }
        str=""HIW"〖"HIG"梦幻"HIW"西游〗"HIG"·总站管理员工作表\n"NOR;
        str+=""HIC"≡≡"HIB"══════════════════════════════════════════"HIC"≡≡\n"NOR;
        str +=WHT"    系统级别           ID            状   态              任务级别      工作动向\n"NOR;
        str+=""HIB"─────────────────────────────────────────────\n"NOR;
        for(i=0; i<sizeof(list); i++) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        switch (hood) { 
                                case "(admin)"          :msg =HIB"〖"HIW"底层制作"NOR+HIB"〗"NOR;k=adm_n;break;
                                case "(arch)"           :msg =HIB"〖"HIM"技术总监"NOR+HIB"〗"NOR;k=arc_n;break;
                                case "(wizard)"         :msg =HIB"〖"HIY"网页主管"NOR+HIB"〗"NOR;k=wiz_n;break;
                                case "(apprentice)"     :msg =HIB"〖"HIG"玩家主管"NOR+HIB"〗"NOR;k=app_n;break;
                                case "(immortal)"       :msg =HIB"〖"BLK"见习巫师"NOR+HIB"〗"NOR;k=imm_n;break;
                                case "(elder)"          :msg =HIB"〖"HIB"管理顾问"NOR+HIB"〗"NOR;k=imm_n;break;
                        }
                        j=1;
                } else {
                        msg="";
                        j++;
                }
                if ( k == 1) scr=WHT"━━━━"NOR;
                else scr=WHT"━━┳━"NOR;

                if ( k!=j && k!=1 && j!=1 ) scr=WHT"    ┣━"NOR;
                if ( k==j && k!=1 && j!=1 )     scr=WHT"    ┗━"NOR;
                   inv=0;
                   login = new(LOGIN_OB);
                   ob = new(LOGIN_OB);
                   exit = new(LOGIN_OB);
                   exit->set("id", list[i]);
                   exit->restore();
                   body = LOGIN_D->make_body(ob);
                   me=this_player();
                 if(objectp(login = find_player(list[i])) && !login->query("env/invisibility")){
                        att=sprintf(WHT"连线：%s", 
                                query_time(login->query_temp("temp_time")));
                        inv=1;
                } else {
                        att=sprintf("离线：%s", 
                        query_time(exit->query("last_on")));
                }
                
                time /= 60;
                min = time%60;
                time /= 60;
                hour = time%24;
                time /= 24;
                day = time;

//                showtime=sprintf("%s%s%s",day?sprintf("%d天",day):"",
//                                        hour?sprintf("%d小时",hour):"",
//                                        min?sprintf("%d分钟",min):"小于一分钟");
       //          showtime=sprintf(HIR"\n"NOR);
                if ( wizhood(list[i])!="(elder)" ) {
                        str += sprintf("%-12s%s "YEL"%-10s"NOR"%s  %s\t%s",msg, scr, list[i], att, get_mission( list[i] ), get_titlemission( list[i]));
                        str += fill_blank(remove_ansi(get_mission( list[i])), 15)+"\n";
                }
                if (wizardp(me) && wizhood(list[i])=="(elder)" ) {
                        str += sprintf("%-12s%s "YEL"%-10s"NOR"%s %s\t%s",msg, scr, list[i], att, get_mission( list[i] ), get_titlemission( list[i]));
                        str += fill_blank(remove_ansi(get_mission( list[i])), 15)+"\n";
                }
        }
        str+=""HIC"≡≡"HIB"═════════════════════════════════ "HIW"梦幻西游"HIB" ════"HIC"≡≡\n"NOR;
        str+=sprintf(""HIR"★"HIW" %s (青岛总站)"HIC" 现在共有%s位管理员。\n"NOR, MUD_NAME, chinese_number(sizeof(list)));
        me->start_more(str);
        return 1;
}
int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob2) - wiz_level(ob1);
        return ob1 < ob2?-1:1;
}
string get_mission( string wiz)
{
        int i;
        string wname,wmin;
        for(i=0; i<sizeof(mission); i++) {
                if( mission[i][0]=='#' || sscanf(mission[i], "%s %s",
                        wname, wmin)!=2 ) continue;
                if(wname==wiz) return wmin;
        }
        return "未知任务"NOR;
}
string get_titlemission( string wiz)
{
        int i;
        string wtname,wtmin;
        for(i=0; i<sizeof(titlemission); i++) {
                if( titlemission[i][0]=='#' || sscanf(titlemission[i], "%s %s",
                        wtname, wtmin)!=2 ) continue;
                if(wtname==wiz) return wtmin;
        }
        return NOR CYN"动向不明"NOR;
}  
string fill_blank(string type, int num)
{
        string bak;
        int i, j;
        bak="";
        i=strlen(type);
        for (j=0; j<num-i; j++ )
                bak+=" ";
        return bak;
}
string query_time(int time)
{
        string msg;
        int day, hour, min;
        
        time=time()-time;
        
        msg="";
        day=time/86400;
        hour=time%86400/3600;
        min=time/60%60;
        if(min<1)
                min=1;
        if(day)
                msg+=sprintf("%s天", chinese_number(day));
        if(day<10 && hour)
                msg+=sprintf("%s小时", chinese_number(hour));
        if(!day && hour<20 && min)
                msg+=sprintf("%s分钟", chinese_number(min));
        return msg;
}
int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单及巫师当前任务。

HELP
     );
     return 1;
}
