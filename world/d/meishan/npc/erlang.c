//erlang.c writted by Beeby. 07/30/2000
//By tianlin@mhxy for 2001.10.3ÐÞ¸Äbug<ansi.h>=MAG
#include <ansi.h>

inherit NPC;
int begin_chasing();
void create()
{
        set_name("¶þÀÉÕæ¾ý", ({"erlang zhenjun", "erlang", "zhenjun"}));
        set("long", "ËûÊÇ³à³ÇÕÑ»ÝÓ¢ÁéÊ¥£¬ÏÔ»¯ÎÞ±ßºÅ¶þÀÉ¡£
Á¦·ü°Ë¹ÖÉùÃûÔ¶£¬Òå½áÃ·É½ÆßÊ¥ÐÐ¡£\n");
	set("looking", "ÒÇÈÝÇå¿¡Ã²ÌÃÌÃ£¬Á½¶ú´¹¼çÄ¿ÓÐ¹â¡£");
        set("age", 28);
        set("attitude", "peaceful");
        set("gender", "ÄÐÐÔ");
        set("title", "ÕÑ»ÝÁéÏÔÍõ");
        set("str", 40);
        set("int", 40);
        set("per", 30);
	set("con", 30);
        set("max_kee",3000);
        set("max_sen", 3000);
        set("combat_exp", 1500000);
        set("daoxing", 2500000);

        set("force", 4000);
        set("max_force", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 150);
        set("mana_factor", 120);

        set("eff_dx", 800000);
        set("nkgain", 800);

        set_skill("unarmed", 200);
	set_skill("force", 180);
	set_skill("spells", 180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("spear", 200);
        set_skill("dao",200);
        set_skill("wuxiangforce",200);
	set_skill("moyun-shou", 200);
	set_skill("moshenbu", 200);
        set_skill("bawang-qiang", 200);
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("force","wuxiangforce");
        map_skill("spells","dao");
        set("inquiry", ([ /* sizeof() == 4 */
  		"me" : (: begin_chasing :),
  		"here" : "ÎÒ·îÓñµÛÚÍÖ¼£¬ÕýÒªÐË±ø×½ÄÃ·´³öÌì¹¬µÄÆëÌì´óÊ¥¡£",
  		"name" : "ÎÒÄË¶þÀÉÉñÑîê¯ÊÇÒ²¡£",
  		"ÆëÌì´óÊ¥" : (: begin_chasing :),
	]) );

        setup();
        carry_object("/d/meishan/npc/obj/spear")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/obj/drug/jinchuang")->set_amount(random(10));
}

void init()
{
	object me=this_object();
	object who=this_player();
	if (me->query("name") != "¶þÀÉÕæ¾ý" && me->query_temp("chasing_status") && 
	environment(me)!=me->query_temp("last_env"))
	{
	   me->set("name","¶þÀÉÕæ¾ý");
	   me->set("title","ÕÑ»ÝÁéÏÔÍõ");
	   message_vision(HIY"$N¿ÚÄîÖäÓï£¬ÉíÐÎÒ»»Î£¬ÏÖÁËÕæÉí¡£\n"NOR,me);
	}
	return ::init();
}
			
		     
void die()
{
	object who;
	object me=this_object();
	remove_call_out("check_status");
        if( environment() ) {
        message("sound", "\n\n¶þÀÉÉñÅ­µÀ£ºÄãÄªÒª²þ¿ñ£¬´ýÎÒÉÏÌì¸æÓù×´È¥£¡\n\n", environment());
        message("sound", "\n¶þÀÉÉñ´îÉÏ°×ÔÆ£¬¾¶ÍùÄÏÌìÃÅ·ÉÈ¥¡£¡£¡£\n\n", environment());
        command("drop all");
        }
	if (query_temp("chasing_status")==5 && !query_temp("chasing_fail")
	    && query_temp("current_player"))
	{
	   who=query_temp("current_player");
	   who->set("dntg/erlang","done");
	   who->add("cor",2);
	   tell_object(who,HIW"Äã¾õµÃ×ÔÒÑµÄµ¨Ê¶Ò»ÏÂ×ÓÔö¼ÓÁË²»ÉÙ£¡\n"NOR);
	   CHANNEL_D->do_channel(me,"chat",who->query("name")+"ÄãÄªÒª²þ¿ñ£¬´ýÎÒÉÏÌì¸æÓù×´È¥£¡");
	} 

        destruct(this_object());
}

void kill_ob(object who)
{
	if (!query_temp("current_player"))
	  return ::kill_ob(who);
	if (query_temp("current_player")!=who)
	  set_temp("chasing_fail",1);
	return ::kill_ob(who);
}

int accept_fight(object who)
{		
	if (query_temp("chasing_status"))
	  {
	    if (query_temp("current_player")!=who)
	     return notify_fail("¶þÀÉÕæ¾ýÒ¡ÁËÒ¡Í·£º¡°µÈÎÒÏÈÊÕÊ°ÁËÕâ¸ö³ôºï×Ó°É£¡¡±\n");
	    else
	     kill_ob(who);
	  }
	return ::accept_fight(who);
}	
	  
	

int receive_damage(string arg,int damage,object me)
{
	if (this_object()->query_temp("no_damage"))
	   return 1;
	else return ::receive_damage(arg,damage,me);
}

int begin_chasing()
{
	object me=this_object(); 
	object who=this_player();
	if (who->query("dntg/erlang") == "done" )
	 {
	 	command("shake");
	 	command("say ÕâÎ»"+RANK_D->query_respect(who)+"µÄ¹¦·òÒÑ¾­Áì½Ì¹ýÁË¡£\n");
	 	return 1;
	 }
	if (query_temp("chasing_status"))
	 {
		if (query_temp("current_player")==who)
		  command("say Äã¹Ô¹ÔÍ¶½µ°Õ!");
		else
		  command("say ÔõÃ´ÓÖÀ´Ò»¸ö£¿´ô»áÔÙÀ´ÊÕÊ°Äã£¡");
		return 1;
	 }
	command("look "+who->query("id"));
	command("jump");
	command("say ÎÒÕý³îÄÃÄã²»µ½£¬ÄãÈ´ËÍÉÏÃÅÀ´£¬ÕæÊÇÌìÖúÎÒÒ²£¡");
	command("follow "+who->query("id"));
	me->set("max_kee",4000);
	me->set("max_sen",4000);
	me->set("eff_kee",4000);
	me->set("eff_sen",4000);
	me->set("kee",4000);
	me->set("sen",4000);
	me->set("force",4000);
	me->set("mana",4000);
	me->kill_ob(who);
	who->kill_ob(me);
	me->set_temp("current_player",who);
	me->set_temp("chasing_status",0);
	me->set_temp("no_damage",1);
	remove_call_out("check_status");
	call_out("check_status",1);
	return 1;
}

void check_status()
{
	object me=this_object();
	object who=query_temp("current_player");
	string *id_list;
	if (!who || who->is_ghost())
	 {  
	    message_vision("$NÀäÐ¦Ò»Éù£º¡°ËùÎ½ÆëÌì´óÊ¥Ò²²»¹ýÈç´Ë°Õ!¡±\n"+
	                  "×ªÉí¼ÜÆðÒ»¶ä°×ÔÆ»ØÃ·É½È¥ÁË¡£\n",me);
	    remove_call_out("check_sratus");
	    destruct(me);
	    return;
	 }
	if (me->query("eff_kee") < me->query("max_kee")*9/10 &&
	    present("jinchuang yao",me))
	   command("eat yao");
	if (me->query("kee") < me->query("eff_kee")*9/10 &&
	    me->query("force") > 0)
	   command("exert recover");
	if (me->query("sen") < me->query("eff_sen")*9/10 &&
	    me->query("force") > 0)
	   command("exert refresh");
	if (!present(who,environment(me)))
	 {
	   me->move(environment(who));
	   message_vision("$N×ßÁË¹ýÀ´¡£\n",me);
	 }
        if (id_list=who->query_temp("apply/id"))
	   switch (me->query_temp("chasing_status"))
	   {
	   	case 0:if (member_array("maque",id_list)!=-1 
	   	           && environment(me)->query("short")=="É½ÑÂ") 
	   		{
	   		 message_vision(HIY"$NÊÖÄí¿Ú¾÷£¬Äî¶¯ÕæÑÔ£¬Ò¡ÉíÒ»±ä£¬±ä³ÉÒ»Ö»È¸Ó¥£¡\n"NOR,me);
	   		 me->set_temp("chasing_status",1);
	   		 me->set("name","È¸Ó¥");
	   		 me->set("title","");
	   		 me->set_temp("last_env",environment(me));
	   		 break;
	   		}
	   	case 1:if (member_array("ci hu",id_list)!=-1
	   		   && environment(me)->query("short")=="[0;35mÐ¡ÏªÇ°[m")
	   		{
	   		 message_vision(HIY"$NÊÖÄí¿Ú¾÷£¬Äî¶¯ÕæÑÔ£¬Ò¡ÉíÒ»±ä£¬±ä³ÉÒ»Ö»º£º×£¡\n"NOR,me);
	   		 me->set_temp("chasing_status",2);
	   		 me->set("name","º£º×");
	   		 me->set("title","");
	   		 me->set_temp("last_env",environment(me));
	   		 break;
	   		}
	   	case 2:if (member_array("fish",id_list)!=-1
	   		&& environment(me)->query("short")=="Ð¡Ïª")
	   		{
	   		 message_vision(HIY"$NÊÖÄí¿Ú¾÷£¬Äî¶¯ÕæÑÔ£¬Ò¡ÉíÒ»±ä£¬±ä³ÉÒ»Ö»ÓãÓ¥£¡\n"NOR,me);
	   		 me->set_temp("chasing_status",3);
	   		 me->set("title","");
	   		 me->set("name","ÓãÓ¥");
	   		 me->set_temp("last_env",environment(me));
	   		 break;
	   		}
	   	case 3:if (member_array("shui she",id_list)!=-1
	   		&& environment(me)->query("short")=="Ð¡Ïª")
	   		{
	   		 message_vision(HIY"$NÊÖÄí¿Ú¾÷£¬Äî¶¯ÕæÑÔ£¬Ò¡ÉíÒ»±ä£¬±ä³ÉÒ»Ö»»Òº×£¡\n"NOR,me);
	   		 me->set_temp("chasing_status",4);
	   		 me->set("name","»Òº×");
	   		 me->set("title","");
	   		 me->set_temp("last_env",environment(me));
	   		 break;
	   		}
	   	case 4:if (member_array("hua bao",id_list)!=-1
	   		 && environment(me)->query("short")=="[0;35mÐ¡ÏªÇ°[m")
	   		{
	   		 me->delete_temp("no_damage");
	   		 me->set_temp("chasing_status",5);
	   		}
	   }
	 
	remove_call_out("chech_status");
	call_out("check_status",1);
	return;
}   
