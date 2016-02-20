// qinger.c...yushu, 2000.10.24.

inherit NPC;
void create()
{
	set_name("Çà¶ù", ({"qing er", "er", "qinger"}));
	//set("title", "");
	set("gender", "Å®ÐÔ" );
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
	set_skill("whip", 90);
	set_skill("snowwhip", 80);
	set_skill("force", 80);   
	set_skill("shushan-force", 80);
	set_skill("literate", 100);
	set_skill("spells", 80);
	set_skill("xianfeng-spells", 80);
	map_skill("spells", "xianfeng-spells");
	map_skill("force", "shushan-force");
	map_skill("whip", "snowwhip");
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
	carry_object("d/obj/weapon/whip/whip")->wield();
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
			command("xixi");
			command("say ÄãºÃÓÐÈ¤Å¶!\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say ºÃ£¬ÎÒÊñÉ½ÅÉÒ»ÃÅÈË²Å±²³ö£¬Äã¿ÉµÃ¸øÊ¦¸¸ÕùÆø¡£\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xiake");
}

void init()
{
::init();
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
        object m,mm;
        message_vision("$NÏòÇà¶ùÎÊµÀ£ºÇà¶ù£¬¿ª·¹ÁËÂð£¿\n", this_player());

        if((int)this_player()->query("food") >=
             (int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("Çà¶ùÐ¦µÀ£º¶öÀ²£¬»¹Ã»×öºÃÄØ£¡\n");

        if((present("gongbao jiding", this_player())))
        return notify_fail("Çà¶ùÐ¦µÀ£º²»ÒªÄÃ×ÅÊÖÀïµÄ£¬»¹¿´×Å¹øÀïµÄ! ²ö¹í!\n");
	
	 if ( present("gongbao jiding", environment()) )
         return notify_fail("Çà¶ùÐ¦µÀ£ºÄÇ²»ÊÇÓÐÒ»ÅÌÂï£¬³ÔÍêÔÙËµ£¡\n");

        m=new("d/obj/food/dishes/dish10");
        mm=new("d/obj/food/dishes/dish10");


        m->move(this_player());
        mm->move(this_player());
             
        command("snicker");
        message_vision("Çà¶ù¶Ô$NÐ¦µÀ£º¶öÁË°É£¬Âýµã³Ô£¬Ð¡²ö¹í!\n", this_player());
        return 1;
}





ÿ