inherit NPC;
#include <ansi.h>

void create()
{
  set_name("Öí°Ë½ä", ({ "zhu bajie", "zhu", "bajie" }));
  set("age", 70);
  set("title", HIY"ÌìÅîÔªË§"NOR);
    set("gender", "ÄÐÐÔ");
  set("long", "ºÙºÙ£¬Á¬ÀÏÖí¶¼²»ÈÏÊ¶À²£¿\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
       set("class", "xian");
  set("combat_exp", 12000000);
  set("daoxing", 8000000);

  set("max_kee", 3000);
  set("max_sen", 3000);
  set("max_force", 6300);
  set("force", 12600);
  set("max_mana", 6300);
  set("mana", 12600);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 500);
  set_skill("dodge", 500);
  set_skill("parry", 500);
  set_skill("rake", 500);
  set_skill("force", 500);
  set_skill("spells", 500);
  set_skill("xbuddhism", 500);
  set_skill("yanxing-steps", 500);
  set_skill("skyriver-rake", 500);
  set_skill("sougu-zhua", 500);
  map_skill("unarmed", "sougu-zhua");
  map_skill("force", "lengquan-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("chat_chance",5);
  set("chat_msg",({
    "Öí°Ë½äÀÖºÇºÇµØËµµÀ£ºË­ÄÜ¸ø°³ÀÏÖíÈ¥ÕÒµã³ÔµÄ¶«Î÷À´¡£\n",
    "Öí°Ë½äÏëÏëËµ£ºÏçÏÂ·¢´óË®ÔÖÁË£¬ÀÏÖí¸Ãµ±¾È¼Ã¼¢Ãñ¡£\n",
    "Öí°Ë½äËµµÀ£ºÀÏÖíÒªÑ°±éÌìÏÂÃÀ¾Æ¼ÑëÈ£¬ÔÙÇëÊÀÈËÀ´°³Ë§¸®Æ·³¢Æ·³¢¡£\n",
    "Öí°Ë½äËµµÀ£º²»ÊÇÀÏÖíÌ°×ì£¬°³ÀÏÖíÏë´Õ¸öÃÀÑç£¬ÇëÆ½Ãñ°ÙÐÕÒ²ÄÜ³¢¸öÐÂÏÊ¡£\n",
    "Öí°Ë½ä×ÔÑÔ×ÔÓïµØËµ£º°³ÀÏÖí²»ÊÇÎª×Ô¼º£¬ÀÏÖíÏëÊÕ¼¯ÊÀÉÏÃÀÊ³£¬ÈÃ´óÌÆÈË¶¼ÄÜÀ´³¢³¢¡£\n",
    "Öí°Ë½äÅ¤¹ýÉíÈ¥ÅõÆðÔèÅè´óµÄ½ð·¹Åè°Éàª°Éàª´ó½ÀÁËÆðÀ´¡£\n",
    "Öí°Ë½äÍäÑüÅõÆðË®Í°´óµÄÒø¾Æºø¹¾ßË¹¾ßËµØ¹àÁËÏÂÈ¥¡£\n",
  }));
  set("inquiry", ([
        "here":   "´ËÄËÌìÅîË§¸®Ò²£¬ÀÏÖíÎ÷Ìì¹éÀ´ºóÌÆÌ«×ÚÓù´ÍÔÚ´Ë¿ª¸®£¬×¨ÊÂÒûÊ³´ÈÉÆÒµ¡£\n",
        "name":   "Öí°Ë½ä£¬Ë­ÈË²»ÖªÒ²¡£\n",
     ]));
   create_family("ÌìÅî¸®", 1, "À¶");
  setup();
  carry_object("/d/tianpeng/obj/tianpengpa")->wield();
  carry_object("/clone/armor/jinjia")->wear();
}
void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 3000000 )) {
	command("say " + RANK_D->query_respect(ob) +
                          "µÄµÀÐÐ²»¹»¸ßÉî£¬ÓÐÐ©¾øÑ§ÃØ·¨¿ÖÅÂÄÑÒÔÁìÎò¡£\n");
	return;
	}

	if ( (string)ob->query("family/family_name")=="ÌìÅî¸®") {
        command("pat "+ob->query("id"));
        command("say ºÃ£¬Ï£Íû" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬°ÑÎÒÃÇÌìÅî¸®·¢Ñï¹â´ó¡£\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"»¹ÊÇÏÈÈ¥Ñ§Ð©»ù´¡¹¦·ò°É¡£\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )                                                                                                                                                                                                     
                ob->set("class", "xian");
                ob->set("per","11");
}
ÿ


ÿ
