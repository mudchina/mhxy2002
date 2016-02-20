//Cracked by Njyjf
// superpasswd.c
#include <ansi.h>
#include <command.h>
#include <login.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
int check_legal_superpasswd(object ob,string arg);
private void get_new_superpasswd(string superpasswd, object ob);
private void get_old_superpasswd(string superpasswd, object ob);
int main(object me, string arg)
{
        object ob;

        if( me != this_player(1) ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;
        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

        write("为了安全起见，请先输入您的身份标识：");
        input_to("get_old_superpasswd", 1, ob);
        return 1;
}
int check_legal_superpasswd(object ob,string superpasswd)
{
        int i;
        int bigletter=0;
        int smlletter=0;
        int number=0;
        string id;
        i = strlen(superpasswd);
        if( strlen(superpasswd) <= 5)   {
                write(WHT"对不起，你的身份标识必须最少"BLINK HIY"六"WHT"个字符。\n"NOR);
                return 0;
        }
        while(i--) {
                if( superpasswd[i]<='Z' && superpasswd[i] >='A' ) bigletter++;
                if( superpasswd[i]<='z' && superpasswd[i] >='a' ) smlletter++;
        }
        if( bigletter == 0 || smlletter == 0 || bigletter+smlletter == strlen(superpasswd)){
        write(WHT"您的身份标识必需包含"HIY"大写" NOR HIR"和" + HIY"小写英文字母" NOR HIR"和" + WHT"其它"HIY"特殊符号（数字，标点）"NOR WHT"。\n"NOR);
                return 0;
        }
        return 1;
}
private void get_old_superpasswd(string superpasswd, object ob)
{
       string old_superpasswd;
       write("\n");
       old_superpasswd = ob->query("superpasswd");
       if( crypt(superpasswd, old_superpasswd)!=old_superpasswd ) {
              write("身份标识错误！\n");
              return;
       }
       write("请输入新的身份标识：");
       input_to("get_new_superpasswd", 1, ob );
}
private void get_new_superpasswd(string superpasswd, object ob)
{
        if( !check_legal_superpasswd(ob,superpasswd)) {
                write("请设定您的身份标识"HIM"[ "HIC"SuperPassWord"HIM" ]"NOR"：");
                input_to("get_new_superpasswd", 1, ob);
                return;
        }
        write("\n请再输入一次新的身份标识：");
        input_to("confirm_new_superpasswd", 1, ob, crypt(superpasswd,0));
}
private void confirm_new_superpasswd(string superpasswd, object ob, string new_superpasswd)
{
        write("\n");
        if( crypt(superpasswd, new_superpasswd)!=new_superpasswd ) {
                write("对不起，您输入的身份标识并不相同，继续使用原来的身份标识。\n");
                return;
        }
        seteuid(getuid());
        if( !ob->set("superpasswd", new_superpasswd) ) {
                write("身份标识变更失败！\n");
                return;
        }

        ob->save();
        write("身份标识变更成功。\n");
}

int help(object me)
{
        write(@HELP
指令格式 : superpasswd
 
这个指令可以修改你的身份标识。
 
HELP
    );
    return 1;
}