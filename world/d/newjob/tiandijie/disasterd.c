// 浩劫系统的主程序
// 请注意作者!是龙剑飞扬之纵横新世纪(202.103.98.74-5555)
// 【 天尊 】小黑马(xhm)和任天平(tianping)  

#include <ansi.h>
inherit F_DBASE;
void copy_npc(int count);
string query_site();
void verdict_time(int t,int count);
void juedou();

string *factions=({"火云洞","蜀山剑派","五庄观","大雪山","南海普陀山","月宫","阎罗地府","东海龙宫","陷空山无底洞","花果山盘丝洞","方寸山三星洞","将军府",});
string faction;     //存放攻打的门派
int Cnpcend, count;
object lead;
void create()
{
    seteuid(getuid());
    set("name", "天地劫");
    set("id", "disaster");
  remove_call_out("disaster");
  call_out("disaster",30,0);   
}

//浩劫系统发生的主函数
void disaster(int count)
{
        if(count==0){
        message("system",HIR"【天地劫】"HIW"太白金星：凡间的欲念太重了，致使心魔重生！\n"NOR,users());
        message("system", HIR"【天地劫】"HIW"太白金星：看来天地间一场浩劫在所难免！\n"NOR,users());
        }       
        faction = factions[count];
        message("system",HIR"【天地劫】"HIW"魔教的第"+chinese_number(count+1)+"个目标是血洗【"HIR+faction+HIW"】。\n"NOR,users());
//      message("system", HIR"【天地劫】"HIW"由于大敌当前，从现在开始进入戒严状态！任何人不得临阵脱逃！\n"NOR,users());
        call_out("copy_npc",11,count);
//      copy_npc();
}

//产生EXP and SKILL跟指定玩家相等的杀手(pker)
void copy_npc(int count)
{
        object ob, *user;
        string site,leader;
        int i, j, exp, skill;
        int t=0;
        user = users();
        j = sizeof(user);
        Cnpcend = 0;
        for (i=0;i<j;i++) {
                if (user[i]->query("family/family_name")!=faction
                ||user[i]->query("combat_exp")<30000||wizardp(user[i]))
                        continue;
                  if (!user[i]||wizardp(user[i])) continue;
               switch(faction){
                case "南海普陀山":
                      ob = new("/d/newjob/tiandijie/npc/yg-putuo");
                      leader="观音菩萨";
                      break;
                case "五庄观":
                      ob = new("/d/newjob/tiandijie/npc/yg-wzg");
                      leader="镇元大仙";
                      break;
                case "大雪山":
                      ob = new("/d/newjob/tiandijie/npc/yg-xueshan");
                      leader="大鹏明王";
                      break;
                case "阎罗地府":
                      ob = new("/d/newjob/tiandijie/npc/yg-hell");
                      leader="地藏王菩萨";
                      break;
                case "东海龙宫":
                      ob = new("/d/newjob/tiandijie/npc/yg-dragon");
                      leader="东海龙王";
                      break;
                case "陷空山无底洞":
                      ob = new("/d/newjob/tiandijie/npc/yg-wudidong");
                      leader="玉鼠精";
                      break;
                case "蜀山剑派":
                      ob = new("/d/newjob/tiandijie/npc/yg-shushan");
                      leader="蜀山剑圣";
                      break;
                case "花果山盘丝洞":
                      ob = new("/d/newjob/tiandijie/npc/yg-pansi");
                      leader="紫霞仙子";
                      break;
                case "方寸山三星洞":
                      ob = new("/d/newjob/tiandijie/npc/yg-fangcun");
                      leader="菩提祖师";
                      break;
                case "火云洞":
                      ob = new("/d/newjob/tiandijie/npc/yg-hyd");
                      leader="红孩儿";
                      break;
                case "将军府":
                      ob = new("/d/newjob/tiandijie/npc/yg-jjf");
                      leader="秦琼";
                      break;
                case "月宫":
                      ob = new("/d/newjob/tiandijie/npc/yg-moon");
                      leader="嫦娥仙子";
                      break;
/*                case "三界山":      
                       ob = new("/d/newjob/tiandijie/npc/yg-sanjie");
                       leader="纯阳天师";
                       break;      */
                      }
                site = query_site();
//                  ob->set("title",HIR"心魔小头目"NOR);
                ob->copy_status(ob,user[i]);
                ob->move(site);
                tell_object(user[i], HIY""+leader+"告诉你:魔教挑衅本门,速回本门助战！\n");
                message_vision("$N凶神恶煞的走了过来。\n",ob);
                t++;
        }

        if (t==0) {
                if (count < 12) {
                        message("system", HIR"【天地劫】"HIW"由于"+faction+"门下空无一人，魔教不战而胜，一举拿下了"+faction+"。\n"NOR,users());
                        message("system", HIR"【天地劫】"HIW"魔教教主心魔老祖大笑道：没想到如此轻易得手，真是天助我也，哈。哈。哈。下一个！\n"NOR,users());
                        call_out("disaster",11,count+1);
                }
                else {
                message("system", HIR"【天地劫】"HIW"虽然各派奋力杀敌，击退魔教，无奈损失太大，一时间腥风血雨，三界一片混暗。\n"NOR,users());
                message("system", HIR"【天地劫】"HIW"太白金星：魔教虽然暂时退了，但不知什么时候又会卷土重来!\n"NOR,users());
                        call_out("disaster",3600,0);
                   call_out("juedou",5);
                }
        }
        else {
                Cnpcend = 1;
                call_out("verdict_time",600,t,count);
        }
}

