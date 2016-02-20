//¡¾ÊñÉ½ÅÉ¡¿mhxy-yushu 2001/2
inherit NPC;
inherit F_MASTER;
int ask_back();
int send_back(object me);
#include <ansi.h>
void create()
{
       set_name("¾²ĞéÀÏ×æ", ({"master jingxu","jingxu", "master"}));
       set("title",HIC"ÊñÉ½ÅÉ¿ªÉ½×æÊ¦"NOR);
       set("gender", "ÄĞĞÔ");
       set("age", 220);
	set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏÊ¦×æ");
       set("per", 26);
	set("looking", "ÓñÃæ¶à¹âÈó£¬²Ô÷×ò¢ÏÂÆ®£¬½ğ¾¦·É»ğÑæ£¬³¤Ä¿¹ıÃ¼ÉÒ¡£");
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 8000000);
       set_skill("literate", 160);
       set_skill("dodge", 300);
       set_skill("parry", 300);
       set_skill("unarmed", 290);
       set_skill("fumozhang", 290); 
	set_skill("sword", 300);
	set_skill("songhe-sword", 300);
	set_skill("spells", 300);
	set_skill("xianfeng-spells", 300);
	set_skill("yujianshu", 300);
	set_skill("shushan-force", 300);
	set_skill("force", 300);
       set_skill("zuixian-steps", 300);
       map_skill("force", "shushan-force");
	map_skill("sword", "yujianshu");
       map_skill("spells","xianfeng-spells");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "zuixian-steps");
	map_skill("whip", "snowwhip");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
        set("inquiry", ([
                 "»ØÈ¥" : (: ask_back :),
                 "back" : (: ask_back :),
		         "shushan" : (: send_back :),
				 "ÊñÉ½" : (: send_back :),
         ]) );
        create_family("ÊñÉ½ÅÉ", 1, "µÜ×Ó");
        setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/shushan/obj/shenxue")->wear();
}

void attempt_apprentice(object ob)
{	ob=this_player();
       if( (string)ob->query("family/family_name")=="ÊñÉ½ÅÉ") {
	if ((int)ob->query("daoxing") < 800000 ) {
  	command("say ÄãµÄµÀĞĞ»¹²»¹»£¬¶ÔÎÒµÄÕĞ·¨ÄÑÒÔÁìÎò¡£\n");
	return;
	}
       if( (int)ob->query_skill("xianfeng-spells", 1) < 250 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÄãµÄÏÉ·çÔÆÌåÊõ»¹²»µ½»ğºò,Äã»¹ÊÇÕÒ½£Ê¥ËûÃÇÁ·×Å°É!\n");
	command("sigh");
	return;
	}
       command("smile");
       command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£");
       command("recruit " + ob->query("id") );
       ob->set("shushan/wanjian_perform",1);
       return;
	}
       command("shake");
       command("say ÄãÊÇ±¾ÅÉµÄÂğ?£¬" + RANK_D->query_respect(ob) + "»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "ÊñÉ½¾²ĞéÀÏ×æ´«ÈË");

}

        return 0;
}
int ask_back()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "ÊñÉ½ÅÉ")
    {
    command("say ÄãÓÖ²»ÊÇÊñÉ½ÅÉµÄ£¬ÄãÎÊÕâ¸ö¸ÉÂğ£¡");
    return 1;
    }
    if(ob->query("shushan/tuoqiao_cast"))
    { 
    command("say Äã²»ÊÇÖªµÀÁËÂğ? ");
    return 1;
    }
    if(ob->query("family/master_name") == "¾²ĞéÀÏ×æ" )
    {
    command("say ÄãÏë³öÈ¥°¡£¡ºÃ°É!ÎÒ½ÌÄãÒ»ÕĞ¡¸½ğ²õÍÑ¿Ç¡¹!");
    command("say ÓÃ(cast tuoqiao)¾ÍÄÜ³öÈ¥!");
    command("say ÏÂ´Î½øÀ´Ê±¾Í²»ÒªÄÇÃ´Âé·³ÁË,È¥²Ø¾­¸ó(push Êé¼Ü)¾Í¿ÉÒÔÁË¡£");
    ob->set("shushan/tuoqiao_cast",1);
    return 1;
    }
}
int send_back(object me)
{
	me=this_player();
	command("sigh " + me->query("id"));
	command("say " + "ÓÖÊÇÒ»¸ùÄ¾Í·...ºÃ£¬ÄãÕâ¾ÍÈ¥°É¡£\n");
	tell_object(me,"\n¾²ĞéÀÏ×æÇáÊæ³¤Ğä£¬ÔÚÄãÑÛÇ°Ò»·÷...\n\nÄãÈàÈàÑÛ¾¦£¬ĞÑÁË¹ıÀ´¡£\n\n");
	me->move("/d/shushan/shanmen");
	return 1;
}



ÿ
