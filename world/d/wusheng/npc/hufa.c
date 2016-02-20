// hufa.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIW"»¤·¨×ðÕß"NOR, ({"hufa zunzhe", "zunzhe"}));
       set("long", "ÎäÊ¥ÃÅÊØÅÉ×ðÕß£¬ÃÅÅÉ´óÐ¡ÊÂÎïÎÊËû¶¼ÖªµÀ¡£\n");
       set("title", HIC"ÎäµÛÃÅ"NOR);
       set("gender", "ÄÐÐÔ");
       set("age", 1000);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "»¤·¨");
       set("looking", "Ó¢¿¡äìÈ÷£¬ÓñÊ÷ÁÙ·ç£¬·çÁ÷ÙÃÙÎ¡£");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1000);
       set("max_force", 500);
       set("force_factor", 10);
       set("max_mana", 500);
       set("mana", 1000);
       set("mana_factor", 10);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("feisheng", 300);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("wuying", 300);
        set_skill("fumobashi", 300);  
        set_skill("mizongbu", 100);
        set_skill("stick", 200);
        set_skill("yinglong-stick", 200);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("xiantian", 300);

        map_skill("spells", "feisheng");
      map_skill("stick", "yinglong-stick");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");

	set("inquiry", ([
	"³öÃÅ" : (: expell_me :),
	"leave" : (: expell_me :),
	]) );
	
	create_family("ÎäÊ¥ÃÅ", 1, "»¤·¨");
	
	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
}

string expell_me(object me)
{       
        me=this_player();
        if((string)me->query("family/family_name")=="ÎäÊ¥ÃÅ") {
                message_vision("»¤·¨×ðÕßºú×Ó¶¶¶¶£¬ºÃÏñ·Ç³£ÉúÆø¡£\n", me);
                me->set_temp("betray", 1);
                message_vision("»¤·¨×ðÕß¶Ô$NÈÂÈÂ×Å£ºÐ¡¶«Î÷£¬ÄãËµ»°ÊÇÕæÐÄ»°(true)£¿\n", me);
                return ("ÆøËÀÎÒÁË£¬ÆøËÀÎÒÁË£¡\n");
}
        return ("ÎÊÊ²Ã´ÎÊ£¡×Ô¼ºÏëÈ¥£¡\n");
}
void init()
{     add_action("do_true", "true");
}

int do_true(string arg)
{

        if(this_player()->query("family/family_name") != "ÎäÊ¥ÃÅ" )
                return 0;
        if(this_player()->query_temp("betray")) {
                message_vision("$N´ðµÀ£ºµÜ×Ó½²µÄÕæÐÄ»°£¡\n\n", this_player());
                message_vision("»¤·¨×ðÕßÌ¾ÁË¿ÚÆø£¬¼ÈÊÇÈç´Ë£¬Äã±ãÏÂÉ½°É£¡\n", this_player());
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("feisheng") )
		    this_player()->delete_skill("feisheng");
		if( this_player()->query_skill("xiantian") )
	            this_player()->delete_skill("xiantian");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/wusheng", 1);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙÐÕ");
                this_player()->set("faith",0);
                this_player()->set_temp("betray", 0);
                this_player()->save();
                message_vision("»¤·¨×ðÕßÉì³öÊÖ½«$NÒ»ÍÆ£¬$N»¯×÷Ò»¹ÉÇàÑÌÏò¶«¶øÈ¥ ... \n", this_player());
                this_player()->move("/d/city/center");
                tell_room( environment(this_player()),"Ìì¿ÕÉÏàÛàÛàÂàÂ¼¸ÉùÏì£¬µôÏÂ¸öÈËÀ´£¡\n", ({this_player()}));
                this_player()->unconcious();            
                return 1;
                }
        return 0;
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="ÎäÊ¥ÃÅ") {
	if ((int)ob->query("daoxing") < 1000000 ) {
  	command("say ÎÒÃÇ½µÄ§³ýÑýÖ®ÈË×îÖØµÄ¾ÍÊÇµÀÐÐ£¬" + RANK_D->query_respect(ob) + "»¹Ðè¶à¼ÓÅ¬Á¦²ÅÄÜÔçÎò´óµÀ¡£\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÄãÔø±³ÅÑ¿×Îä´óµÛ£¬±¾»¤·¨×îºÞÏñÄãÕâÑùµÄÈË£¬ÎÒ²»Ô­ÔÙÊÕÄãÎªÍ½ÁË£¡\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 40) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÎòÐÔÌ«µÍ£¬¿ÖÅÂÊÕÁËÄãÒ²ÄÑÓÐ×÷Îª£¡\n");
	command("sigh");
	return;
	}
    if( (int)ob->query_skill("feisheng", 1) < 150 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒ·ÉÉý´ó·¨Áì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say ÀÏ·ò²»ÊÕÍâÃÅµÜ×Ó£¬" + RANK_D->query_respect(ob) + "»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "wusheng");
}

ÿ
