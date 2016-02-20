//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ÕÅËÉÏª", ({ "zhang songxi", "zhang" }));
	set("nickname", HIW"Îäµ±"NOR+HIR"ËÄÏÀ"NOR);
	set("long", 
		"Ëû¾ÍÊÇÕÅÈı·áµÄËÄµÜ×ÓÕÅËÉÏª¡£\n"
		"Ëû½ñÄêËÄÊ®Ëê£¬¾«Ã÷ÄÜ¸É£¬ÒÔ×ãÖÇ¶àÄ±Öø³Æ¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 40);
	set("attitude", "peaceful");
	set("class", "wudang");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	
	set("max_kee", 1200);
	set("max_sen", 800);
	set("force", 1500);
	set("max_force", 1500);
	set("mana", 1500);
	set("max_mana", 1500);
       set("force_factor", 100);
       set("mana_factor", 90);
	set("combat_exp", 100000);
	set("daoxing", 100000);

	set_skill("force", 90);
	set_skill("wudang-force", 90);
	set_skill("dodge", 90);
	set_skill("tiyunzong", 90);
	set_skill("unarmed", 90);
	set_skill("taiji-quan", 95);
	set_skill("parry", 95);
	set_skill("sword", 90);
	set_skill("spells", 90);
	set_skill("taiji-jian", 90);
	set_skill("wudang-xianfa", 80);
	set_skill("literate", 90);

	map_skill("force", "wudang-force");
	map_skill("spells", "wudang-xianfa");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("Îäµ±ÅÉ", 2, "µÜ×Ó");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 50000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "ÊÇ·ñ»¹Ó¦ÔÚµÀµÂ¼°Îä¹¦·½Ãæ¶àÏÂÅ¬Á¦£¬À´ÈÕ·½³¤Âğ£¡");
                return;
        }
        if ((int)ob->query_skill("wudang-force", 1) < 30) {
                command("say ÎÒÎäµ±ÅÉÄËÄÚ¼ÒÎä¹¦£¬×îÖØÊÓÄÚ¹¦ĞÄ·¨¡£");
                command("say " + RANK_D->query_respect(ob) +
                        "ÊÇ·ñ»¹Ó¦¸ÃÔÚÌ«¼«Éñ¹¦ÉÏ¶àÏÂµã¹¦·ò£¿");
                return;
        }
        command("say ºÃ°É£¬ÎÒ¾ÍÊÕÏÂÄãÁË¡£");
        command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33mÎäµ±ÅÉ[1;37mµÚ[1;36mÈı[1;37m´úµÜ×Ó[2;37;0m");
}
