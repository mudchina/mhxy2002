// by gslxz@mhsj 2001/11/21 (ÓÅ»¯)
inherit NPC;
#include <ansi.h>

void create()
{
  set_name("Öí´ó³£", ({ "zhu dachang", "zhu", "dachang" }));
  set("age", 600);
  set("title", HIY"ÌìÅî¸®»¤ÔºÍ³Áì"NOR);
    set("gender", "ÄÐÐÔ");
  set("long", "Ëû¾ÍÊÇÌìÅî¸®µÄ»¤ÔºÍ³Áì¡£\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 15);
  set("combat_exp", 2000000);
  set("daoxing", 1900000);

  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_mana", 2700);
  set("mana", 3700);
  set("max_force", 2700);
  set("force", 3700);
  set("force_factor", 90);
  set("mana_factor", 90);
  set_skill("rake", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("force", 210);
  set_skill("spells", 200);
  set_skill("xbuddhism", 205);
    set_skill("tianpeng-force", 205);
  set_skill("yanxing-steps", 200);
  set_skill("skyriver-rake", 205);
  map_skill("rake", "skyriver-rake");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
   create_family("ÌìÅî¸®", 3, "µÜ×Ó");
  setup();
  carry_object("/d/tianpeng/obj/jinjia")->wear();
  carry_object("/d/tianpeng/obj/gangpa")->wield();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 500000 )) {
	command("say " + RANK_D->query_respect(ob) +
                          "µÄµÀÐÐ²»¹»¸ßÉî£¬ÓÐÐ©¾øÑ§ÃØ·¨¿ÖÅÂÄÑÒÔÁìÎò¡£\n");
	return;
	}

	if ( (string)ob->query("family/family_name")=="ÌìÅî¸®") {
        command("pat "+ob->query("id"));
        command("say ºÃ£¬Ï£Íû" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬°ÑÎÒÃÇÌìÅî¸®·¢Ñï¹â´ó¡£\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"»¹ÊÇÏÈÈ¥Ñ§Ð©»ù´¡¹¦·ò°É¡£\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )                                                                                                                                                                                                     
                ob->set("class", "xian");
                ob->set("per",11);
}
ÿ


ÿ
