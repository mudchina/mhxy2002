//by tianlin 2001.5.1
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("²Ýïô¾©", ({"caozhi jing", "jing"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 30);
        set("long", "ËûÊÇ°ËÉñâÖµÄËÀµÐ.\n");
        set("combat_exp", 320000);
  set("daoxing", 3200000);

        set("attitude", "friendly");
        create_family("¸ñ¶·Ö®Íõ", 2, "Ê×Í½");
	set("int", 25+random(5));
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 200);  
        set_skill("literate", 10);
        set_skill("dodge", 280);  
        set_skill("force", 280);   

       // map_skill("spells", "dao");
       // map_skill("unarmed", "puti-zhi");
       // map_skill("force", "wuxiangforce");
       // map_skill("stick", "qianjun-bang");
       // map_skill("parry", "qianjun-bang");
       // map_skill("dodge", "jindouyun");


        set("per", 30);
        set("max_kee", 2500);
        set("max_gin", 2400);
        set("max_sen", 2400);
        set("force", 2450);
        set("max_force", 2300);
        set("force_factor", 150);
        set("mana", 2450);
        set("max_mana", 2300);
        set("mana_factor", 108);
//	set("chat_chance_combat", 50);
//	set("chat_msg_combat", ({
	//	(: cast_spell, "thunder" :),
  //      }) );

        setup();
       // carry_object("/d/kof/obj/cloth")->wear();
       // carry_object("/d/kof/obj/bang")->wield();
}
void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("combat_exp") < 100000)) {
	command("say " + RANK_D->query_respect(ob) +
"sigh..sigh..Äã»¹ÊÇÔÙÁ·Á·°É");
	return;
	}
        command("say ºÃ£¬" + RANK_D->query_respect(ob) +
"ÄÇºÃ°É.ÎÒ¾ÍÊÖÏÂÄã.\n");
        command("recruit " + ob->query("id") );
}
// int recruit_apprentice(object ob)
// {
       // if( ::recruit_apprentice(ob) )
               // ob->set("class", "taoist");
// }

ÿ
