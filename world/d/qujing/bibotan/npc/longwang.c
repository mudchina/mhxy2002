// By tianlin 2001.5.1
//longwang.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("ÍòÊ¥ÁúÍõ", ({"wansheng longwang", "longwang",  "wang", "long"}));
       set("long", "ËûÊÇÂÒÊ¯É½±Ì²¨Ì¶µÄÀÏÁúÍõ\n");
       set("title", "ÂÒÊ¯É½±Ì²¨Ì¶");
       set("gender", "ÄĞĞÔ");
       set("age", 68);
       set("attitude", "peaceful");
       set("gender", "ÄĞĞÔ");
	set("class", "yaomo");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("combat_exp", 3000000);
       set("daoxing", 5000000);
       set("max_kee", 1600);
       set("max_sen", 1600);
       set("force", 5400);
       set("max_force", 3500);
       set("force_factor", 100);
       set("max_mana", 3400);
       set("mana", 5400);
       set("mana_factor", 100);
        set_skill("zhuanlong-force", 180);
       set_skill("unarmed", 180);
       set_skill("dodge", 180);
       set_skill("huaxue-blade", 180);
       set_skill("blade", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("spells", 180);
       set_skill("chuanyun-tui", 180);
       set_skill("literate", 140);
	set_skill("fork", 180);
        set_skill("yueya-fork", 200);
       set_skill("yulong-steps", 180);
        set_skill("bihai-spells", 180);
        map_skill("dodge", "yulong-steps");
	map_skill("blade", "huaxue-blade");
        map_skill("unarmed", "chuanyun-tui");
        map_skill("parry", "yueya-fork");
        map_skill("fork", "yueya-fork");
       map_skill("force", "zhuanlong-force");
       map_skill("spells", "bihai-spells");
	
       create_family("ÂÒÊ¯É½±Ì²¨Ì¶", 1, "×æÊ¦");
       setup();
       carry_object("/d/lingtai/obj/pao")->wear();
       carry_object("/d/obj/weapon/blade/yanblade")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="ÂÒÊ¯É½±Ì²¨Ì¶") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ÄãµÄµÀĞĞ»¹²»¹»£¬" + RANK_D->query_respect(ob) + "»¹Ğè¶à¼ÓÅ¬Á¦²ÅĞĞ¡£\n");
	return;
	}
       if( (int)ob->query_skill("bihai-spells", 1) < 120 ) {
        command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒÅÉµÄ·¨ÊõÁì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say ÀÏ·ò²»ÊÕÍâÃÅµÜ×Ó£¬" + RANK_D->query_respect(ob) + "»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", "±Ì²¨Ì¶ÍòÊ¥ÁúÍõ×ùÏÂµÜ×Ó");

}

        return 0;
}

ÿ
