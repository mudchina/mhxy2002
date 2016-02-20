//By tianlin@mhxy for 2001.10.1
//°ËÔÂÊ®ÎåÖÆ×÷,¼ÓÈësldÃÅÅÉ
#include <ansi.h>
#define MAX_TRY 20
inherit NPC;
string ask_me();
string ask_mieyao();
string ask_cancel();
inherit F_MASTER;

void create()
{
	set_name("Áù¶úâ¨ºï", ({"liuer mihou", "liuer", "mihou"}));
	set("title", CYN"ÁéÍ¨×Ó"NOR);
       set("nickname","[1;33mÆëÌìĞ¡Ê¥[m");
	set("gender", "ÄĞĞÔ" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
  set("long", "
Áù¶úÁéºï±¾À´¾Ó×¡ÔÚÑ©É½£¬²»ÖªÎªºÎËû»áÔÚÕâÀï³öÏÖ¡£Áù¶úâ¨ºïÀä¿áÎŞÇé£¬
²»¹ıÒªÊÇÍ¶ÆäËùºÃ,ÄãÈÃËû°Ñ×Ô¼ºÀÏ×ÓÉ±ÁË¶¼ĞĞ£¡£¡¡£\n");
  set("combat_exp", 5000000);
  set("daoxing", 3456789);
  set("max_mana",5000);
  set("max_force",5000);
  set("force",5000);
  set("mana",5000);
  set("mana_factor",200);
  set("force_factor",200);
  set("attitude", "heroism");
  set_skill("unarmed", 290);
  set_skill("dodge", 260);
  set_skill("stick",280);
  set_skill("qitian-gun",280);
  set_skill("mihouxinjing",270);
  set_skill("mihou-force",280);
  set_skill("force",280);
  set_skill("spells",250);
  set_skill("jindouyun",260);
  set_skill("houquan",290);
  set_skill("parry", 260);
  set("per", 40);
  set("max_kee", 3500);
  set("max_gin", 3000);
  set("max_sen", 3000);
  map_skill("parry","qitian-gun");
  map_skill("dodge","jindouyun");
  map_skill("unarmed","houquan");
  map_skill("stick","qitian-gun");
  map_skill("spells","mihouxinjing");
  map_skill("force","mihou-force");
  set("chat_chance_combat", 90);
   set("chat_msg_combat", ({
    (: perform_action, "stick.wu" :)
   }) );
  create_family("Ë®Á±¶´", 2, "¶´Ö÷");
  setup();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/stick/xiangmo")->wield();
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "houyao");
                ob->set("title", "[1;32m»¨¹ûÉ½[41m[1;37mË®Á±¶´Áù¶úâ¨ºï´«ÈË[2;37;0m");
}
void init()
{
  object ob;
  ::init();
  set("chat_chance", 11);
  set("inquiry", ([
		"name": "ÆëÌì´óÊ¥ËïÎò¿ÕÊÇÒ²¡£\n",
		"here": "¡£¡£¡£\n",
		"ÈË²Î¹û": "ºïÒ¯ÎÒ×îÏ²»¶µÄ¾ÍÊÇÈË²Î¹û¡£\n",
		"É±ÈË": "É±ÈË£¿Ö»ÒªÄãÓĞÈË²Î¹û£¬Ê²Ã´¶¼ºÃÉÌÁ¿¡£\n",
		"ÃØ¾÷": "ÃØ¾÷£¿Ö»ÒªÄãÓĞÈË²Î¹û£¬Ê²Ã´¶¼ºÃÉÌÁ¿¡£\n",
		"â¨ºïÊÖ¼Ç": "ÊÖ¼Ç£¿Ö»ÒªÄãÓĞÈË²Î¹û£¬Ê²Ã´¶¼ºÃÉÌÁ¿¡£\n",
              "ËïÎò¿Õ" : "¾ÍËûÄÇÖÖµÀĞĞÒ²Åä³ÆÕ½¶·Ê¤·ğ£¿£¿ÎÒ¾ÍÊÇÀ´ÕÒËûÂé·³µÄ£¡£¡",
              "¶··ğ" : (: ask_mieyao :),
              "cancel" : (: ask_cancel :),
		"°ü¹ü"     : (: ask_me :),
		"Õæ¼Ù"     : (: ask_me :),
	]) );

}

int accept_object(object me, object ob)
{
	object book;

	if ( (string)ob->query("id") != "renshen guo" ) {
		message_vision("Áù¶úâ¨ºï¼âÉù½ĞµÀ£ºÈ¥£¡È¥£¡È¥£¡Äã¼ÒºïÒ¯Ã»¿ÕÀíÄã£¡\n", me);
		command("kick " + me->query("id"));
		//call_out("do_drop", 2, ob);
		return 1;
	}

	else {
		command("jump ");
		command("say ÕâÎ»" + RANK_D->query_respect(me) + "¹ûÈ»ÊÇÍ´¿ìÈË£¡\n");
		//first give a book...
 book = new("/d/obj/book/mihou-book");
		book->move(me);
		message_vision("$N¶Ô$nµÀ£ºÄÇºïÒ¯ÎÒÒ²²»ÄÜĞ¡Æø¡£Ëµ°Õµİ¸ø$nÒ»±¾Ğ¡²á×Ó¡£\n³ıÁËÕâ±¾ÊéÍâ£¬±ğµÄÎÒ°ï²»ÉÏ£¬µ«É±¸öÈËÊÇÃ»ÎÊÌâµÄ¡£ÄãÒªÉ±ÈËµÄ»°£¬¾¡¿É¸½¶úËµÀ´(whisper liuer enemy_id)¡£\n", this_object(), me);
		me->set_temp("rsg_given", 1);
       		return 1;
	}
}

void do_drop(object ob)
{
	command("drop "+ob->query("id"));
}

void relay_whisper(object me, string msg)
{
	object target, where;

	if (me->query_temp("rsg_given") != 1)
	{
		message_vision((string)this_object()->query("name") + "¶Ô×Å$NÀäÀäµØ¿´ÁËÒ»ÑÛ¡£\n", me);
		return;
	}

	if( query_temp("I_am_busy") == 1 )
	{
		message_vision((string)this_object()->query("name") + "¶Ô$NµÀ£ºÎÒÏÖÔÚÕıÃ¦×Å£¬ÄãµÈ»áÔÙÀ´°É¡£\n", me);
		return;
	}

	
	target = find_player(msg);
	if( !target )
	{ 
		message_vision((string)this_object()->query("name") + "¶Ô$NËµµÀ£ººÃÏñÕÒ²»µ½Õâ¸öÈË¡£\n", me);
		return;
	}

	where = environment(target);
	if( !where )
	{ 
		message_vision((string)this_object()->query("name") + "¶Ô$NËµµÀ£ºÕâ¸öÈËÊÇÓĞ£¬µ«ÊÇ¶ãÆğÀ´ÁË¡£\n", me);
		return;
	}

	//now got the target player...
	message_vision((string)this_object()->query("name") + "¶Ô$NËµµÀ£ººÃ£¬Äã¾Í¾²ºò¼ÑÒô°É£¡\n", me);

	me->delete_temp("rsg_given");
	set_temp("I_am_busy", 1);
	set_temp("kill_count", MAX_TRY);

	remove_call_out ("try_kill");
	call_out ("try_kill", 3, msg);
	call_out ("check_finish", 3, msg);
	//note, here we still use target id for future trying...
}

void check_finish(string target_id)
{
	object target;

	//here alway set fali back, since liuer mihou is in a "bian" status...
	if( (int)this_object()->query("mana") < (int)this_object()->query("max_mana") )
		this_object()->set("mana", 2*(int)this_object()->query("max_mana"));

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("check_finish");
		call_out ("check_finish", 15, target_id);//try every 15 second.
		return; 
	}

	if( target->is_ghost() )
	{//means the target is dead.
		//bian back now...
		command("bian");
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		remove_call_out ("try_kill");
		remove_call_out ("check_finish");
		return;
	}
	else
	{
		remove_call_out ("check_finish");
		call_out ("check_finish", 15, target_id);//try every 15 second.
		return; 
	}
}

