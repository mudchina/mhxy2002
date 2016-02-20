//By tianlin@mhxy for 2002.1.2

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
         set_name("¼§ÒØ¿¼", ({ "ji yankao", "yankao", "ji", "kao", "master" }));
             set("title", MAG "ÖĞÌì±±¼«×ÏÎ¢´óµÛ"NOR);   
	set("long", @LONG
Ò»Î»±¥¾­²×É£¾­Àú¹ıĞí¶à·ç·çÓêÓêÔÚ½­ºşÖĞ îú¶ø×ßÏÕµÄÅ®Ç°±²¡£
LONG);
         set("gender", "Å®ĞÔ");
         set("age", 20);
	set("attitude", "heroism");
	set("per", 9);
	set("max_kee", 2850);
	set("max_gin", 2800);
	set("max_sen", 2850);
	set("force", 15400);
	set("max_force", 8000);
	set("force_factor", 50);
	set("max_mana", 5000);
	set("mana", 11300);
	set("mana_factor", 20);
	set("combat_exp", 2330000);
	set("daoxing", 7450000);
       set_skill("literate", 180);
       set_skill("unarmed", 285);
       set_skill("dodge", 285);
       set_skill("force", 285);
       set_skill("parry", 285);
       set_skill("sword", 285);
       set_skill("spells", 285);
       set_skill("whip", 285);
       set_skill("pansi-dafa", 285);
       set_skill("lanhua-shou", 285);
       set_skill("jiuyin-xinjing", 285);
       set_skill("chixin-jian", 285);
       set_skill("qin", 285);
       set_skill("yueying-wubu", 285);
       set_skill("yinsuo-jinling", 285);
       map_skill("spells", "pansi-dafa");
       map_skill("unarmed", "lanhua-shou");
       map_skill("force", "jiuyin-xinjing");
       map_skill("sword", "chixin-jian");
       map_skill("parry", "yinsuo-jinling");
       map_skill("dodge", "yueying-wubu");
       map_skill("whip", "yinsuo-jinling");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
                (: cast_spell, "wuzhishan" :),
                (: cast_spell, "ziqi" :)
	}) );
        create_family("ÅÌË¿¶´ ", 1, "×æÊ¦");
	setup();
	// carry_object("/u/tianlin/zjmaster/putuo/jiasha")->wear();
	// carry_object("/u/tianlin/zjmaster/putuo/staff")->wield();
}
void init ()
{
  add_action("do_back", "back");
}
void attempt_apprentice(object ob)
{
	int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	int i;

         if (((int)ob->query_skill("pansi-dafa", 1) < 200 )) {
                command("say " + RANK_D->query_respect(ob) + "²»ÔÚÎÒÅÉ·¨ÊõÉÏ¿àĞŞ£¬¿ÖÅÂÄÑ³ÉÕı¹û¡£\n");
                return;
        }
  	for (i = 0; i < size; i++)
      	if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
      	{
 	   command("shake");
    	   command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÉĞÎ´Àú¾¡Î÷ĞĞÄÑ¹Ø£¬¿ÖÅÂÄÑÒÔÁìÎò¸ßÉîÎäÑ§¡£\n");
	   return;
      	}
        command("pat " + ob->query("id") );
        command("jump " + ob->query("id") );
         command("say ºÃ£¡Õâ²ÅÊÇÎÒµÄºÃµÜ×Ó¡£Ö»Òª¶à¼ÓÅ¬Á¦£¬¶¨¿ÉÔç³ÉÕı¹û¡£\n");

        command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"¡¾"HIW"Ò¥ÑÔ"HIM"¡¿Ä³ÈË£º"BLINK+HIY+ob->query("name")+NOR+HIM"Î÷ÌìÈ¡¾­¸Ğ»¯ÖÚÉúµÃµ½"NOR+MAG"¼§ÒØ¿¼"HIM"µÄÇ××ÔÖ¸µã£¡\n"NOR,users() );
        return; 
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	      ob->set("class", "xian");
             ob->set("title",MAG"ÅÌË¿¶´"YEL"É¢»¨Õó"CYN"´«ÈË"NOR);
}
int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("33tian/from");

  message_vision("$NÇëÇó$nËÍ$N»Ø·µ¡£\n",who,me);
  there = "/d/city/kezhan";

  message_vision("$NµÄÊÖÕÆÇáÇáÍĞÆğ$nÏòÔ¶·½ÉìÈ¥¡­¡­\n",me,who);
  who->move(there);
  message_vision(HIM"¡­¡­ÔÆÖĞÉì³öÒ»Ö»¾Ş´óµÄ·ğÊÖÇáÇáÒ»·­£¬Ö»¼û$N´ÓÀïÃæÌø³öÀ´¡£\n"NOR,who);
  
  return 1;
}

ÿ
