// zhangguolao.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
	set_name("ÕÅ¹ûÀÏ", ({"zhang guolao", "zhang", "guolao"}));
	//set("title", "");
	set("gender", "ÄÐÐÔ" );
	set("age", 50);
	set("per", 20);
	set("long", "Ò»Î»Ð¦ÎûÎûµÄ»¬»üÀÏÍ·¡£\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 500000);

	set("attitude", "peaceful");
	create_family("Îå×¯¹Û", 3, "µÜ×Ó");
	set_skill("unarmed", 60);
	set_skill("wuxing-quan", 60);
	set_skill("dodge", 80);
	set_skill("baguazhen", 70);
	set_skill("parry", 80);
	set_skill("hammer", 90);
	set_skill("kaishan-chui", 100);
	set_skill("force", 70);   
	set_skill("zhenyuan-force", 70);
	set_skill("literate", 50);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("hammer", "kaishan-chui");
	map_skill("dodge", "baguazhen");

	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	set("maolu", 0);

	setup();
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/cloth/pobuxie")->wear();
	carry_object("/d/obj/weapon/hammer/jiuhulu")->wield();
}

void init()
{       
	object ob=this_player();
	object me=this_object();

	::init();

	set("chat_chance", 10);
	set("inquiry", ([
		"name" : "ºÇºÇ£¡ÕÅ¹ûÀÏÊÇÒ²¡£\n",
		"here" : "½ñ¶ù¸ö×íÁË£¬»¹Õæ±»ÄãÎÊµ¹ÁË¡£\n",
	 ]) );

	set("chat_msg", ({
		"ÕÅ¹ûÀÏÎûÎûÎûµØÐ¦ÁË¼¸Éù¡£\n",	
		"ÕÅ¹ûÀÏÄÃÆð¾ÆºùÂ«ÓÖ¹àÁËÒ»¿Ú£¬ÂúÒâµØßÆÁËßÆ×ì¡£\n",
		"ÕÅ¹ûÀÏ´òÁË¸öÏìÖ¸£º¹þ¹þ£¬ÎÒµÄÐ¡Ã«Â¿¾ÍÊÇÌý»°¡£\n",
		(: random_move :)
	}) );

	if( query("maolu") == 0 )
	{
		call_out("qi_maolu", 1);
		set("maolu", 1);
	}

}

void qi_maolu()
{
	object maolu;

        	maolu = new(__DIR__"xiaomaolu.c");
        	maolu->move( environment(this_object()) );
	command("mount maolu");
	return;	
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
			if ( (string)ob->query("gender") == "ÄÐÐÔ" ) command("say Ê¦ÐÖÌ«¿ÍÆøÁË¡£\n");
			else command("say Ê¦ÃÃÌ«¿ÍÆøÁË¡£\n");
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
		command("say ºÃ£¬ºÃºÃ¸É£¬ÕÅ¹ûÀÏ²»ÐÐ£¬Í½µÜ¿É²»ÄÜ²îÁË¡£\n");
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