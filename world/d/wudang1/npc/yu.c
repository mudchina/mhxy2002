//By tianlin@mhxy for 2001.9.27
//²¿·ÖÓÅ»¯

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao(object me);
string ask_cancel();

void create()
{
	set_name("ÓáÁ«ÖÛ", ({ "yu lianzhou", "yu" }));
	set("nickname", HIW"Îäµ±"NOR+HIR"¶şÏÀ"NOR);
	set("long", 
		"Ëû¾ÍÊÇÕÅÈı·áµÄ¶şµÜ×ÓÓáÁ«ÖÛ¡£\n"
		"Ëû½ñÄêÎåÊ®Ëê£¬Éí²Ä¿ıÎà£¬Æø¶ÈÄıÖØ¡£\n"
		"ËäÔÚÎäµ±ÆßÏÀÖĞÅÅÃûµÚ¶ş£¬¹¦·òÈ´ÊÇ×î¾«¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "wudang");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 3500);
	set("max_sen", 3800);
	set("force", 5000);
	set("max_force", 5000);
	set("mana", 5000);
	set("max_mana", 5000);
       set("force_factor", 140);
       set("mana_factor", 140);
	set("combat_exp", 1800000);
	set("daoxing", 1800000);

	set_skill("force", 210);
	set_skill("wudang-force", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 230);
	set_skill("unarmed", 180);
	set_skill("taiji-quan", 240);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("spells", 200);
	set_skill("taiji-jian", 210);
	set_skill("liangyi-jian", 180);
	set_skill("wudang-xianfa", 200);
	set_skill("literate", 150);

	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
        set("inquiry", ([
      "kill": (: ask_mieyao :),
      "cancel": (: ask_cancel :),
      "·ÅÆú": (: ask_cancel :),
]) );

	create_family("Îäµ±ÅÉ", 2, "µÜ×Ó");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang1/obj/whiterobe")->wear();
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
string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="Îäµ±ÅÉ") {
    tell_room(environment(me),"ÓáÁ«ÖÛ¾ÙÆğÊÖÖĞµÄ³¤½££¬¶ÙÊ±´óºğÒ»Éù¡£\n");
    write(HIY+"/d/obj/mieyao"->query_yao(me)+NOR);
    return (HIG"¼´ÎÒÃÅÈË,µ±³ıÑıÄ§Îª¼ºÈÎ.\n"NOR);
    }
    return ("Æ¶µÀ²»Öª¡£");
}

string ask_cancel()
{
    object me=this_player();
    
    if("/d/obj/mieyao"->delete_mieyao(me))
      me->add("faith",-5);
    return ("Ã»ÓÃµÄ¶«Î÷£¡");
}
