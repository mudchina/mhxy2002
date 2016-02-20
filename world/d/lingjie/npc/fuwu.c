// fuwu.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("服务员", ({ "waiter", "fuwuyuan", "fuwu", "yuan"}) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位服务员正跑前跑后地忙着。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "不敢不敢，小的叫逍遥，是在本地上长大的。",
		"here" : "这里是广州呀，客官您竟然不知道？",
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int accept_object(object who, object ob)
{
	object fuwuyuan;

	if (ob->query("money_id")) {
		if (!objectp(fuwuyuan = present("waiter2", environment()))) {
			fuwuyuan = new(__DIR__"fuwu2");
			fuwuyuan->move(environment());
		}
		tell_object(who, "服务员道：“我带你去付帐。”\n");
		tell_object(who, "你跟着服务员来到柜台前，把钱交给服务员。\n");
		return fuwuyuan->accept_object(who, ob);
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("服务员对$N冷笑道：“别装腔作势啦，象你这种扮凶巴巴妄图吃饭不付钱的家伙我见多了，省省吧。”\n", ob);
	message_vision("$N心中纳闷：“我这番龌龊心思怎么全被他说中了？”\n", ob);
}

void greeting(object ob) 
{ 
           string time,respect;  
    
             time = NATURE_D->room_event(); // 调用
             respect=RANK_D->query_respect(ob); 
     
              if( !ob || environment(ob) != environment() ) return; 
               
              switch(time) {  // 使用switch 判断当前时间                         
                      case "event_sunrise": // 早上
                              message_vision(CYN"$N笑着对$n说道：「这位" + respect 
                      + "，今儿可真早啊，本店刚刚营业，欢迎光临。」\n"NOR, this_object(),ob);  
                              break; 
 
                      case "event_noon":   // 中午
                              message_vision(CYN"$N跑过来对$n说道：「这位" + respect 
                      + "，用过午饭了吗？快请坐。」\n"NOR, this_object(),ob);  
                              break; 

                     case "event_evening": // 傍晚
                              message_vision(CYN"$N笑嘻嘻地对$n说道：「这位" + respect 
                      + "，天快黑了，还是来本店歇歇吧，今天瞧把您给累的。」\n"NOR, this_object(),ob);  
                             break; 

                     case "event_midnight": // 午夜
                             message_vision(CYN"$N披着睡衣走出来，迷迷糊糊地对$n说道：「这位" + respect 
                     + "，可真不巧啊，本店已经打烊了，您还是天亮再来吧。」\n"NOR, this_object(),ob); 
                             ob->move("/d/huafu/xjjicun");        
                             break; 
                     default : 
			     break;
             }  

} 


void unconcious()
{
	say( "服务员大喊一声：“我不行了，快来接班！”\n");
	say( "结果从柜台后面又钻出一个服务员来，说：“没问题，交给我吧。”\n");
	say( "前一个酒保快快乐乐地离开了。\n");
	reincarnate();
	set("eff_kee", query("max_kee"));
	set("kee", query("max_kee"));
	set("eff_gin", query("max_gin"));
	set("gin", query("max_gin"));
}

void die()
{
	unconcious();
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}
