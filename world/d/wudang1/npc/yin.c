//[4;53m[1;31mBy tianlin@mhxy and elva@mhxy for 2001.9.27[2;37;0m
//²¿·ÖÓÅ»¯

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ÒóÀæÍ¤", ({ "yin liting","yin"}));
        set("nickname", HIW"Îäµ±"NOR+HIR"ÁùÏÀ"NOR);
        set("long",
                "Ëû¾ÍÊÇÕÅÈı·áµÄ×îÈíÈõµÄµÜ×Ó¡¢Îäµ±ÆßÏÀÖ®ÁùµÄÒóÀæÍ¤¡£\n"
                "Éí´©Ò»¼ş¸É¸É¾»¾»µÄÇà²¼³¤ÉÀ¡£\n"
                "Ëû²»¹ı¶şÊ®³öÍ·Äê¼Í£¬¾«Ã÷ÄÜ¸É£¬¼µ¶ñÈç³ğ£¬ĞÔÈçÁÒ»ğ£¬È´Ò»Ö±Ò»¸±²»Óä¿ìµÄ±íÇé¡£\n");
        set("gender", "ÄĞĞÔ");
        set("age", 23);
        set("attitude", "peaceful");
        set("class", "wudang");
        set("shen_type", 1);
        set("str", 26);
        set("int", 39);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 5000);
        set("max_force", 1000);
        set("mana", 5000);
        set("max_mana", 1000);
       set("force_factor", 50);
       set("mana_factor", 40);
        set("combat_exp", 1250000);
        set("daoxing", 1000000);

        set_skill("force", 195);
        set_skill("wudang-force", 200);
        set_skill("spells", 195);
        set_skill("wudang-xianfa", 170);
        set_skill("dodge", 195);
        set_skill("tiyunzong", 190);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 160);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("liangyi-jian", 200);
        set_skill("literate", 125);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");

        create_family("Îäµ±ÅÉ", 2, "µÜ×Ó");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 100000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "ÊÇ·ñ»¹Ó¦ÔÚµÀµÂ¼°Îä¹¦·½Ãæ¶àÏÂÅ¬Á¦£¬À´ÈÕ·½³¤Âğ£¡");
                return;
        }
        if ((int)ob->query_skill("wudang-force", 1) < 140) {
                command("say ÎÒÎäµ±ÅÉÄËÄÚ¼ÒÎä¹¦£¬×îÖØÊÓÄÚ¹¦ĞÄ·¨¡£");
                command("say " + RANK_D->query_respect(ob) +
                        "ÊÇ·ñ»¹Ó¦¸ÃÔÚÌ«¼«Éñ¹¦ÉÏ¶àÏÂµã¹¦·ò£¿");
                return;
        }
	command("say ºÃ°É£¬¼ÈÈ»" + RANK_D->query_respect(ob) + "Ò²ÊÇ" +
		"ÎÒ±²ÖĞÈË£¬½ñÌì¾ÍÊÕÏÂÄã°É¡£");
	command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33mÎäµ±ÅÉ[1;37mµÚ[1;36mÈı[1;37m´úµÜ×Ó[2;37;0m");
}

