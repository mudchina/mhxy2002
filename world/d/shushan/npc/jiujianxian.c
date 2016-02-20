//¡¾ÊñÉ½ÅÉ¡¿mhxy-yushu 2001/2
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
   string ask_mieyao();
   string ask_cancel();
string expell_me(object me);
int ask_jiu();
void create()
{
       set_name("¾Æ½£ÏÉ", ({"jiu jianxian", "jianxian", "xian"}));
       set("title", HIC"×íµÀÊ¿"NOR);   
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
        set_skill("shushan-force", 170);
       set_skill("yujianshu", 160);
       set_skill("sword", 160);
       set_skill("unarmed", 150);
       set_skill("fumozhang", 170); 
       set_skill("dodge", 160);
       set_skill("literate", 110);
       set_skill("force", 150);
       set_skill("parry", 250);
       set_skill("spells", 160);
       set_skill("xianfeng-spells", 160);
       set_skill("zuixian-steps", 150);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "shushan-force");
       map_skill("spells", "xianfeng-spells");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
       set("inquiry", ([
                  "ÏÂÉ½": (: expell_me :),
                 "leave": (: expell_me :),
                 "kill" : (: ask_mieyao :),
                 "cancel" : (: ask_cancel :),
                 "¾ÆÉñ" : (: ask_jiu :),

       ]) );
       create_family("ÊñÉ½ÅÉ", 2, "µÜ×Ó");
       setup();
       carry_object("d/obj/cloth/linen")->wear();
       carry_object("d/obj/weapon/sword/qinghong")->wield();
       carry_object("d/qujing/tianzhu/obj/jiuhu");
       carry_object("d/qujing/tianzhu/obj/jiuzhong");
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="ÊñÉ½ÅÉ") {
	if ((int)ob->query("daoxing") < 300000 ) {
  	command("say ÄãµÄµÀĞĞ»¹²»¹»£¬" + RANK_D->query_respect(ob) + "»¹Ğè¶à¼ÓÅ¬Á¦²ÅĞĞ¡£\n");
	return;
	}
       if( (int)ob->query_skill("xianfeng-spells", 1) < 110 ) {
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
                ob->set("title", "ÊñÉ½¾Æ½£ÏÉµÜ×Ó");

               } 
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("Ã»ÓÃµÄ¶«Î÷£¡");
}
else
{
     return ("ÄãÓĞÈÎÎñÂğ£¿£¡");
}
}
string ask_mieyao()
{
   object me=this_player();

    if(me->query("family/family_name")!="ÊñÉ½ÅÉ")
      return ("Äã²»ÊÇ±¾ÃÅÖĞÈË!");

   command("pat "+me->query("id"));
    command("say ÓĞÖ¾Æø£¡");
   return "/d/obj/mieyao"->query_yao(me);
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="ÊñÉ½ÅÉ") {
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

int ask_jiu()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "ÊñÉ½ÅÉ")
    {
    command("say ÄãÓÖ²»ÊÇÊñÉ½ÅÉµÄ£¬Ë­¹ÜÄã£¡");
    return 1;
    }
    if(ob->query("shushan/jiushen_cast"))
    { 
    command("say Äã²»ÊÇÎÊ¹ıÁËÂğ? ");
    return 1;
    }
    if(ob->query("family/master_name") == "¾Æ½£ÏÉ" )
    {
    command("say ÕâÒ»ÕĞ¾ÆÉñ£¬ÊÇÎªÊ¦Î¨Ò»ÄÜ¸øÄãµÄ£¬¾ø²»±ÈÈÎºÎ·¨Êõ²î£¡ËüÓ¦¸Ã¿ÉÒÔ°ïÄã±£ÃüµÄ£¡");
    ob->set("shushan/jiushen_cast",1);
    return 1;
    }
}



ÿ
