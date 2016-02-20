// hexiangu.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
	set_name("ºÎÏÉ¹Ã", ({"he xiangu", "he", "xiangu"}));
	//set("title", "");
	set("gender", "Å®ÐÔ" );
	set("age", 25);
	set("per", 20);
	set("long", "ºÎÏÉ¹ÃÉîµÃÕòÔª´óÏÉÏ²°®£¬¸÷Î»Í¬ÃÅ´ó¶à¸úËý½»ºÃ¡£\nºÎÏÉ¹ÃÔ­ÃûºÎÐã¹Ã£¬¸¸Ç×ÊÇ¿ª¶¹¸¯·»µÄ£¬ËýÍ¶ÈëÎå×¯¹ÛÇ°ÊÇµ±µØÓÐÃûµÄ¡°¶¹¸¯Î÷Ê©¡±¡£\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 200000);

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
	set_skill("literate", 50);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
set_skill("medical",80);
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

	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/sword/snow_sword")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="Îå×¯¹Û" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "ÄÐÐÔ" ) command("say Ê¦Êå¼ûÐ¦ÁË¡£\n");
			else command("say Ê¦¹Ã¼ûÐ¦ÁË¡£\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			command("kick " + ob->query("id") );
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "£¬¸ÒÄÃ¹ÃÄÌÄÌÎÒÀ´ÏûÇ²£¡\n");
		}
		else 
		{
			command("consider");
			command("say ÊÇÄã×Ô¼ºÒª°ÝµÄ£¬ÄãÊ¦¸¸´òÉÏÃÅÀ´ÎÒ¿ÉµÃÄÃÄãµ²¡£\n");
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




ÿ
