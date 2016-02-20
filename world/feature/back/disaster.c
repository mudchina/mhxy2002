// /feature/disaster.c
// 浩劫系统的主程序
// 请注意作者!是龙剑飞扬之纵横新世纪(202.103.98.74-5555)
// 【 天尊 】小黑马(xhm)和任天平(tianping)  
//By tianlin@mhxy for 2001.12.31修改
#include <ansi.h>

void copy_npc(int sum);
void set_status(object ob,int exp,int skill);
string query_site();
void verdict_end();
int query_children(string arg);
void verdict_time();
void set_hj_startT(int i);
int query_hj_startT();
void juedou();

string *factions=({"五庄观","大雪山","月宫","地府","东海龙宫","陷空山无底洞","蜀山派","盘丝洞"});
string faction;     //存放攻打的门派
int Cnpcend, count = 0;
int hj_startT = 0;
object lead;

//浩劫系统发生的主函数
void disaster(int sum)
{
	count = sum;
	LOGIN_D->set_dienpc(-1);
	set_hj_startT(time());
	faction = factions[count];
	message("channel:chat",HIR"【西天佛祖】如来佛(Rulai fo):"MAG"神秘组织的第"+chinese_number(count+1)+"个目标是血洗【"HIR+faction+MAG"】。\n"NOR,users());
	message("channel:chat",HIW"【"+HIM MUD_NAME+HIW"】由于大敌当前，从现在开始进入戒严状态！任何人不得临阵脱逃！\n"NOR,users());
	call_out("copy_npc",0,1);
}

//产生EXP and SKILL跟指定玩家相等的杀手(pker)
void copy_npc(int sum)
{
	object ob, *user;
	string site, domain;
	int i, j, exp, skill, lead_exp=0;
	int t=0;

	user = users();
	j = sizeof(user);
	Cnpcend = 0;
	for (i=0;i<j;i++) {
		if (faction!="长安城" && user[i]->query("family/family_name")!=faction) {
			t++;
			continue;
		}
		if (!user[i]) {t++;continue;}
		exp = (int) user[i]->query("combat_exp");
		skill = (int) user[i]->query_skill("parry",1);
		if (lead_exp < exp) {lead_exp = exp;lead = user[i];}
		if (skill < 1) skill = 5;
		if (exp < 10000)
			ob = new("/d/haojie/npc/pker1");
		else if (exp < 30000)
			ob = new("/d/haojie/npc/pker2");
		else if (exp < 50000)
			ob = new("/d/haojie/npc/pker3");
		else if (exp < 80000)
			ob = new("/d/haojie/npc/pker4");
		else if (exp < 150000)
			ob = new("/d/haojie/npc/pker5");
		else if (exp < 300000)
			ob = new("/d/haojie/npc/pker6");
		else if (exp < 500000)
			ob = new("/d/haojie/npc/pker7");
		else if (exp < 800000)
			ob = new("/d/haojie/npc/pker8");
		else
			ob = new("/d/haojie/npc/pker9");

		set_status(ob,exp,skill);
		site = query_site();
		domain = domain_file(site);
		ob->set("domain",domain);
		ob->move(site);
		message_vision("$N凶神恶煞的走了过来。\n",ob);
	}

	if (t>=j) {
		message("channel:chat",HIR"【天地劫】"MAG"由于"+faction+"门下空无一人，魔界不战而胜，一举拿下了"+faction+"。\n"NOR,users());
		message("channel:chat",HIW"【梦幻西游】魔界首领无天老祖大笑道：没想到如此轻易得手，真是天助我也，哈。哈。哈。下一个！\n"NOR,users());
		message("channel:chat",HIW"【"+HIM MUD_NAME+HIW"】敌人暂时撤退了，现在解除戒严状态！\n"NOR,users());
		LOGIN_D->set_madlock(0);
		call_out("disaster",10,count+1);
		return;
	}
	if (sum<3)
		call_out("copy_npc",20,++sum);
	else {
		Cnpcend = 1;
		call_out("verdict_time",1800);
	}
}

//根据player的EXP and SKILL设置pker的EXP and SKILL
void set_status(object ob,int exp,int skill)
{
	ob->set("combat_exp",exp);
	ob->set_skill("parry",skill);
}

//根据门派随机产生pker的落脚地点
string query_site()
{
	mapping sites=([
       "五庄观":                  ({"/d/qujing/wuzhuang/gate","/d/qujing/wuzhuang/guangchang","/d/qujing/wuzhuang/houyuan","/d/qujing/wuzhuang/baicaidi"}),
       "大雪山":                  ({"/d/xueshan/binggu","/d/xueshan/xuelu","/d/xueshan/wuchang-nw","/d/xueshan/xueshan5"}),
       "月宫":                    ({"/d/moon/ontop2","/d/moon/road1","/d/moon/wulang","/d/moon/huilang1"}),
       "地府":                    ({"/d/death/new-zhaopo","/d/death/new-sifang4","/d/death/pingyang","/d/death/room9"}),
       "东海龙宫":                ({"/d/sea/under4","/d/sea/boy2","/d/sea/inside3","/d/sea/huayuan6"}),
       "陷空山无底洞":            ({"/d/qujing/wudidong/shanlu2","/d/qujing/wudidong/dong1","/d/qujing/wudidong/cave1","/d/qujing/wudidong/mishi"}),
       "蜀山派":                  ({"/d/shushan/yongdao","/d/shushan/cangjingge","/d/shushan/xianjing","/d/shushan/zhenyaota/tower"}),
       "盘丝洞":                  ({"/d/pansi/pubu","/d/pansi/yandong","/d/pansi/fangjian1","/d/pansi/midao3","/d/pansi/fangjian3"}),
	]);

	return sites[faction][random(sizeof(sites[faction]))];
}

