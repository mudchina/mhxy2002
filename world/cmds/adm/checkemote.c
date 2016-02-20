// 谁与争锋 /cmds/adm/checkemote.c对emote.o进行减肥
// by llm 将七句减为三句，使用者请慎重，如有网际频道或想进行者勿用
//为防止出错，使用该命令前，请先将原来的emote.o进行备份
//只要第一次清理后，这个指令就可以不用了

inherit F_CLEAN_UP;

string *e;//一个全局的数组变量，取出所有emote的词

int do_soucha(int,int);

int main(object me, string arg)
{
    int j,k;

    if( !arg ||arg!="-S")
    	return notify_fail("你确定要精减emote格式吗？如果是请加上 -S参数！\n");

    e = EMOTE_D->query_all_emote();//取关键词，赋进变量e里面去了
    j = sizeof(e);//计算总共emote个数
    write("目前一共是 "+j+" 个emote，开始检查前40个......\n\n");
    k = 0;
    return do_soucha(k,j);
}

int do_soucha(int k,int j)
{
    int i,max;
    mapping emote;

    seteuid(getuid());

    if((j-k) > 40) max = (k+40);//每次最大减40个
   	else max = (j-k);

    for(i=k; i<max; i++)
    {
		emote = EMOTE_D->query_emote(e[i]);//取出这个词的内容       	
       	write(e[i]+"\n");//显示一下名字
       	if(emote["new"]) continue;
//因为new这个参数是本系统独有的，有了这个表示就是新写的，没必要减肥
       	if(emote["myself"]) emote["myself"]=0;
       	if(emote["myself_self"]) emote["myself_self"]=0;
       	if(emote["myself_target"]) emote["myself_target"]=0;
       	if(emote["target"]) emote["target"]=0;                //清除
       	if(!emote["updated"]) emote["updated"]="sys";
/*没有updated参数的就加一个，为什么要加，因为在这个emote系统里，updated本来是指emote的作者
主要是在玩家编辑时控制他们不能改、删别人的emote。因此，对于已有的emote应该加上一个玩家不可
能有的名字，而sys一般是大多数MUD里禁止玩家登录的ID，你也可以用你在logind.c里禁止玩家用的任
意ID。
*/
       	EMOTE_D->set_emote(e[i], emote);//存储
       	write("精简整理成功！\n");//报告一下
    }
    if(j > 40)
   	{
   		j -= 40;//总数减少了40个，直到全部查完
   		k += 40;//下一次起步将前进40个
		write("继续检查下40个emote吗？(y/n)");
        input_to("confirm",1,k,j);
	}
	else
    	write("\n所有emote数据检查减肥完毕。\n");
    return 1;
}

int confirm(string yn,int k,int j)
{
	if(!yn) return 1;
    if( yn[0]=='y' || yn[0]=='Y' )
    {
        write("继续检查......\n");
    	return do_soucha(k,j);//此时的j,k都变化了，再次执行
    }
    else
        write("停止检查！\n");
    return 1;
}

int help(object me)
{
write(@HELP
指令格式：checkemote -S

检查并精简emote.o文件，注意：需要整个emote系统支持。
HELP
    );
    return 1;
}