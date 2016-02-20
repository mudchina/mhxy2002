//jiu jianxian-yushu 2000.10.24
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("¾Æ½£ÏÉ", ({"jiu jianxian", "jianxian", "xian"}));
       set("title", "×íÎÌÖ®Òâ²»ÔÚ¾Æ");   
       set("long", "Ò»ÈËÈËËÍÍâºÅ¡°¾Æ½£ÏÉ¡±£¬ĞĞ×Ù²»¶¨£¬»òÓÎÀúÓÚÃûÉ½´ó´¨Ö®ÅÏ£¬»òÒşÄäÓÚ½ÖÍ·ÄÖÊĞÖ®ÖĞ¡£\n");
       set("gender", "ÄĞĞÔ");
       set("age", 68);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("combat_exp", 800000);
       set("daoxing", 800000);
       set("max_kee", 1700);
       set("max_sen", 1700);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 120);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 120);
	set_skill("shushan-force", 160);
       set_skill("songhe-sword", 160);
       set_skill("yujianshu", 160);
       set_skill("sword", 160);
       set_skill("snowwhip", 160);
       set_skill("dodge", 160);
       set_skill("literate", 120);
       set_skill("whip", 160);
       set_skill("force", 160);
       set_skill("parry", 160);
       set_skill("spells", 160);
       set_skill("xianfeng-spells", 160);
       set_skill("zuixian-steps", 160);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "songhe-sword");
	map_skill("sword", "songhe-sword");
       map_skill("force", "shushan-force");
       map_skill("spells", "xianfeng-spells");
            set("inquiry", ([
                "ÏÂÉ½": (: expell_me :),
                "leave": (: expell_me :),
            ]) );

	create_family("ÊñÉ½", 2, "µÜ×Ó");
       setup();
       carry_object("d/obj/cloth/linen")->wear();
       carry_object("d/obj/weapon/sword/qinghong")->wield();
       carry_object("d/qujing/tianzhu/obj/jiuhu");
       carry_object("d/qujing/tianzhu/obj/jiuzhong");
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="ÊñÉ½") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ÄãµÄµÀĞĞ»¹²»¹»£¬" + RANK_D->query_respect(ob) + "»¹Ğè¶à¼ÓÅ¬Á¦²ÅĞĞ¡£\n");
	return;
	}
       if( (int)ob->query_skill("xianfeng-spells", 1) < 120 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÄãµÄÏÉ·çÔÆÌåÊõ»¹²»µ½»ğºò,Äã»¹ÊÇÕÒ×·ÔÆ×ÓËûÃÇÁ·×Å°É!\n");
	command("sigh");
	return;
	}
        command("haha");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£");
        command("recruit " + ob->query("id") );
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
                ob->set("title", "ÊñÉ½ÅÉÕÆÊÂµÜ×Ó");

               } 
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="ÊñÉ½") {
                me->set_temp("betray", 1);
                return ("ÄãÕæµÄÒªÀë¿ªÂğ?ÄãÒª¸¶³öÒ»Ğ©´ú¼Û,Äã¿ÉÔ¸Òâ(agree)?");
        }
        return ("²»Öª¡£");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N´ğµÀ£ºÔ¸Òâ¡£\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/shushan", 1);
		    this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                if( this_player()->query_skill("shushan-force") )
		  this_player()->delete_skill("shushan-force");
                if( this_player()->query_skill("xianfeng-spells") )
		  this_player()->delete_skill("xianfeng-spells");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
                this_player()->save();
                command("say ÄÇÄãÈ¥°É£¡\n");
                return 1;
                }
        return 0;
}


ÿ
