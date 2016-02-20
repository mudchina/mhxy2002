// by gslxz@mhsj 2001/11/21 (ÓÅ»¯)
inherit NPC;
#include <ansi.h>

void create()
{
    set_name("´äÀ¼", ({ "cui lan","lan" }));
  set("age", 20);
  set("title", HIM"¸ßÀÏ×¯ÈýÐ¡½ã"NOR);
    set("gender", "Å®ÐÔ");
  set("long", "Ëý¾ÍÊÇ¸ßÀÏ×¯µÄÈýÐ¡½ã¡£\n");
  set("attitude", "peaceful");
       set("class", "xian");
  set("str", 50);
  set("per", 30);
  set("combat_exp", 3800000);
  set("daoxing", 2570000);

  set("max_kee", 2500);
  set("max_sen", 2500);
  set("max_mana", 3000);
  set("mana", 6000);
  set("max_force", 3000);
  set("force", 6000);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 450);
  set_skill("dodge", 450);
  set_skill("parry", 430);
  set_skill("rake", 450);
  set_skill("force", 450);
  set_skill("spells", 450);
  set_skill("xbuddhism", 470);
    set_skill("tianpeng-force", 470);
  set_skill("literate", 400);
  set_skill("yanxing-steps", 430);
  set_skill("skyriver-rake", 450);
  set_skill("sougu-zhua", 430);
  map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
   create_family("ÌìÅî¸®", 2, "µÜ×Ó");
  setup();
    carry_object("/d/tianpeng/obj/yupa")->wield();
  carry_object("/d/tianpeng/obj/pink")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 1000000 )) {
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