//判断浩劫是否被平息
void verdict_end()
{
	int sum = 0;

	if ( !Cnpcend ) return;
	sum += query_children("/d/haojie/npc/pker9.c");
	sum += query_children("/d/haojie/npc/pker8.c");
	sum += query_children("/d/haojie/npc/pker7.c");
	sum += query_children("/d/haojie/npc/pker6.c");
	sum += query_children("/d/haojie/npc/pker5.c");
	sum += query_children("/d/haojie/npc/pker4.c");
	sum += query_children("/d/haojie/npc/pker3.c");
	sum += query_children("/d/haojie/npc/pker2.c");
	sum += query_children("/d/haojie/npc/pker1.c");
	if (sum > 1) return;

	if (count+1 != sizeof(factions)) {
		message("channel:chat",HIR"【天地劫】"MAG+faction+"弟子在"+lead->name()+"的带领下，杀得敌人溃不成军，大败而逃！\n"NOR,users());
		message("channel:chat",HIW"【梦幻西游】魔界首领无天老祖：他奶奶的，点子手硬，闪先！\n"NOR,users());
		message("channel:chat",HIW"【"+HIM MUD_NAME+HIW"】暂时击退敌人，三界局势得到缓解，临时解除戒严状态！\n"NOR,users());
		call_out("disaster",20,count+1);
	}
	else {
		message("channel:chat",HIR"【天地劫】"MAG"各大门派接成联盟，在"+lead->name()+"的带领下，终于挫败了魔界的阴谋，三界又恢复了往日的平静。\n"NOR,users());
		message("channel:chat",HIW"【"+HIM MUD_NAME+HIW"】敌方大败，江湖恢复平静，解除戒严状态！\n"NOR,users());
		message("channel:chat",HIW"【梦幻西游】魔界首领无天老祖仰天狂叫：我不服！！我不服！！！我不服！！！！\n"NOR,users());
		call_out("juedou",5);
	}
	LOGIN_D->set_madlock(0);

}
void juedou()
{
	object ob;
	object *user;
	int i, exp, skill, killer = 0;

	user = users();
	for(i=0;i<sizeof(user);i++)
		if (user[i]->query_temp("hj_killer") > killer) lead = user[i];

	ob = new("/d/haojie/obj/zhanshu.c");
	ob->move(lead);
	message_vision(HIY"一张战书飘到了$N的面前。\n"NOR,lead);
	message("channel:chat",HIM"【天地劫】"+"听说"+lead->name()+HIM"得到了一张魔界首领无天老祖的挑战书。\n"NOR,users());

	exp = lead->query("combat_exp");
	skill = lead->query_skill("parry",1);
	ob = new("/d/haojie/npc/tianshaxing.c");
	ob->set("pk_target",lead);
	set_status(ob,exp,skill);
	ob->move("/d/city/center.c");
	message_vision("$N凶神恶煞的走了过来。\n",ob);
}

//取指定pker的人数
int query_children(string arg)
{
	object *ch;
	int i,sum = 0;

	ch = children(arg);
	for(i=0;i<sizeof(ch);i++)
		if(environment(ch[i])) sum++;
	return sum;
}

//定时判断浩劫发生的时间是否超过期限，超过则给予玩家惩罚
void verdict_time()
{
	object *user;
	int i, exp, parry, force;

//设置浩劫的期限为30分钟(1800秒)
	if( (time()-hj_startT) < 1800 ) {
		remove_call_out("verdict_time");
		call_out("verdict_time",60);
		return;
	}
	if (!LOGIN_D->get_madlock()) return;

	user = users();
	if (faction != "长安城")
		for(i=0;i<sizeof(user);i++) {
			if (user[i]->query("family/family_name") != faction) continue;
			if (!user[i]) continue;
//			exp = (int) user[i]->query("combat_exp") * 0.97;
			parry = (int) user[i]->query_skill("parry",1) * 0.99;
			force = (int) user[i]->query_skill("force",1) * 0.99;
//			if (exp > 1000) user[i]->set("combat_exp",exp);
			if (parry > 5) user[i]->set_skill("parry",parry);
			if (force > 5) user[i]->set_skill("force",force);
		}
	else	for(i=0;i<sizeof(user);i++) {
			if (!user[i]) continue;
			exp = (int) user[i]->query("combat_exp") * 0.97;
			parry = (int) user[i]->query("balance") * 0.75;
			if (exp > 1000) user[i]->set("combat_exp",exp);
			if (parry > 0) user[i]->set("balance",parry);
		}
	if (count+1 != sizeof(factions)) {
		message("channel:chat",HIR"【天地劫】"MAG+faction+"弟子力战之下，伤亡惨重，从此消声匿迹。\n"NOR,users());
		message("channel:chat",HIW"【梦幻西游】魔界首领无天老祖冷哼一声：下一个！\n"NOR,users());
		message("channel:chat",HIW"【"+HIM MUD_NAME+HIW"】敌人暂时撤退了，现在解除戒严状态！\n"NOR,users());
		call_out("disaster",10,count+1);
	}
	else {
		message("channel:chat",HIR"【天地劫】"MAG"虽然各派奋力杀敌，无奈悬殊太大，还是败下阵来，一时间腥风血雨，三界一片混暗。\n"NOR,users());
		message("channel:chat",HIW"【"+HIM MUD_NAME+HIW"】魔界首领大获全胜，三界一片黑暗，现在解除戒严状态！大家快逃命吧!\n"NOR,users());
	}
	LOGIN_D->set_madlock(0);

}

//设置和读取浩劫的开始时间
void set_hj_startT(int i)
{
	hj_startT = i;
}
int query_hj_startT()
{
	return hj_startT;
}
