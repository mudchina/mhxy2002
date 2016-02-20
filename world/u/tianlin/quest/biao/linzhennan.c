// linzhennan.c 林震南
// modified by Jay 4/7/96

#include <ansi.h>
int potential_lv(int exp);
inherit NPC;

//#define CART_PATH "cart"
//moon,shushan,wzg,lingtai,kaifeng
string do_quest();
string* dart_area=({"/d/moon/nroom","/d/shushan/yongdao","/d/kaifeng/dangpu","/d/lingtai/room",
                    "/d/jz/in"});
string* dart_short=({"月宫","蜀山","开封","灵台","江州"});
string* dart_id=({"magu","lin yueru","xu laoban","master puti","yin wenjiao"});
string* dart_name=({"麻姑","林月如","徐老板","菩提祖师","殷温娇"}); 
string do_job();
string do_give();
int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

string daoxing(int dx)
{
        
        int day,hour;
        day = (dx) / 4;
        hour = (dx  - day * 4) * 3; 
        return day?(chinese_number(day)+"天"):""+hour?(chinese_number(hour)+"时辰"):"";
}

void create()
{
        set_name("林震南", ({ "lin zhennan", "lin", "zhennan" }));
        set("gender", "男性");
        set("age", 45);
        set("title", "福威镖局总镖头");
        set("long", "他就是「福威镖局」的总镖头－－林震南。\n");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("max_neili", 500);
        set("force", 500);
        set("jiali", 10);
        set_skill("force", 40);
        set("per",19);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("inquiry", ([
                "向阳老宅" : "林震南说道：那是我从前在福建时住的家院，已经破败了。\n",
                "林远图" : "林震南大怒：小孩子这么没礼貌，直呼先人名讳！\n",
                "运镖" : (: do_job :),
                "镖"   : (: do_job :),
                "工作" : (: do_job :),
                "job"  : (: do_job :),
                "领赏" : (: do_give :),
                "over" : (: do_give :),
        ]) );
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

string chinese_time(int t)
{
        int d, h, m, s;
        string time;
        s = t % 60;     t /= 60;
        m = t % 60;     t /= 60;
        h = t % 24;     t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        return time;
}

string do_job()
{   int n;
    object ob,cart;
    ob=this_player(); 
    n=random(sizeof(dart_area));   

//    return "由于保镖中出了点问题，本镖局决定整顿一下，这几天不开门了。\n";
    
    if ( ob->query_temp("in_dart"))
       return "你不是才要了任务吗？\n";

    if ( (int)ob->query_condition("dart_limit" ) > 0 )
       return "你好象没完成任务吧。\n";

    if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "你现在正忙着呢。\n";

    if ( (int)ob->query("combat_exp") < 20000 )
       return "护镖是件危险工作，我看"+RANK_D->query_respect(ob)+"似乎没有这能力！\n";
//By tianlin@mhxy for 2002.1.24加上限制
    if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 2500000 )
       return "这种小事情哪能麻烦"+RANK_D->query_respect(ob)+"！\n";

    if ( (int)ob->query_skill("force") < 20 )
       return "护镖是件危险工作，我看"+RANK_D->query_respect(ob)+"的基本内力不足！\n";

    if ( (int)ob->query("dart/number") > 20 && (int)ob->query("age") < 18)   
       return "这位"+RANK_D->query_respect(ob)+"果然是位人才，不过官府规定18岁以下只能押20次镖，等你长大点再来吧！\n";
    
    if(!ob->query("dart/number")) ob->set("dart/number",1);
    else ob->add("dart/number",1);
    ob->set_temp("in_dart",1);
    ob->set_temp("dart_area",dart_area[n]);
    ob->set_temp("dart_id",dart_id[n]);
    ob->set_temp("dart_name",dart_name[n]);
    ob->set_temp("dart_area_name",dart_short[n]);
    ob->apply_condition("dart_limit", 3600);
    ob->set_temp("robber_rec",1);

    cart=new(__DIR__"cart");
    cart->set("master",ob->query("name"));
    cart->set("masterid",ob->query("id"));
    cart->move("/u/tianlin/quest/biao/biaoju");
    cart->set_leader(ob);
    command("nod");
    message_vision(CYN "几个伙计将镖推了出来。\n" NOR,ob); 
    return "你把这批红货送到"+dart_short[n]+"的"+dart_name[n]+"手中。\n";
    
}

string do_give()
{
int bonus;
  object ob;
  int dh,pot,wx,money;
// int max_pot;

  ob=this_player();
//   max_pot=(int)this_player()->query("max_pot");

  if ( !ob->query_temp("in_dart"))
    return "我没让你走镖啊？\n";

  if ( !ob->query_temp("over_dart") )
    return "镖车没有送到地头，莫非是你吞了！？\n";

    wx = random(1000)+1000;
    dh = random(1000)+5000;
    pot = random(1000)+2000;                    
    money = random(400000)+100000;
    
    ob->add("combat_exp",wx);
    ob->add("daoxing",dh);
//    ob->add("potential",pot);    
    ob->add("balance",money);
  
  message("system",HIY"【运镖天下】林镇南(Lin zhennan)："+ob->name()+"将镖车安全运到"+ob->query_temp("dart_area_name")+"，获得镖费"+chinese_number(money/10000)+"两金子！\n"NOR,users());
  message("system",HIY"【运镖天下】林镇南(Lin zhennan)："+ob->name()+"得到了"+daoxing(dh)+"道行、"+chinese_number(wx)+"点武学经验的奖励！\n"NOR,users());
  ob->delete_temp("in_dart");
  ob->delete_temp("over_dart");
  ob->delete_temp("dart_name");
  ob->delete_temp("dart_id");
  ob->delete_temp("dart_area");
  ob->delete_temp("robber_rec");

  command("pat "+ob->query("id"));
  return RANK_D->query_respect(ob)+"果然是栋梁之才！\n";
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp /500;
        return grade;
}

int accept_object(object who, object ob)
{
    int value;

        if (ob->query("money_id") && (value=ob->value()) >= 500000) 
        {
                command("sigh");
                tell_object(who, name()+
                        "说道：好吧，既然你把红货弄丢了，也只能赔偿了。\n");
                who->delete_temp("in_dart");
                who->apply_condition("dart_limit", 0);
//                take_money(value, 500000);
                return 1;
        }
        return 0;
}
