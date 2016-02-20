#include <ansi.h>
inherit NPC;
int ask_ge();
int ask_la();
int ask_long();
int ask_sex();

void create()
{
	set_name("美容师",({"meirongshi","meirong shi","shi"}));
	set("title",HIR"丑人克星"NOR);
	set("nickname",HIC"整人专家"NOR);
	set("long",
		"\n这是一个大夫打扮的英俊少年,神采飞扬。\n"
		"他就是幻想西天的美容师,专门负责对容貌不佳的玩家进行美容服务。\n"
		"美容可是高消费哦,听说割双眼皮要100gold,拉皮300gold,隆胸500gold,\n"
		"至于变性嘛,属于超前消费,不二价1000gold。\n");
	set("gender","男性");
	set("age",21);
	set("per",40);
	set("str",30);
	set("int",40);
	set("attitude", "friendly");
	
	set("max_kee",10000);
	set("kee",10000);
	set("max_sen",10000);
	set("sen",10000);
	set("max_force",50000);
	set("force",50000);
	set("max_mana",50000);
	set("mana",50000);
	set("combat_exp",100000000);
    set("daoxing",100000000);
  set("force_factor", 200);
  set("mana_factor", 200);

	set_skill("blade",500);
	set_skill("dodge",500);
	set_skill("parry",500);
	set_skill("unarmed",500);
	set_skill("dragonfight",500);
	set_skill("kugu-blade",500);

	map_skill("dodge","kugu-blade");
	map_skill("parry","kugu-blade");
	map_skill("blade","kugu-blade");
	map_skill("unarmed","dragonfight");

	set("inquiry", ([
		"割双眼皮":(: ask_ge :),
		"隆胸":(: ask_long :),
		"拉皮":(: ask_la :),
		"变性":(: ask_sex :),
	]) );
set("chat_chance_combat", 80);

	set("chat_msg_combat", ({
		"\n美容师摇头叹道：螳臂当车，不自量力。唉，你这又是何苦呢?\n",
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 这位" + RANK_D->query_respect(this_player())+",你我无冤无仇，何必如此?\n") :),		
(: perform_action, "blade.diyu" :),
                (: exert_function, "recover" :),                          
	}) );
	setup();

 carry_object("/u/bmw/obj/dao")->wield();
  carry_object("/u/bmw/obj/cloth")->wear();
}

void init()
{
  add_action("do_ok", "ok");
  add_action("do_sure", "sure");
  add_action("do_nod","nod");
  add_action("do_yes","yes");
}

