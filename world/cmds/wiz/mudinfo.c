#include <ansi.h>
inherit F_CLEAN_UP;

#define SCALE   (1.0/10.0)
#define STATUS  "系统函数库改写中"

string memory_expression(int m);

int count_ppls();

void create() { seteuid(getuid(this_object())); }

int main() {
        float value;
        mapping r;

        r = rusage();
        value = SCALE * (r["utime"] + r["stime"]) / uptime();

//        write("        .__________ 系 统 资 讯 __________.\n");
        write(HIW"──────────────────────────\n");
        write(" Mud 的识别名称：  " + MUD_NAME + ".\n");
        write(" 界面系统的版本：  " + __VERSION__ + "\n");
        write(" 系统函数库版本：  X.X.Z.J Mudlib Ver 2.0\n");
        printf(" CPU 使用百分比：  %f %% 被这个 Mud 使用中.\n", value );
        write(" CPU 的负担状况：  " + query_load_average() + ".\n");
        printf(" 共使用的记忆体：  %s bytes.\n", memory_expression(memory_info()) );
        write(" 线上使用者总数：  " + sizeof( users() ) + "  个人在线上.\n");
        write(" 注册使用者总数：  " + count_ppls() + "  个人在在本 Mud 注册.\n");
        write(" 载入的物件总数：  " + sizeof( objects() ) + " 个物件.\n");
        write(" 连续执行的时间：  " + CHINESE_D->chinese_period(uptime()) + "\n");
        write("──────────────────────────\n"NOR);        
//        write(" Mud 现在的状态：  " + STATUS + ".\n");
        return 1;
}

string memory_expression(int m)
{
        float mem;

        mem = m;
        if( mem<1024 ) return m + "";
        if( mem<1024*1024 )

                return sprintf("%.2f K", (float)mem / 1024);
        return sprintf("%.3f M", (float)mem / (1024*1024));
}

int count_ppls()
{
        int count,i;
        string *dir, *ppls;

        seteuid(getuid());

        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        count += sizeof(ppls);
        }
        return count;
}

int help() {

   write(@HELP
指令格式：mudinfo

这个指令将会显示有关这个 Mud 的一些系统资讯。

HELP
        );
         return 1;
}

