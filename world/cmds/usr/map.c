// CMDS USR wherei.c
// Created by kittt@DJX2000
// Last Modified by kittt@DJX2000 5/20/2000
// 自动查询玩家位置，不需其他设定帮助。

#include <ansi.h>

inherit F_CLEAN_UP;

string get_area(string area);
string remove_ansi(string str) // 去掉颜色的函数，很有用
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BLINK });
                        
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}

int main(object me, string arg)      
{
        string file,here;
        object room;
        int i;

        room = environment(me);
        here = file_name(room);

        file = read_file("doc/help/maps/map-" + get_area(here)); //调用map文件
        if (!file || !stringp(file)) 
                return notify_fail("这里暂时没有地图。\n");
        // 颜色标记
        file = replace_string(file, remove_ansi(room->query("short")), HIY+room->query("short")+NOR);
      me->start_more(file);
 
        write(" ___________________________________________________________\n");
        write(CYN"\n你目前正处在"HIM+"/adm/daemons/questd"->query_city(room)+ HIW+remove_ansi(room->query("short"))+CYN"。\n"NOR);
        return 1;
}

// modified by happ

string get_area(string area)  // 由path找出map文件
{
        string* list=explode(area,"/");
        return list[sizeof(list)-2];        
}


int help(object me)
{
write(@HELP
指令格式 : map
 
这个指令可以让你知道你所处的环境
在地图中的位置。
 
HELP
    );
    return 1;
}
