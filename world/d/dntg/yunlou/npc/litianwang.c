//by tianlin 2001.5.1
//by tianlin@mhxy for 2001.9.18´ÓÐÂÐÞ¸Ä
#include <ansi.h>
inherit NPC;

string *list=({"yg-putuo","yg-moon","yg-wzg","yg-shushan","yg-hyd",
	"yg-fangcun","yg-hell","yg-jjf","yg-pansi",
	"yg-dragon", "yg-xueshan","yg-kaifeng",
	"yg-wudidong",
	});

int work_me();
int cancel_me();
int delete_ask(object me);
 
void create()
{
 
	set_name(HIY"Àî¾¸"NOR, ({ "li jing", "jing", "li" }) );
	set("gender", "ÄÐÐÔ" );
	set("long", "ÍÐËþÀîÌìÍõÄËÊÇÌì½çÔªË§£¬÷âÏÂÊ®ÍòÌì±øÌì½«£¬·¨Á¦ÎÞ±ß¡£\n");
	set("age",40);
	set("title", HIC"ÍÐËþ"NOR+HIW"ÌìÍõ"NOR);
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("spi", 30);
	set("per", 30);
	set("class", "xian");
	set("attitude", "heroism");
	set("combat_exp", 1500000);
	set("daoxing", 2000000);
	set("max_kee", 2000);
	set("max_sen", 2000);
	set("force",5000);
	set("max_force",3000);
	set("force_factor", 150);
	set("mana", 5000);
	set("max_mana", 3000);
	set("mana_factor", 150);

	set("eff_dx", 600000);
	set("nkgain", 600);

	set_skill("unarmed",170);
	set_skill("dodge",170);
	set_skill("parry",170);
	set_skill("sword", 180);
	set_skill("force", 170);
	set_skill("spells", 170);
 	set_skill("changquan", 170);
	set_skill("liangyi-sword", 180);
	set_skill("baguazhou", 170);
	set_skill("moshenbu", 170);
	set_skill("lengquan-force", 170);
	map_skill("unarmed", "changquan");
	map_skill("force", "lengquan-force");
	map_skill("spells", "baguazhou");
	map_skill("sword", "liangyi-sword");
	map_skill("parry", "liangyi-sword");
	map_skill("dodge", "moshenbu");
	
	set("chat_chance",1);
	set("chat_msg", ({
		    name()+"ËµµÀ£ºÄÄÎ»´óÏÉ¿ÉÔ¸È¥ÏÂ½çÃðÑý£¿\n",
		    }));

        seteuid(getuid());

	set("inquiry", ([
	"mieyao": (: work_me :),
	"kill": (: work_me :),
	"ÃðÑý": (: work_me :),
	"·ÅÆú": (: cancel_me :),
	"fangqi": (: cancel_me :),
	"cancel": (: cancel_me :),
	]));

	setup();
	carry_object("/d/obj/fabao/huangjin-baota");
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/sky/obj/zhanyaojian")->wield();
}
//this funtion is modified by vikee 2000-11-20 1:32
int cancel_me()
{	object ghost,me=this_player();
//this modi by cnd delete here if for bug
	if(!me->query("mieyao/time_start")||
           me->query("mieyao/time_start")+180<time() ||
	   me->query("mieyao/time_start")>time() ||
	   me->query("mieyao/done")||
	   !me->query_temp("mieyao/ob"))
	   
	{
	   command("bite");
	   command("say ÄãÃ»ÓÐÔÚÉ±Ñý£¬À´´ÕÊ²Ã´ÈÈÄÖ£¡\n");
	   return 1;
       }
	ghost=me->query_temp("mieyao/ob");
	if (!living(ghost))
	{
	   command("say "+ghost->query("name")+"Õâ¸öÐóÉúÒÑ¾­ÅÜÁË!\n");
	   return 1;
        }
	me->delete_temp("mieyao/ob");
// É¾³ýÃðÑý×ÊÁÏ
	me->delete_temp("mieyao/name");
	me->delete_temp("mieyao/time_start");
	//Èç¹û·ÅÆúÕâ¸ö¹ÖÎï,µ±Ç°µÄlevel´ÓµÚÒ»¸ö¿ªÊ¼.
	me->set_temp("mieyao/level",1);
	command("shrug");
	command("say Äã¼ÈÈ»ÎÞÁ¦ÊÕ·þ"+ghost->query("name")+", Ö»ºÃÈÎËüÈ¥ÁË¡£\n");
	me->set("mieyao/done",1);

	destruct(ghost);
	return 1;
}
 
