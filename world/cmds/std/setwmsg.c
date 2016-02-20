//setwmsg.c
// SetWeaponMsg
//Creat by ZCooker 97.12.6

#include <ansi.h>

inherit F_CLEAN_UP;

string creat_info(string msg1,int flag);
//flag is a variable to say which should be returned
int help();

int main(object me, string info)
{
        string msg,command,msg1;
        object weapon;
        if( !info ) return help();
        if (strsrch(info, "$N") < 0)
                return notify_fail("描述里要有$N表示你自己！\n");
        if (strsrch(info, "$WEAPON$") < 0)
                return notify_fail("描述里要带$WEAPON$表示你的兵器！\n");
        if (strsrch(info, "【") > 0)
                return notify_fail("描述里出现了非法字符！\n");
        if (strsrch(info, "】") > 0)
                return notify_fail("描述里出现了非法字符！\n");
        if (strsrch(info, "仙子") > 0)
                return notify_fail("描述里出现了非法字符！\n");
        if (strsrch(info, "风儿") > 0)
                return notify_fail("描述里出现了非法字符！\n");
        if (strsrch(info, "巫师") > 0)
                return notify_fail("描述里出现了非法字符！\n");
        if (strsrch(info, "天神") > 0)
                return notify_fail("描述里出现了非法字符！\n");
        if (strsrch(info, "告诉") > 0)
                return notify_fail("描述里出现了非法字符！\n");
        if (strsrch(info, "回答") > 0)
                return notify_fail("描述里出现了非法字符！\n");
        if( !(me->query("weapon/make")))
                return notify_fail("你没有自制的兵器！\n");
        weapon = present( (me->query("weapon/id")), me );
        if( !objectp(weapon))
                return notify_fail("你的兵器不在身边！\n");
        sscanf(info ,"%s %s" ,command ,msg1);
        switch(command)
        {
                case "-w":
                        msg = creat_info(msg1,1);
                        me->set("weapon/wield_msg",msg);
                        weapon->set("wield_msg",msg+"\n");
                        break;
                case "-u":
                        msg = creat_info(msg1,1);
                        me->set("weapon/unwield_msg",msg);
                        weapon->set("unwield_msg",msg+"\n");
                        break;
                default :
                        return notify_fail("描述设置失败，请选择具体参数。详细请
看帮助文件。\n");
        }
        write("Ok.\n");
        return 1;
}

string creat_info(string msg1,int flag)
{
        string w_name,name;
        int w_lv,color;
        w_lv = this_player()->query("weapon/lv");
        w_name = this_player()->query("weapon/name");
        color = (w_lv/10);
        color = w_lv - color*10;
        switch(color){
                case 1:
                case 2:
                        name = HIR + w_name + NOR;
                        break;
                case 3:
                case 4:
                        name = HIG + w_name + NOR;
                        break;
                case 5:
                case 6:
                        name = HIY + w_name + NOR;
                        break;
                case 7:
                case 8:
                        name = HIB + w_name + NOR;
                        break;
                case 9:
                        name = HIM + w_name + NOR;
                        break;
                case 0:
                        name = HIC + w_name + NOR;
                        break;
        }
        if ( flag==2 )
                return name;
        msg1 = replace_string(msg1, "$WEAPON$",name);
        msg1 = replace_string(msg1, "$BLK$", BLK);
        msg1 = replace_string(msg1, "$RED$", RED);
        msg1 = replace_string(msg1, "$GRN$", GRN);
        msg1 = replace_string(msg1, "$YEL$", YEL);
        msg1 = replace_string(msg1, "$BLU$", BLU);
        msg1 = replace_string(msg1, "$MAG$", MAG);
        msg1 = replace_string(msg1, "$CYN$", CYN);
        msg1 = replace_string(msg1, "$WHT$", WHT);
        msg1 = replace_string(msg1, "$HIR$", HIR);
        msg1 = replace_string(msg1, "$HIG$", HIG);
        msg1 = replace_string(msg1, "$HIY$", HIY);
        msg1 = replace_string(msg1, "$HIB$", HIB);
        msg1 = replace_string(msg1, "$HIM$", HIM);
        msg1 = replace_string(msg1, "$HIC$", HIC);
        msg1 = replace_string(msg1, "$HIW$", HIW);
        msg1 = replace_string(msg1, "$NOR$", NOR);
        if ( flag==1)
                return msg1;

}

int help()
{
        string  f=RED+"★"+NOR;
        write(
"指令格式 : setwmsg -w|-u <具体描述>\n"
+"\n"
+f+"这个指令可以让你为自己的武器加入装备以及卸下时的描述\n"
+"    语言。\n"
+"    -w : 将后续文字作为兵器装备时的描述语言。\n"
+"    -u : 将后续文字作为卸下兵器时的描述语言。\n"
+"\n"
+f+"你如果希望在描述中使用 ANSI 的控制字元改变颜色，\n"
+"    可以用以下的控制字串：\n"
+"\n"
+"$BLK$ - 黑色    $NOR$ - 正常色   $RED$ - 红色    $HIR$ - 亮红色\n"
+"$GRN$ - 绿色    $HIG$ - 亮绿色   $YEL$ - 土黄色  $HIY$ - 黄色\n"
+"$BLU$ - 深蓝色  $HIB$ - 蓝色     $MAG$ - 浅紫色  $HIM$ - 粉红色\n"
+"$CYN$ - 蓝绿色  $HIC$ - 天青色   $WHT$ - 浅灰色  $HIW$ - 白色\n"
+"其中系统自动会在字串尾端加一个 $NOR$。\n"
+"\n"
+f+"在描写中使用$N代替自己；使用$WEAPON$代替兵器名称。\n"
+"\n"
+f+"注意如果在兵器名称后还有描写文字那么需要从新定义颜色\n"
+"    否则按默许颜色处理。\n"

        );
        return 1;
}
