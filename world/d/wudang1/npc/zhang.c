//By tianlin@mhxy and elva@mhxy for 2001.9.27
//²¿·ÖÓÅ»¯

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ÕÅÈı·á", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "[1;37mÌ«¼«[1;33mÕæÈË[2;37;0m");
	set("long", 
		"Ëû¾ÍÊÇÎäµ±ÅÉ¿ªÉ½±Ç×æ¡¢µ±½ñÎäÁÖµÄÌ©É½±±¶·ÕÅÈı·áÕæÈË¡£\n"
		"Éí´©Ò»¼şÎÛ»àµÄ»ÒÉ«µÀÅÛ£¬²»ĞŞ±ß·ù¡£\n"
		"Éí²Ä¸ß´ó£¬ÄêÂú°ÙËê£¬ÂúÁ³ºì¹â£¬ĞëÃ¼½Ô°×¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_kee", 3000);
	set("max_sen", 2800);
	set("force", 5700);
	set("max_force", 5700);
	set("mana", 4900);
	set("max_mana", 4900);
       set("force_factor", 140);
       set("mana_factor", 140);
	set("combat_exp", 5000000);
	set("daoxing", 6000000);
        set("chat_msg_combat", ({
 //               (: perform_action, "sword.ren" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
	set_skill("force", 300);
	set_skill("wudang-force", 300);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 300);
	set_skill("taiji-quan", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 300);
	set_skill("wudang-xianfa", 300);
	set_skill("spells", 300);
	set_skill("literate", 290);

	map_skill("force", "wudang-force");
	map_skill("spells", "wudang-xianfa");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");

	create_family("Îäµ±ÅÉ", 1, "¿ªÉ½×æÊ¦");
	set("class", "wudang");

	setup();
       carry_object("/d/wudang1/obj/jian.c")->wield();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 500000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "ÊÇ·ñ»¹Ó¦ÔÚµÀµÂ¼°Îä¹¦·½Ãæ¶àÏÂÅ¬Á¦£¬À´ÈÕ·½³¤Âğ£¡");
                return;
        }
        if ( ((int)ob->query("daoxing") < 500000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "ÊÇ·ñ»¹Ó¦ÔÚµÀĞĞ·½Ãæ¶àÏÂÅ¬Á¦°¡£¡");
                return;
        }
	if ((int)ob->query_skill("wudang-force", 1) < 200) {
		command("say ÎÒÎäµ±ÅÉÄËÄÚ¼ÒÎä¹¦£¬×îÖØÊÓÄÚ¹¦ĞÄ·¨¡£"); 
		command("say " + RANK_D->query_respect(ob) + 
			"ÊÇ·ñ»¹Ó¦¸ÃÔÚÌ«¼«Éñ¹¦ÉÏ¶àÏÂµã¹¦·ò£¿");
		return;
	}
    if ((int)ob->query_skill("wudang-xianfa", 1) < 200)
    {
        command("say ÎÒÎäµ±ÅÉÄËµÀ¼ÒÎä¹¦£¬¸ßÉîµÄÎä¹¦Àë²»¿ªµÀÑ§ĞÄ·¨¡£");
        command("say " + RANK_D->query_respect(ob) +
            "ÊÇ·ñ»¹Ó¦¸Ã¶à¶Á¶ÁµÀµÂ¾­£¿");
        return;
    }
	if (ob->query_int() < 30) {
		command("say ÎÒÎäµ±ÅÉÎä¹¦È«´ÓµÀ²ØÎò³ö¡£");
		command("say ÒªÄÜ´ïµ½Â¯»ğ´¿ÇàÖ®¾³£¬ÌåÖÊÊ²Ã´µÄµ¹ÊÇÎŞ¹Ø½ôÒª£¬ÎòĞÔÈ´ÊÇ°ëµãÒ²Âí»¢²»µÃ¡£");
		command("say " + RANK_D->query_respect(ob) + "µÄÎòĞÔ»¹´óÓĞÇ±Á¦¿ÉÍÚ£¬»¹ÊÇÇë»Ø°É¡£");
		return;
	}
	command("chat ¹ş¹ş¹ş¹ş£¡£¡£¡£¡");
	command("chat Ïë²»µ½ÀÏµÀÔÚ´¹ËÀÖ®Äê£¬ÓÖÃÙµÃÒ»¸ö¿ÉËÜÖ®²Å£¬ÕæÊÇ¿ÉÏ²¿ÉºØ¡£");
	command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33mÎäµ±ÅÉ[1;37mÕÅÈı·á[1;31mÃÅÏÂ[1;37mµÜ×Ó[2;37;0m");
}
