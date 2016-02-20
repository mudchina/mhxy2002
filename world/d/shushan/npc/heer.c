// heer.c...yushu, 2000.10.24.

inherit NPC;
void create()
{
	set_name("º×¶ù", ({"he er", "er", "heer"}));
	//set("title", "");
	set("gender", "ÄÐÐÔ" );
	set("age", 22);
	set("per", 30);
	set("long", "ÊñÉ½ÅÉµÄµÚÈý´úµÜ×Ó¡£\n");
	set("class", "xiake");
	set("combat_exp", 120000);
       set("daoxing", 200000);
       set("attitude", "peaceful");
	create_family("ÊñÉ½ÅÉ", 3, "µÜ×Ó");
	set_skill("dodge", 80);
	set_skill("zuixian-steps", 80);
	set_skill("parry", 80);
	set_skill("sword", 90);
	set_skill("songhe-sword", 80);
	set_skill("force", 80);   
	set_skill("shushan-force", 80);
	set_skill("literate", 110);
	set_skill("spells", 80);
	set_skill("xianfeng-spells", 80);
	map_skill("spells", "xianfeng-spells");
	map_skill("force", "shushan-force");
	map_skill("sword", "songhe-sword");
	map_skill("dodge", "zuixian-steps");
       set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="ÊñÉ½ÅÉ" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "ÄÐÐÔ" ) command("say Ê¦Êå¼ûÐ¦ÁË¡£\n");
			else command("say Ê¦¹Ã¼ûÐ¦ÁË¡£\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "ÄÐÐÔ" ) command("say Ê¦ÐÖÌ«¿ÍÆøÁË¡£\n");
			else command("say Ê¦ÃÃÌ«¿ÍÆøÁË¡£\n");
		}
		else 
		{
			command("consider");
			command("say ÊÇÄã×Ô¼ºÒª°ÝµÄ£¬¿É±ð¹ÖÎÒ°¡!¡£\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say ºÃ£¬ÎÒÊñÉ½ÅÉÅÉÒ»ÃÅÈË²Å±²³ö£¬Äã¿ÉµÃ¸øÊ¦¸¸ÕùÆø¡£\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xiake");
}




ÿ