//根据门派随机产生pker的落脚地点
string query_site()
{
        mapping sites=([
                "将军府":               ({"/d/jjf/gate","/d/jjf/stone_road","/d/jjf/pavillion"}),
                "火云洞":               ({"/d/qujing/kusong/songlin1","/d/qujing/kusong/kusongjian","/d/qujing/kusong/yongdao1"}),
             "南海普陀山":      ({"/d/nanhai/gate","/d/nanhai/tingjing","/d/nanhai/guangchang"}),
                "五庄观":               ({"/d/qujing/wuzhuang/linyin2","/d/qujing/wuzhuang/guangchang"}),
                "大雪山":               ({"/d/xueshan/shanpo","/d/xueshan/xuelu"}),
                  "月宫":       ({"/d/moon/backyard","/d/moon/neartop","/d/moon/road3"}),
               "阎罗地府":      ({"/d/death/gate","/d/death/new-walk2"}),
               "东海龙宫":      ({"/d/sea/gate","/d/sea/yujie2","/d/sea/under4"}),
            "陷空山无底洞":     ({"/d/qujing/wudidong/dong","/d/qujing/wudidong/dong2"}),
               "蜀山剑派":      ({"/d/shushan/square","/d/shushan/shanjiao"}),
            "花果山盘丝洞":     ({"/d/pansi/damen","/d/pansi/hubian"}),
             "方寸山三星洞":    ({"/d/lingtai/uphill5","/d/lingtai/gate1"}),
//                 "三界山":              ({"/d/sanjie/tianyidian4","/d/sanjie/tianyaodian","/d/sanjie/tianyidian4"}),
        ]);

        return sites[faction][random(sizeof(sites[faction]))];
}

void juedou()
{
        object ob;
        object *user;
        int i, exp, skill, killer = 0;

        user = users();
        for(i=0;i<sizeof(user);i++)
                if (user[i]->query_temp("hj_killer") > killer) lead = user[i];

        ob = new("/d/newjob/tiandijie/obj/zhanshu.c");
        ob->move(lead);
        message_vision(HIY"一张战书飘到了$N的面前。\n"NOR,lead);
        message("system", HIM"【天地劫】"+"听说某人得到了一张魔教教主无天老祖的挑战书。\n"NOR,users());

        exp = lead->query("combat_exp");
        skill = lead->query_skill("parry",1);
        ob = new("/d/newjob/tiandijie/npc/mengmo.c");
        ob->set("pk_target",lead);
        ob->move("/d/city/center.c");
        message_vision("$N凶神恶煞的走了过来。\n",ob);
}

//定时判断浩劫发生的时间是否超过期限，超过则给予玩家惩罚
void verdict_time(int t,int count)
{
        object *user;
        int i,exp;
        if(DISASTER_D->query("xinmo_die")<t){
        user = users();
                for(i=0;i<sizeof(user);i++) {
                        if (!user[i]||user[i]->query("family/family_name") != faction)continue;
                        exp = (int) user[i]->query("daoxing") * 0.01;
                        if (exp > 1000) exp=1000;
                        user[i]->add("daoxing",-exp);
                    tell_object(user[i], HIC"魔教血洗"+faction+"得手,你护派无力，失去了"+COMBAT_D->chinese_daoxing(exp)+"道行！\n");
                }
        message("system", HIR"【天地劫】"HIW+faction+"弟子力战之下，伤亡惨重，从此消声匿迹。\n"NOR,users());
        }else{
        message("system", HIR"【天地劫】"HIW+faction+"弟子力战之下，击退了魔教，避免了这场浩劫。\n"NOR,users());
        }
        DISASTER_D->delete("xinmo_die");
        if (count<12  ) {
                message("system", HIR"【天地劫】"HIW"魔教教主心魔老祖冷哼一声：下一个！\n"NOR,users());
                call_out("disaster",11,count+1);
        }
        else {
                message("system", HIR"【天地劫】"HIW"虽然各派奋力杀敌，击退魔教，无奈损失太大，一时间腥风血雨，三界一片混暗。\n"NOR,users());
                message("system", HIR"【天地劫】"HIW"太白金星：魔教虽然暂时退了，但不知什么时候又会卷土重来!\n"NOR,users());
                call_out("disaster",3600,0);
                call_out("juedou",5);
        }
}
