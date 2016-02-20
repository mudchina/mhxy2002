
#include <ansi.h>

inherit NPC;
int ask_gongzuo(); 
void create()
{
	set_name("服务员", ({ "fw yuan","yuan" }));
	set("gender", "男性");
	set("age", 45);
	set("str", 27);
	set("long", "这人相貌和蔼，笑呵呵的。你可以问他要盘子洗。\n");
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
	 set("inquiry",  ([
	"盘子" : (: ask_gongzuo :), 
	"panzi" : (: ask_gongzuo :), 
	"plate" : (: ask_gongzuo :), 
                ]));
	setup();
}
void init()
{	
	object ob;
	if( interactive(ob = this_player())&&ob->query_temp("工作/洗盘子")){
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
                      + "，你是不是想洗盘子？"WHT"（ask yuan about panzi）"CYN"」\n"NOR, this_object(),ob);  
                              break; 
                      case 1:
                              message_vision(CYN"$N跑过来对$n说道：「这位" + respect 
                      + "，洗盘子就问我要！"WHT"（ask yuan about panzi）"CYN"」。\n"NOR, this_object(),ob);  
                              break; 
                     default : 
			     break;
             }  

} 

int ask_gongzuo() 
{ 
object me,ob; 
int i=random(10);
me = this_player(); 
if(!me->query_temp("工作/洗盘子")) 
{
tell_object(me,"你还是先去给服务员总管打个招呼吧。\n"); 
return 1;
}
if( me->query_temp("工作/给盘子")> 0) 
{
tell_object(me,"服务员疑惑不解的对你说：“我不是给过你盘子了吗？难道你丢了它？”\n "); 
return 1;
}
ob = new(__DIR__"obj/zangpanzi"); 
ob->set_amount(i);
ob->move(me); 
me->set_temp("工作/给盘子", 1); 
message_vision("服务员给了$N一叠脏盘子。\n",me); 
tell_object(me,"服务员告诉你：“好吧，你快去厨房洗赶干净这些盘子吧。”\n "); 
return 1;
} 