int ask_ge()
{        
	object me=this_player();
        command("say 你确定要割吗？（ok）要割的话受费100gold，我会从你的
钱庄帐号里扣除！\n");
        me->set("ge",time()+60);
        return 1;
        }
int ask_long()
{        
	object me=this_player();
        command("say 你想隆胸？好把隆胸受费500gold，我会从你的
钱庄帐号里扣除！（sure)\n");
        me->set("long",time()+60);
        return 1;
}
int ask_la()
{        
	object me=this_player();
        command("say 想拉皮？拉皮受费300gold，从你的
钱庄帐号里扣除！确定吗？(nod)\n");
        me->set("la",time()+60);
        return 1;
        }
int ask_sex()
{        
	object me=this_player();
        command("say 这可是大手术呀，受费1000gold不算贵吧，如果你真的
想作的话，（yes)我会从你的钱庄帐号里扣除！\n");
        me->set("sex",time()+60);
        return 1;
        }

int do_ok()
{
	object me = this_player();
	if (me->query("ge")>(int)time())
{	 
	if (me->query("bmw_ge")=="done"){
//	command("hit"+ me->query("id"));
	tell_object(me,"你割过双眼皮拉,还要割,难道你想割成三眼皮? \n");
	return 1;
	}
	if (me->query("per")>=25){
	command("shake " + me->query("id"));
	tell_object(me,"你本来就是双眼皮,还割什么? \n");
	return 1;
	}
 if (me->query("balance")<1000000){
//         command("slap " + me->query("id"));
         tell_object(me,"穷光蛋,饭都吃不饱,还来美容! \n");
         return 1;
         }
	else {
		me->set("bmw_ge","done");
		me->add("per",1);
me->save();
                me->add("balance",-1000000);
                command("ok " + me->query("id"));
                message("channel:chat",HIY+"【美容中心】：听说 "+me->query("name")+" 在美容中心割了双眼皮！\n"+NOR,users());
		        me->unconcious();
				me->move("/u/bmw/room/bed_room");
		return 1;
	}	
 return 1;
}else { message_vision("什么\n");return 1;}return 1;
}
int do_sure()
{
	object me = this_player();
		if (me->query("long")>(int)time())
{
	
	if (me->query("gender")!="女性"){
//	command("slap " + me->query("id"));
	tell_object(me,"你变态呀，男的还来隆胸？？？？\n");
	message("channel:chat",HIY+"【美容中心】："+me->query("name")+" ！！你着个变态，居然跑到美容中心来做隆胸！\n"+NOR,users());
	return 1;
	}	 
	if (me->query("bmw_long")=="done"){
//	command("hammer " + me->query("id"));
	tell_object(me,"你的胸部都隆的和气球一样大了，还隆? \n");
	return 1;
	}
	if (me->query("per")>=25){
	command("heihei " );
	tell_object(me,"你的胸部已经不小了! \n");
	return 1;
	}
 if (me->query("balance")<5000000){
  //      command("slap " + me->query("id"));
         tell_object(me,"穷光蛋,饭都吃不饱,还来隆胸! \n");
         return 1;
         }
	else {
		me->set("bmw_long","done");
		me->add("per",2);
me->save();
                me->add("balance",-5000000);
                command("ok " + me->query("id"));
               message("channel:chat",HIY+"【美容中心】：听说 "+me->query("name")+" 在美容中心做了一个隆胸手术，胸围增大了XX寸！\n"+NOR,users()); 
	        	me->unconcious();
				me->move("/u/bmw/room/bed_room");
		return 1;
	}	
 return 1;
}
else { message_vision("什么\n");return 1;}return 1;
}
int do_nod()
{
	object me = this_player();
	 	if (me->query("la")>(int)time())
{
	if (me->query("bmw_la")=="done"){
//	command("sigh " + me->query("id"));
	tell_object(me,"经常拉皮对身体不好！不要为了美容而伤了身体！ \n");
	return 1;
	}
	if (me->query("per")>=25){
//	command("pat " + me->query("id"));
	tell_object(me,"你的皮肤很好，不用拉了，再拉就拉成怪物了！\n");
	return 1;
	}
 if (me->query("balance")<3000000){
  //       command("kick " + me->query("id"));
         tell_object(me,"穷光蛋,饭都吃不饱,还来美容! \n");
         return 1;
         }
	else {
		me->set("bmw_la","done");
		me->add("per",1);
me->save();
                me->add("balance",-3000000);
                command("nod " + me->query("id"));
                message("channel:chat",HIY+"【美容中心】：听说 "+me->query("name")+" 在美容中心拉了个皮，变的年轻多了！\n"+NOR,users());
	        	me->unconcious();
				me->move("/u/bmw/room/bed_room");
		return 1;
	}	
 return 1;
}
else { message_vision("什么\n");return 1;}return 1;
}
int do_yes()
{
	object me = this_player();
       if (me->query("sex")>(int)time())
   {    
	if (me->query("bmw_sex")=="done"){
//	command("sigh " + me->query("id"));
	tell_object(me,"你这人是不是有毛病呀？当你的身体是泥巴捏的呀？随便乱搞！ \n");
	return 1;
	}

 if (me->query("balance")<10000000){
  //       command("kick " + me->query("id"));
         tell_object(me,"穷光蛋,饭都吃不饱,还来变性! \n");
         return 1;
         }
	else {
		me->set("bmw_sex","done");
		
    if(me->query("gender")=="女性") me->set( "gender", "男性" );
    else me->set( "gender", "女性" );
                me->add("balance",-10000000);
				me->add("per",-3);
                command("nod " + me->query("id"));
                message("channel:chat",HIY+"【美容中心】：听说 "+me->query("name")+" 在美容中心做了个变性手术！\n"+NOR,users());
		        me->unconcious();
				me->move("/u/bmw/room/bed_room");
		return 1;
	}	
 return 1;
}    
else { message_vision("什么\n");return 1;}return 1;
}

   