void  try_kill(string target_id)
{
	object target, where;

	if( (int)query_temp("kill_count") <= 0 )
	{//tried too long
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		return;
	}

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 900, target_id);//try every 15 minutes.
		return; 
	}

	where = environment(target);
	if( !where )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 900, target_id);//try every 15 minutes.
		return; 
	}

	//now kill...
	if( where != environment(this_object()) )
	{
		this_object()->move(where);
		message_vision(YEL "Ö»¼û¼¸µÀ½ğ¹âÂÒ»Î²»Ö¹£¬$NÒ»¸ö½î¶··­ÁË³öÀ´¡£\n" NOR, this_object());
	}
	message_vision(RED "$N×¥¶úÄÓÈùµØ¶Ô$n¼âÉùËµµÀ£ºµ½ÁËÑÖÍõÄÇ¶ùĞİ¹ÖºïÒ¯ÎŞÇé¡£¸óÏÂÒªÊÇÓĞÈË²Î¹ûÎÒÒ»ÑùÄÜÌæÄãÉ±ÈË¡£\n" NOR, this_object(), target);

	if( (int)query_temp("kill_count") == MAX_TRY ) 
	{//first time, always need to initialize kill...
		command("bian " + target_id);
		//this_object()->kill_ob(target);
		//need consider this carefully, is it ok to make safe place unsafe?
		command("kill " + target_id);
	}
	else command("kill " + target_id);
	//problem here, if kill_ob(), may bypass no_fight, ...etc;
	//if kill command, may confuse with NPC of the same name?
	command("follow "+target_id);

	set_temp("kill_count", (int)query_temp("kill_count")-1);

	remove_call_out ("try_kill");
	call_out ("try_kill", 900, target_id);//try every 15 minutes.
}

