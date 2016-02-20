// 请注意作者!是龙剑飞扬之纵横新世纪(202.103.98.74-5555)
// 【 天尊 】小黑马(xhm)和任天平(tianping)  
// blockade.c

#include <login.h>
//#include <obj.h.es2>

inherit F_CLEAN_UP;
string time_period(int timep);

int main(object me, string arg)
{
        int i, j, tim, sum=0;

        i = LOGIN_D->get_dienpc();
        j = LOGIN_D->get_madlock();
	tim = F_DISASTER->query_hj_startT();
	tim = time() - tim;
	sum += F_DISASTER->query_children("/d/haojie/npc/pker9.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker8.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker7.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker6.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker5.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker4.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker3.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker2.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker1.c");
	write(" 被杀NPC人数："+i+"\n");
	write("系统封锁状态："+j+"\n");
	write("封锁持续时间："+time_period(tim)+"\n");
	write("当前杀手数量："+sum+"\n");
        return 1;
}

string time_period(int timep)
{
	int t, d, h, m, s;
	string time;
	if ( timep>=1800 ) return "已超时";
	t = timep;
	s = t % 60;	t /= 60;
	m = t % 60;	t /= 60;
	h = t % 24;	t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	return time;
}
