//By tianlin@mhxy for 2002.2.25

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
       set_name("Ú¤Íõ", ({ "ming wang", "wang", "mingwang" }));

       set("long","µØ²ØÆÐÈøÊ¦µÜ,²»ÂúµØ²Ø³çÉÐ·ðÑ§,³¤ÆÚ¾ÓÓÚÛº¶¼³ÇÍâ.\n");
       set("attitude", "peaceful");
	set("per", 30);
	set("str", 35);
	set("int", 25);
       set("age", 30);
	set("title", HIB"Òõ²ÜµØ¸®"NOR);
	set("nickname", HBRED+HIY"Ú¤½çÖ®Éñ"NOR);
       set("nkgain",790);
       set("max_kee", 3000);
       set("max_gin", 2500);
       set("max_sen", 2000);

       set("force", 7500);
       set("max_force", 4200);
       set("force_factor", 200);
       set("max_mana", 4500);
       set("mana", 8000);
       set("mana_factor", 200);

       set("combat_exp", 5000000);
       set("daoxing", 6000000);

       set_skill("stick", 285);
       set_skill("kusang-bang", 285);
       set_skill("unarmed", 285);
       set_skill("whip", 285);
       set_skill("hellfire-whip", 285);
       set_skill("dodge", 285);
       set_skill("parry", 285);
       set_skill("literate", 180);
       set_skill("spells", 285);
       set_skill("force", 285);
       set_skill("tonsillit", 285);
       set_skill("ghost-steps", 285);
       set_skill("gouhunshu", 285);
       set_skill("jinghun-zhang", 285);
       set_skill("zhuihun-sword", 285);
       set_skill("sword", 285);

	map_skill("stick","kusang-bang");
	map_skill("parry", "kusang-bang");
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
       set("chat_chance_combat", 40);
       set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "sheqi" :),
                (: cast_spell, "gouhun" :),
       }) );


       set("nkgain", 400);

	set_temp("apply/dodge", 150);
	set_temp("apply/armor", 150);


create_family("ÑÖÂÞµØ¸®", 1, "ÄãºÃ");

       setup();
	carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
	carry_object("/d/obj/cloth/taijicloth")->wear();
}


void attempt_apprentice(object ob)
{
		int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	int i;
  	for (i = 0; i < size; i++)
      	if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
      	{
 	   command("shake");
    	   command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÉÐÎ´Àú¾¡Î÷ÐÐÄÑ¹Ø£¬¿ÖÅÂÄÑÒÔÁìÎò¸ßÉîÎäÑ§¡£\n");
	   return;
      	}
        command("grin");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
       command("recruit " + ob->query("id") );
	//me->set("class", "youling");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
              ob->set("class", "youling");
		ob->set("title", HIB"Òõ²ÜµØ¸®"NOR+HBBLU+HIR"Ú¤Íõ×ùÏÂµÜ×Ó"NOR);
}


ÿ
