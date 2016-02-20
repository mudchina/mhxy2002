#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me) {
        mapping info;
        float x, fraction;
        string str;

        info = rusage();
        x = info["utime"] + info["stime"];
        // time is in msec, convert to sec
        x = (info["utime"] + info["stime"])/1000;
        fraction = x / uptime();    
        str = sprintf("目前CPU使用率为："WHT"%2.2f%%", fraction * 100);
        write( str+"/100%。\n"NOR);
        return 1;
}

