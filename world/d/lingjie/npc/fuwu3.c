//fwzong.c服务员总管
//by jjgod
#include <ansi.h>

inherit NPC;
int do_gongzuo() ;
int accept_object(object me, object ob) ;
void create()
{
	set_name("服务员总管", ({"zong guan", "zongguan","guan"}));
	set("gender", "男性");
	set("age", 45);
	set("str", 27);
	set("long", "这人相貌和蔼，笑呵呵的。你可以问他要工作做（job）。\n");
	set("combat_exp", 700000);
	set("attitude", "friendly");
	set_skill("unarmed", 120);
	set_skill("force", 130);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	set("kee", 2000);
	set("max_kee", 2000);
	set("force", 2500); 
	set("max_force", 2500);
	 set("inquiry", 
                ([
                  "工作" : (: do_gongzuo :),
	"job" : (: do_gongzuo :),
                ]));
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
void greeting(object ob) 
{ 
           string respect=RANK_D->query_respect(ob); 
     
              if( !ob || environment(ob) != environment() ) return; 
              switch(random(1)) {
                      case 0:
                              message_vision(CYN"$N笑着对$n说道：「这位" + respect 
                      + "，你是不是想洗盘子？」\n"NOR, this_object(),ob);  
                              break; 
                      case 1:
                              message_vision(CYN"$N跑过来对$n说道：「这位" + respect 
                      + "，洗盘子就问我要！"WHT"（ask guan about job）"CYN"」。\n"NOR, this_object(),ob);  
                              break; 
                     default : 
			     break;
             }  

} 
int do_gongzuo() 
{ 
object me= this_player();
if( me->query_temp("工作/洗盘子")>0) 
{ 
tell_object(me,"服务员总管拍拍你的头，说道：“快去洗盘子吧。”\n"); 
return 1; 
} 
message_vision(CYN"总管对$N说道：这几天客人多！盘子洗不过来，嗯，\n你就去后柜台找服务员要点盘子来洗吧。\n"NOR,me); 
me->set_temp("工作/洗盘子",1); 
return 1; 
} 
int accept_object(object me, object ob) 
{ 
object ob2,ob3;
int i=ob->query_amount();
me=this_player();
if (me->query_temp("工作/洗盘子")<1) 
{
command("say 你没有找我要过工作吧。\n"); 
return 1;
}
if( (string) ob->query("name") != "洗好的盘子"){
command("say 这是洗好的盘子？你不是开玩笑吧！\n"); 
return 1;
}
else
message_vision(CYN"总管对$N说道：辛苦了，这是你的工钱。\n"NOR,me); 
ob2 = new("/obj/money/silver");
ob2->set_amount(i);
ob2->move(me);
message_vision(CYN"总管给了$N"+chinese_number(i)+"元钱。\n"NOR,me); 
me->add("combat_exp",50); 
me->delete_temp("工作/洗盘子"); 
me->delete_temp("工作/给盘子"); 
call_out("destroying", 1, this_object(), ob); 
return 1;
}