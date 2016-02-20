//By tianlin@mhxy for 2002.1.21,加入passwd双层保护

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( me != this_player(1) ) return 0;

	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

	write(HIC"为了安全起见，请先输入您的"HIW"身份标志"NOR+HIC"："NOR);
	input_to("check_superpasswd",  1, me, 1);
	return 1;
}
private void check_superpasswd(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("superpasswd");
	if( crypt(passwd, old_pass)!=old_pass ) {
              write(HIG"\n身份标识错误！\n"NOR);
              return;
       }
       write(HIR"\n\n为了安全期间请再输入您的密码：\n\n"NOR);
       write("请输入您的密码：");
       input_to("get_old_pass", 1, link_ob );
}
private void get_old_pass(string pass, object ob)
{
	string old_pass;

	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write(HIG"密码错误！\n"NOR);
		return;
	}
	write(HIY"请输入新的密码："NOR);
	input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
	write(HIY"\n请再输入一次新的密码："NOR);
	input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
	write("\n");
	if( crypt(pass, new_pass)!=new_pass ) {
		write("对不起，您输入的密码并不相同，继续使用原来的密码。\n");
		return;
	}
	seteuid(getuid());
	if( !ob->set("password", new_pass) ) {
		write("密码变更失败！\n");
		return;
	}

	ob->save();
	write("密码变更成功。\n");
}

int help(object me)
{
	write(@HELP
指令格式 : passwd
 
这个指令可以修改你的人物密码。
 
HELP
    );
    return 1;
}
 