//LPG 19990925 Õæ¼ÙÃÀºïÍõ

string ask_me()
{
  if (this_player()->query("obstacle/liuer-mihou") == "done" || this_player()->query("obstacle/biqiu") != "done")
return 0;
else
{
	this_player()->set_temp("liuer-mihou_ask","done");
	call_out("autokill",1,this_player(),this_object());
	return "ºÙºÙ";
}
}
void autokill (object me, object who)
{
  message_vision ("$n´óºÈÒ»ÉùÒªÉ±ËÀ$N£¡\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}
void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N´óÅ­£ºÄÄ¸öÆÃÔô×ÓÃ°³äÄã¼ÒºïÒ¯£¡\n",this_player());

  set_temp("my_killer",ob);
  this_player()->kill_ob(me);
}

void unconcious()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object baoguo;
  message_vision(HIY "\n¹ÛÒôÍ»È»´Ó²ÊÔÆ¼äÏÖÉí¡£\n" NOR,me);
  message_vision(HIY "\n¹ÛÒô¶Ô$NÒ»µãÊÖ£¬ÄãÕâºïÍ·£¡\n" NOR,me);
  message_vision(HIY "$N°¥Ñ½Ò»Éù£¬ÏÖÁËÕæÉí¡£\n\n" NOR,me);
  if ((ob) && (ob->query_temp("liuer-mihou_ask") == "done"))
  {
  	ob->set_temp("obstacle/liuer-mihou/liuer-mihou_killed",1);
	message_vision(HIC "¹ÛÒôËµµÀ£ºÕâØËÎÒ´ø×ß£¬Äã°²ĞÄÈ¡¾­È¥°É¡£\n\n" NOR,me);
  	baoguo = new ("/d/obj/misc/baoguo");
  	baoguo -> move(ob);
	message_vision("$NÄÃ³ö¸ö°ü¹ü¡£\n\n",me);
  	call_out ("guan_appearing",1,ob);
  }
  ob->set_temp("liuer-mihou_ask","no");
  message_vision("$Nã¬ã¬µØ×ßÁË¡£\n\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void guan_appearing (object who)
{
  object guan = new ("/d/qujing/mihou/guanyin");
  guan->announce_success (who);
  destruct (guan); 
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}
string ask_cancel()
{
    object me=this_player();
    if("/d/obj/mieyao"->delete_mieyao(me))
    me->add("faith",-5);
    return ("Ã»ÓÃµÄ¶«Î÷£¡");
}

string ask_mieyao()
{
    object me=this_player();

    if(me->query("family/family_name")!="Ë®Á±¶´")
      return ("Äã²»ÊÇ±¾ÃÅÖĞÈË!");
   command("pat "+me->query("id"));
  write(WHT+"/d/obj/mieyao"->query_yao(me)+NOR);
   return "ÓĞÖ¾Æø£¡\n";
}

void attempt_apprentice(object ob)
{
 
        if ((int)ob->query_skill("mihouxinjing",1) <80) {
        command("say ÄãµÄ·¨ÊõÌ«µÍÁË,»¹ÊÇÅ¬Å¬Á¦ÏÈÌá¸ßÒ»ÏÂ°É!");
        command("slap " + ob->query("id"));
                return;
    }
        
        if ((int)ob->query_skill("mihou-force",1) < 80){
        command("say ÄãµÄ±¾ÃÅÄÚ¹¦ĞÄ·¨Ì«µÍÁË,»¹ÊÇÅ¬Å¬Á¦ÏÈÌá¸ßÒ»ÏÂ°É!");
        command("kick2 " + ob->query("id"));                
                return;
    }

    command("say ºÜºÃ£¬ºÜºÃ¡£");
    command("recruit " + ob->query("id"));
}

