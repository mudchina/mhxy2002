// laozhang.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ÀÏÕÅ", ({ "lao zhang", "zhang", "lao" }));
	set("long", 
		"ËûÊÇÌìÅô¸®µÄ¹Ü¼Ò¡£\n");
          set("title", YEL"ÌìÅô¸®¹Ü¼Ò"NOR);
	set("gender", "ÄÐÐÔ");
       set("class", "xian");
	set("age", 55);
	set("attitude", "peaceful");
	set("per", 16);

	set("str", 20);

	set("combat_exp", 115763);
	set("daoxing", 500000);
	set("max_force", 1500);
       set("force", 1500);
       set("max_mana", 1500);
       set("mana", 1500);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("spells", 60);
	set_skill("tianpeng-force", 60);
	set_skill("xbuddhism", 60);
	set_skill("sougu-zhua", 60);
	set_skill("rake", 60);
	set_skill("yanxing-steps", 60);
	set_skill("skyriver-rake", 60);
	set_skill("unarmed", 60);	
	set_skill("parry", 60);
	set_skill("literate", 30);
	map_skill("rake", "skyriver-rake");
	map_skill("parry", "sougu-zhua");
	map_skill("unarmed", "sougu-zhua");
	map_skill("force", "tianpeng-force");
	map_skill("spells", "xbuddhism");
	map_skill("dodge", "yanxing-steps");

	create_family("ÌìÅô¸®", 3, "µÜ×Ó");

	setup();
	
           carry_object("/d/tianpeng/obj/gangpa")->wield();
           carry_object("/d/tianpeng/obj/choupao")->wear();
}
void attempt_apprentice(object ob)
{
        command("pat "+ob->query("id"));
        command("say ºÃ£¬Ï£Íû" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬°ÑÎÒÃÇÌìÅô¸®·¢Ñï¹â´ó¡£\n");
        message("shout", HIW"¡¼"HIC"ÃÅÅÉÏûÏ¢"HIW"¡½£º"HIY"ÌìÅô¸®"NOR+WHT"ÓÖ¶àÁËÒ»¸öµÜ×Ó"+YEL+this_player()->name()+NOR+WHT"ÌìÅô¸®µÄÊÆÁ¦¼ÓÇ¿ÁË¡£\n"NOR,users());
 command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )                                                                                                                                                                                                     
               ob->set("class","xian");
                ob->set("per",11);
}
ÿ
