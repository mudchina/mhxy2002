// chaxun.c
// Modified by snowman@SJ 16/03/2000

/* 闲来无聊，写了个查询武功的命令。个人比较喜欢有框架的图形，各位多包涵。
   PS: 在没有优化过 ansi 显示的OS里，带颜色的框架会乱序排列，去掉code里的个ansi color就行了。
   
        用 chaxun xxx.yyy 是 call yyy 文件里的 int help(object me)，可以按照其它
        command 的help()来写。
   本想再加点其它功能的，但觉得过于花哨了反而不好，就这样吧。
   附太极拳的help()以做参考：

int help(object me)
{
        write(WHT"\n太极拳："NOR"\n");
        write(@HELP
        太极拳，为宋末元初武当张三丰真人所创，合道家之说，冲虚自然，主以慢
        打快，以静制动，後发制人，无为至虚之念的上乘武学。拳出时双手圆转，
        每一招都含着太极式的阴阳变化，精微奥妙，实是开辟了武学中从所未有的
        新天地。诀窍为「虚灵顶劲、涵胸拔背、松腰垂臀、沉肩坠肘」十六个字，
        纯以意行，最忌用力。形神合一，是这路拳法的要旨。
        太极拳劲首要在似松非松，将展未展，劲断意不断，其接力打力为武林一绝。
        
        要求：  氤氲紫气等级 100 以上；
                内力 500 以上；      
                有张三丰亲传拳招。
HELP
        );
        return 1;
}

*/

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "不堪一击" NOR,BLU "毫不足虑" NOR,BLU "不足挂齿" NOR,BLU "初学乍练" NOR,BLU "勉勉强强" NOR,
        HIB "初窥门径" NOR,HIB "初出茅庐" NOR,HIB "略知一二" NOR,HIB "普普通通" NOR,HIB "平平淡淡" NOR,
        CYN "平淡无奇" NOR,CYN "粗通皮毛" NOR,CYN "半生不熟" NOR,CYN "马马虎虎" NOR,CYN "略有小成" NOR,
        HIC "已有小成" NOR,HIC "鹤立鸡群" NOR,HIC "驾轻就熟" NOR,HIC "青出于蓝" NOR,HIC "融会贯通" NOR,
        GRN "心领神会" NOR,GRN "炉火纯青" NOR,GRN "了然于胸" NOR,GRN "略有大成" NOR,GRN "已有大成" NOR,
        YEL "豁然贯通" NOR,YEL "出类拔萃" NOR,YEL "无可匹敌" NOR,YEL "技冠群雄" NOR,YEL "神乎其技" NOR,
        HIY "出神入化" NOR,HIY "非同凡响" NOR,HIY "傲视群雄" NOR,HIY "登峰造极" NOR,HIY "无与伦比" NOR,
        RED "所向披靡" NOR,RED "一代宗师" NOR,RED "精深奥妙" NOR,RED "神功盖世" NOR,RED "举世无双" NOR,

        WHT "惊世骇俗" NOR,WHT "撼天动地" NOR,WHT "震古铄今" NOR,WHT "超凡入圣" NOR,WHT "威镇寰宇" NOR,


        HIW "空前绝后" NOR,HIW "天人合一" NOR,MAG "深藏不露" NOR,HIM "深不可测" NOR,HIR "返璞归真" NOR
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,BLU "初窥门径" NOR,HIB "略知一二" NOR,HIB "半生不熟" NOR,
        CYN "马马虎虎" NOR,CYN "已有小成" NOR,HIC "融会贯通" NOR,HIC "心领神会" NOR,
        GRN "了然於胸" NOR,GRN "已有大成" NOR,YEL "非同凡响" NOR,YEL "举世无双" NOR,
        HIY "震古铄今" NOR,RED "无与伦比" NOR,WHT "超凡入圣" NOR,HIW "空前绝后" NOR,
});


mapping valid_type = ([
"unarmed":      "拳脚",
"claw":         "爪功","cuff":         "拳功",
"hand":         "手功","leg":          "腿功",
"sword":        "剑法","blade":        "刀法",  
"dagger":       "匕法","brush":        "笔法",          
"spear":        "枪法","hook":         "钩法",          
"stick":        "棒法","staff":        "杖法",          
"club" :        "棍法","throwing":     "暗器",          
"whip":         "鞭法","axe":          "斧法",
"hammer":       "锤法","force":        "内功",  
"dodge":        "轻功","parry":        "招架", 
]);

string skill_level(string, int);
string skill_enables(object sk);

int sort_skill(string file)
{
        int i;
        if ( !sscanf(file, "%*s.c") )  return 0;
        i = strlen(file);
        while(i--){
                if( file[i] == '.' ) continue;
                if( file[i] < 'a' || file[i] > 'z' )
                        return 0;
        }

        return 1;
}

