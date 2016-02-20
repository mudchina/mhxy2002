// by tianlin 2001.7.1

#include <ansi.h>
inherit F_CLEAN_UP;
mapping levels=([
        "(admin)"       :       "[1;37mÌì    Éñ[2;37;0m",
        "(arch)"        :       "[1;36m´ó Î× Ê¦[2;37;0m",
        "(wizard)"      :       "[1;33mÎ×    Ê¦[2;37;0m",
        "(apprentice)"  :       "[1;35m¼ûÏ°Î×Ê¦[2;37;0m",
        "(immortal)"    :       "[1;32m¿Í×ùÎ×Ê¦[2;37;0m",
        "(elder)"       :       "[31mÈÙÓþÍæ¼Ò[2;37;0m",
]);     
string query_time(int time);

void create() { seteuid( getuid() ); }

int main(object me, string arg)
{
        string *list;
        int i, inv=0;
        string msg, time_msg;
        object ob, body;
        msg=""HIW"¡¼"HIG"ÃÎ»Ã"HIW"Î÷ÓÎ¡½"HIG"¡¤×ÜÕ¾¹ÜÀíÔ±¹¤×÷±í\n"NOR;
        msg+=""HIC"¡Ô¡Ô"HIB"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"HIC"¡Ô¡Ô\n"NOR;
        msg+=""CYN"         ÖÐÎÄÃû        Ó¢ÎÄ<id>   È¨ÏÞµÈ¼¶          ×´Ì¬          ¹¤×÷¶¯ÏòËµÃ÷    \n"NOR;
        msg+=""HIB"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR;


        list = sort_array(SECURITY_D->query_wizlist(), 1);

        for(i=0;i<sizeof(list);i++)
        {
                inv=0;
                ob=new(LOGIN_OB);
                ob->set("id", list[i]);
                ob->restore();
                if(objectp(body=find_player(list[i])) && !body->query("env/invisibility"))
                {
                        time_msg=sprintf(" Á¬Ïß£º%s", 
                                query_time(body->query_temp("temp_time")));
                        inv=1;
                }
                else time_msg=sprintf(" ÀëÏß£º%s", 
                        query_time(ob->query("last_on")));
                msg+=sprintf("\t  %-13s%-9s  %s%s%-26s%s%s\n", ob->query("name"), list[i],
                        levels[SECURITY_D->get_status(list[i])], 
                        inv?HBRED+HIY:NOR, time_msg, NOR,
                        ob->query("duty")?ob->query("duty"):"©¤©¤©¤©¤©¤©¤"); 
                destruct(ob);
        }
        msg+=""HIC"¡Ô¡Ô"HIB"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥ "HIW"ÃÎ»ÃÎ÷ÓÎ"HIB" ©¥©¥©¥©¥"HIC"¡Ô¡Ô\n"NOR;
        msg+=sprintf(""HIR"¡ï"HIW" %s (Çàµº×ÜÕ¾)"HIC" ÏÖÔÚ¹²ÓÐ%sÎ»¹ÜÀíÔ±¡£\n"NOR, MUD_NAME, chinese_number(sizeof(list)));
        write(msg);
        return 1;
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
                msg+=sprintf("%sÌì", chinese_number(day));
        if(day<10 && hour)
                msg+=sprintf("%sÐ¡Ê±", chinese_number(hour));
        if(!day && hour<20 && min)
                msg+=sprintf("%s·ÖÖÓ", chinese_number(min));
        return msg;
}

int help(object me)
{
write(@HELP
Ö¸Áî¸ñÊ½ : wlist

ÓÃÍ¾ : ÁÐ³öÄ¿Ç°ËùÓÐµÄÎ×Ê¦Ãûµ¥(º¬¿Í×ùÎ×Ê¦)¡£
HELP
     );
     return 1;
}

