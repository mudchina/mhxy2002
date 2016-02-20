//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("³ÕÃÎÏÉ¹Ã",({"chi meng","dream", "fairy"}));
       set("long",
"´ËÄËÃÔ½ò³ÕÃÎÏÉ¹ÃÒ²£»²»ÊÜ½ðÒøÖ®Ð»£¬µ«ÓöÓÐÔµÕß¶ÉÖ®£¡\n");
       set("title", "ÃÔ½ò¶ÉÕß");
       set("gender", "Å®ÐÔ");
       set("age", 18);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "ÏÉ¹Ã");
       set("per", 30);
	set("int", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 40);
       set("combat_exp", 1000000);
  set("daoxing", 500000);


        set("eff_dx", 100000);
        set("nkgain", 300);

       set_skill("literate", 90);
       set_skill("unarmed", 80);
       set_skill("dodge", 100);
       set_skill("force", 120);
       set_skill("whip", 180);
       set_skill("unarmed", 80);
       set_skill("spells", 120);
       set_skill("baihua-zhang", 120);
        set_skill("moonshentong",140);
        set_skill("jueqingbian", 180);
        set_skill("moonforce", 120);
        set_skill("moondance", 100);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("whip", "jueqingbian");
        map_skill("parry", "jueqingbian");
        map_skill("dodge", "moondance");

create_family("ÔÂ¹¬", 2, "µÜ×Ó");
setup();

        carry_object("/d/obj/cloth/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Å®ÐÔ")){
           command("shake");
           command("say ÎÒÃÇÔÂ¹¬Ö»ÊÕÅ®Í½£¬ÕâÎ»" +
RANK_D->query_respect(ob) + "»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
           return ;
        }
	if ((random(this_player()->query_kar()) < 20 || 
            this_player()->query("mark/moon_chimeng")) && 
            ((string)this_player()->query("zhangmen/base_name") 
             != "/d/moon/npc/zhangmen")) 
        {

	  this_player()->set("mark/moon_chimeng", 1);
	  command("shake");
	  command("say ÄãÎÒÎÞÔµ£¬»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
	  return ;
	}
        else{
	command("pat "+ob->query("id"));
        command("say ¼ÈÈ»" + RANK_D->query_respect(ob) +
"ÓëÎÒÓÐÔµ£¬ÎÒ¾ÍÊÕÏÂÄãÁË¡£\n");
        command("recruit " + ob->query("id") );
        message("system", HIY"ÔÂ¹¬ÓÖ¶àÁËÒ»¸öµÜ×Ó  "+this_player()->name()+HIW"
                     ÔÂ¹¬µÄÊÆÁ¦¼ÓÇ¿ÁË¡£\n"NOR,users());
        return ;}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}


ÿ
