
// ludongbin.c...weiqi, 98.02.24.

string give_book();
string ask_jinguzhou();

inherit NPC;
void create()
{
	set_name("ÂÀ¶´±ö", ({"lu dongbin", "lu", "dongbin"}));
	//set("title", "´¿Ñô×Ó");
	set("gender", "ÄĞĞÔ" );
	set("age", 35);
	set("per", 30);
	set("long", "ÂÀ¶´±ö´ó¸ÅÊÇÕòÔªÃÅÏÂ×î³öÃûµÄµÜ×ÓÁË£¬ÎÄ²É·çÁ÷£¬É«µ¨°üÌì¡£\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 800000);

	set("attitude", "peaceful");
	create_family("Îå×¯¹Û", 3, "µÜ×Ó");
	set_skill("unarmed", 60);
	set_skill("wuxing-quan", 60);
	set_skill("dodge", 80);
	set_skill("baguazhen", 80);
	set_skill("parry", 80);
	set_skill("sword", 90);
	set_skill("sanqing-jian", 100);
	set_skill("force", 70);   
	set_skill("zhenyuan-force", 70);
	set_skill("literate", 120);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "sanqing-jian");
	map_skill("dodge", "baguazhen");

	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	set("inquiry", ([
		"name" : "Îå×¯¹Û´¿Ñô×ÓÊÇÒ²¡£\n",
		"here" : "ÉíÔÚºÎ´¦£¿ĞÄÀÏÆÕÍÓ¡£\n",
		"rumors": (: ask_jinguzhou :),
		"ĞÄµÃ" : (: give_book :),		 
		"´¿ÑôĞÄµÃ" : (: give_book :),
	]) );

	set("no_book", 0);

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="Îå×¯¹Û" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "ÄĞĞÔ" ) command("say Ê¦Êå¼ûĞ¦ÁË¡£\n");
			else command("say Ê¦¹Ã¼ûĞ¦ÁË¡£\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "£¬¸ßÉıÁËÒ²²»ÓÃÏûÇ²ÎÒÂï£¡\n");
		}
		else 
		{
			command("consider");
			command("say ÊÇÄã×Ô¼ºÒª°İµÄ£¬ÄãÊ¦¸¸´òÉÏÃÅÀ´ÎÒ¿ÉµÃÄÃÄãµ²¡£\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say ºÃ£¬ÎÒÎå×¯¹ÛÒ»ÃÅÈË²Å±²³ö£¬Äã¿ÉµÃ¸øÊ¦¸¸ÕùÆø¡£\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}

string give_book()
{
	object me = this_player();

	if( query("no_book") == 0 )
	{
		carry_object("/d/obj/book/chunyang");
		command("give xinde to " + me->query("id"));
		set("no_book", 1);
		return "ÂÀ¶´±öËµµÀ£ººÃ£¡¼ÈÈ»ÊÇÓĞĞÄÈË£¬ÄÇÎÒ¾Í¸øÄã°É¡£\n";
	}
	else
	{
		return "ÂÀ¶´±öËµµÀ£ºÌ«²»ÇÉÁË£¬ÎÒÒÑ¾­ËÍÈËÁË¡£\n";
	}

}

string ask_jinguzhou()
{
	if (this_player() -> query_temp("aware_of_jinguzhou")) 
		return "²»¶¼¶ÔÄãËµÁËÂğ£¬ÔõÃ´ÓÖÀ´ÎÊ£¿\n";
	this_player() -> set_temp("aware_of_jinguzhou", 1);
	command("whisper " + this_player() -> query("id") 
		+ " ÌıËµ×ÏÖñÁÖÀï²ØÓĞÈçÀ´Ëù´ÍµÄ½ô¹¿Öä¡£");
	return "ÓĞÔµÕßµÃÖ®£¬ÎŞÔµÕßÆúÖ®¡£¾Í¿´ÄúµÄ¸£ÆøÁË¡£\n";
}
ÿ