int main(object me, string arg)
{
        mapping lrn;


        string exert, str, *file;
        object sk;
        int i, j = 0;

        seteuid(getuid());

        if(!arg) return notify_fail("指令格式 : chaxun [武功名称].[?|特殊技能]\n");
        
        sscanf(arg, "%s.%s", arg, str);
                
        if(!me->query_skill(arg, 1)) 
                return notify_fail("你要查对什么技能？\n");
        
        if(file_size(SKILL_D(arg)+".c") < 1)
                return notify_fail("错误！你要查对技能文件已经消失，请通知巫师。\n");
        
        if( stringp(str) ){
                // 格式 chaxun xxx.? 是查询此skill的帮助。
                // chaxun xxx.yyy 是查询 yyy 的帮助。
                if( str == "?" ){
                        return SKILL_D(arg)->help(me);
                }
                else if( stringp(exert = SKILL_D(arg)->exert_function_file("")) && file_size(exert + str +".c") > 0){
                        notify_fail("对不起，"+to_chinese(arg)+"内功方面的「"+str+"」功能没有详细的说明。\n");
                        return (exert + str)->help(me);
                }
                else if( stringp(exert = SKILL_D(arg)->perform_action_file("")) && file_size(exert + str +".c") > 0){
                        notify_fail("对不起，"+to_chinese(arg)+"外功方面的「"+str+"」功能没有详细的说明。\n");
                        return (exert + str)->help(me);
                }
                return notify_fail("对不起，"+to_chinese(arg)+"没有「"+str+"」这项功能。\n");
        }
        
        lrn = me->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        str = sprintf("\n┌%-24s─────────────────────┐\n", HIW"【"+to_chinese(arg)+"功能表】"NOR);
        
        str = replace_string(str, "  ", "─");
        str += sprintf("│"HIY"等级"NOR"：  %s %3d/%6d\t      "HIY"类别"NOR"：  %-15s%9s  \n",skill_level(SKILL_D(arg)->type(), 
                        me->query_skill(arg, 1)), me->query_skill(arg, 1), 
                        (int)lrn[arg], SKILL_D(arg)->type(), "│");     


        
        if(SKILL_D(arg)->type() != "martial"
        || member_array(arg, keys(valid_type))!=-1) 
         return notify_fail(str+"└─────────────────────────────────┘\n");
                
        str += "│\t\t\t\t\t\t\t\t    │\n";
        sk = load_object(SKILL_D(arg));
        
        exert = skill_enables(sk);
        if(exert != ""){
                str += exert;
                i++;
        }
        
        if( stringp(exert = SKILL_D(arg)->exert_function_file("")) ){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        
        if(j && j > 0){
                        str = str + "├─────────────────────────────────┤\n";
                str += "│"HIY"内功方面(exert + )"NOR"：\t\t\t\t\t\t    ";
        for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "│\n│\t";
                        str += sprintf("%-14s ",YEL+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +="\t\t\t\t\t            "; break;
                                        case 1: str +="\t\t\t            "; break;
                                        case 2: str +="\t\t    "; break;
                                        default: break;
                                }
                        }
                }
                str += "│\n";
                j = 0;
        }
        
        if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        if(j && j > 0){
                if( i )
                        str = str + "├─────────────────────────────────┤\n";
                str += "│"HIY"外功方面(perform + )"NOR"：\t\t\t\t\t    ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "│\n│\t";
                        str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +="\t\t\t\t\t            "; break;
                                        case 1: str +="\t\t\t            "; break;
                                        case 2: str +="\t\t    "; break;
                                        default: break;
                                }
                        }
                }
                str += "│\n";
        }
        str += "└─────────────────────────────────┘\n";
        write(str);
        return 1;
}





string skill_enables(object sk)
{
        int i, j;
        string str, *skills;
        skills = keys(valid_type);
        
        for(i=0; i < sizeof(skills); i++) {
                if (sk->valid_enable(skills[i])) continue;
                skills[i] = 0;
        }
        
        skills -= ({ 0 });
        j = sizeof(skills);
        if( !j || j < 1)
                return "";
        str = "│"HIY"特殊技能"NOR"：\t\t\t\t\t\t\t    ";
                
        for(i=0; i < j; i++) {
                if (i % 4 == 0) str += "│\n│\t";
                str += sprintf("%-14s ", HIC+valid_type[skills[i]]+"("+skills[i]+")"NOR);
                if ( i > j-2 ){
                        switch(i%4){
                                case 0: str +="\t\t\t\t\t            "; break;
                                case 1: str +="\t\t\t            "; break;
                                case 2: str +="\t\t    "; break;
                                default: break;
                        }
                }
        }
        str += "│\n";
        return str;
}

string skill_level(string type, int level)
{
        int grade;
        
        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        grade = level / 8;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write("\n指令格式 : chaxun [武功名称].[绝招名称 | ?]\n");
        write(@HELP
这个指令可以让你查询此项技能的功能和数据。

特殊技能表示可以 enable 的技能，如：
        (轻功、招架、棍法、杖法) 表示：此武功可以用作轻功，招架，棍法，杖法等。

内功方面显示可运用(exert)的内功。

外功方面显示可使用(perform)的外功，绝招等。

如果内功或外功的绝招有帮助介绍，可用 chaxun skill.pfm 的形式来查看。
如：    chaxun taiji-quan.dongjing  查看动静决
        chaxun yinyun-ziqi.yinyun   查看氤氲内聚
        chaxun taiji-quan.?         查看太极拳

Snowman@SJ 06/04/1999
Copyright 1997-2000 ShuJian MUD Wizard Group.
All rights reserved.
        
Visit our Homepage at - www.mymud.com 
        
HELP);

    return 1;
}