int work_me()
{
	object ghost, me;
	int t, lvl;
	me=this_player();
	//for first time.
	if(!me->query("mieyao")) {
		call_out("start_job", 1, me);
		return 1;
	}
	if( (t=(int)me->query("mieyao/time_start")) &&
		!me->query("mieyao/done")) {

	    if(t<=time() &&
                    time()<t+180) {
		command("heng");
		command(
 		  "say ÀÏ·ò²»ÊÇÅÉÄãÈ¥½µ·þ"+me->query("mieyao/name")
		  +"Âð£¿\n");
		return 1;
	    }
	    // here is modified by vikee for the #9 ask li about kill 's bug
	    // or the #8 {u;ask li about kill;d}'s bug,
	    // set a flag "mieyao/level_change" to judge the monster level.
	    
	    if(!me->query_temp("mieyao/level_changed")) {
		lvl=me->query_temp("mieyao/level");
		if(lvl>0) lvl--;
		me->set_temp("mieyao/level",lvl);
		me->set_temp("mieyao/level_changed",1);
	    }
	    // allow ask again.
	} else { // job done
	    if(t<=time() &&
                    time()<t+180) {
		message_vision("$N¶ÔÊÖÖÐÕÕÑý¾µÒ»¿´£¬Ëµ"+
			"£ºÕâÎ»"+RANK_D->query_respect(me)
			+",ÑýÄ§ÒÑ³ý¾¡,²»·ÁÏÈÈ¥ÐªÏ¢¡£\n",
			this_object(), me);
		return 1;
	    }
	    // succeed, increase lvl.
	    if(!me->query_temp("mieyao/level_changed")) {
		lvl=me->query_temp("mieyao/level");
		if(lvl<9) lvl++; // total 10 levels: 0, ..., 9
		else
		    lvl=1; // reach the top level, reduce difficulty.
		me->set_temp("mieyao/level",lvl);
		me->set_temp("mieyao/level_changed",1);
	    }
	}
	me->delete("mieyao/time_start");
	call_out("start_job", 1, me);
	return 1;
}
int start_job(object me)
{	string where;
	object ghost;
	int lvl;

	if(environment(me)!=environment()) return 1;
	if(me->query("mieyao/time_start")) return 1;
	me->delete("mieyao/done");
	me->set_temp("mieyao/level_changed",0);

	// determine levels.
	// use temp mark, if quit, then start over.
	lvl=me->query_temp("mieyao/level");
	
        ghost = new(__DIR__+list[random(sizeof(list))]);
        where=ghost->invocation(me, lvl);
	
	message_vision("$N½«ÊÖÖÐÕÕÑý¾µ³¯ÏÂ½çÒ»»Î£¡\n",this_object());
	message_vision("$N¶Ô[1;31m$n[2;37;0mËµµÀ£º½üÓÐ"+where+"Îª·Ç×÷´õ£¬"
		+"ÇëËÙÈ¥½µ·þ£¡\n"
		,this_object(),me);
	me->set("mieyao/time_start", time());
	me->set("mieyao/name",ghost->query("name"));
	me->set_temp("mieyao/ob",ghost);
	return 1;
}

int delete_ask(object me)
{
        me->delete_temp("asked/lijing");
        return 1;
}
