inherit NPC;
#include <ansi.h>

#include <quest_fd.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("Öí°Ë½ä", ({ "zhu bajie", "zhu", "bajie" }));
  set("age", 70);
    set("title", HIW"ÌìÅî¸®×æÊ¦Ò¯"NOR);
    set("nickname", HIY"ÌìÅîÔªË§"NOR);
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
    set_skill("tianpeng-force", 500);
  set_skill("spells", 500);
  set_skill("xbuddhism", 500);
  set_skill("yanxing-steps", 500);
  set_skill("skyriver-rake", 500);
  set_skill("sougu-zhua", 500);
  map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
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
             "food":   (: test_player() :),
        "ÃÀÊ³":   (: test_player() :),
        "ÃÀ¾Æ":   (: test_player() :),
        "ÃÀÑç":   (: test_player() :),
        "¼ÑëÈ":   (: test_player() :),
        "Ê³Îï":   (: test_player() :),
        "ÒûË®":   (: test_player() :),
        "³Ô":   (: test_player() :),
        "ºÈ":   (: test_player() :),
]));
   create_family("ÌìÅî¸®", 1, "À¶");
  setup();
  carry_object("/d/tianpeng/obj/tianpengpa")->wield();
  carry_object("/clone/armor/jinjia")->wear();
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
                ob->set("per",11);
}
void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$NÂÔÓÐËùË¼µØµãµãÍ·¶Ô$nËµµÀ£º°³ÀÏÖíÏë¸ø´óÌÆÈË´Õ¸öÃÀÑç£¬ÕýÈ±",
    "$N¶Ô$nËµµÀ£ºÀÏÖíÎÒËÄ´¦Ñ°ÇóÌìÏÂÃÀÎ¶¼ÑëÈ£¬ÕýÒªÕÒ",
    "$N¶Ô$nËµµÀ£º¶ÔÁËÏçÏÂ·¢´óË®ÔÖ£¬ÓÐ¼¸¸öÔÖÃñÏëÒªÊ²Ã´",
    "$N¶Ô$nËµµÀ£º¾©³Ç¿Íµ½£¬ÔÚ¿ª·â¸®ÉÏ£¬ÆäÖÐÓÐÒ»¹ÙÈËÈÃÀÏÖíÎÒ´úÑ°Ê²Ã´",
    "$N¶Ô$nµãÍ·ËµµÀ£ºË®Â½´ó»á¼´½«¿ªÑçÇë¸÷Â··¨Ê¦µ½»á£¬ÌýËµÓÐ·¨Ê¦ÏëÒªÊ²Ã´",
    "$N¶Ô$nÒ»µãÍ·ËµµÀ£º°³ÀÏÖí¾È¼Ã¼¢Ãñ£¬ÌýËµÕýÐèÒª",
    "$NÏëÏëËµ£ºÓÐÈËµ¹ÊÇÏëÈÃ°³ÀÏÖí¸øÕÒ¸öÊ²Ã´Ê²Ã´",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  string *quest;
  int delay;
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬°³¼ûÄãÉíÉÏÏéÔÆ»·ÈÆ£¬ºÎ²»È¥´ÓËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¿\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/food"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬°³»¹µÈ×ÅÇëÄú°ïÃ¦ÕÒµÄ"+
		    who->query("quest/pending/food/name")+"ÄØ£¡\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_food);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/food");
  if (i == -1)
  {
    message_vision ("$N¶Ô$nÌ¾ÆøËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "¸Ã×öµÄÊÂ×öÁË²»ÉÙ£¬°³¿´Äú»¹ÊÇÒÔºóÔÙÀ´°É¡£\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_food[quest_keys[i]];
  who->set("quest/pending/food/index", i);
  who->set("quest/pending/food/daoxing", quest_keys[i]);
  who->set("quest/pending/food/name", quest[IDX_NAME]);
  who->set("quest/pending/food/id", quest[IDX_ID]);
  who->set("quest/pending/food/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "£¬\nÕâÎ»"+RANK_D->query_respect(who)+
        "¿É·ñÉÍÀÏÖí¸ö´óÁ³Éè·¨×ÓÈ¥¸øÅªÀ´£¿\n";
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  object ob;

  if (!who || !visible(who))
      return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "ÉíÉÏÏéÔÆ»·ÈÆ£¬ÇëËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¡\n",me,who);
    return;
  }

  if (! who->query("quest/pending/food"))
    return;

  ob = present (who->query("quest/pending/food/id"),who);
  if (! ob)
    return;
  if (! ob->query("no_give"))
    return;

  if (who->query("quest/pending/food/name") != ob->query("name"))
    return;

  message_vision ("$N¼û$nÊÖÉÏÄÃ×Å"+ob->query("name")+"£¬±ã¸Ï½ôÉìÊÖ½Ó¹ýÈ¥¡£\n",me,who);
  rewarding (who, ob);
  destruct (ob);
}

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

/*
  if (! ob->query("food_remaining") &&
      ! ob->query("liquid/remaining"))
  {
     message_vision ("$NÒ¡Ò¡Í·£º°³ÀÏÖíÏÖÔÚÖ»ÐëÒª³ÔµÄºÈµÄ¡£\n",me);
     return 0;
  }
*/

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬°³¼ûÄãÉíÉÏÏéÔÆ»·ÈÆ£¬ºÎ²»È¥´ÓËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¿\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/food"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÄú¸øÀÏÖíÕâ¸ÉÊ²Ã´£¿°³ÀÏÖí¾¡¹ÜÌ°×ìÒ²²»ÊÜ²»ÒåÖ®²ÆÒ²¡£\n",me,who);
    return 0;
  }

  if(ob->is_character()) return 0;

  if (who->query("quest/pending/food/name") != ob->query("name"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬°³µÈ×ÅÇëÄú°ïÃ¦ÕÒµÄ"+
		    who->query("quest/pending/food/name")+
                    "£¬ÄúÈ´¸ø°³"+ob->query("name")+"£¬Õâ¡­¡­\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/food/id") != ob->query("id"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬°³µÈ×ÅÄúµÄ"+who->query("quest/pending/food/name")+
                    "£¬¶«Î÷µ¹Í¦Ïó£¬µ«²»ÊÇÍ¬Ò»¸ö»õ£»°³ÒªµÄÊÇ("+
                    who->query("quest/pending/food/id")+")£¬Äú¸øµÄÊÇ("+
                    ob->query("id")+")£¡\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/food/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N¶Ô$nÒ¡Í·µÀ£ºÕâÃ´¿ì¾Í»ØÀ´ÁË£¿°³ÀÏÖí²»Òª¼Ù»õ¡£\n",me,who);
    message_vision ("$NÓÖ·Ô¸ÀµÀ£ºÄúÔÙ»¨¸ö"+chinese_number((t-uptime())/60+1)+
                    "·ÖÖÓÈ¥Ñ°Ñ°¡£\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: ÈÃÀÏÖíÒªÏÂ¶«Î÷¡£\n");
  }
  rewarding (who, ob);
  call_out ("destruct_ob",1,ob);
  return 1;
}

void destruct_ob (object ob)
{
  destruct (ob);
}

void rewarding (object who, object ob)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "ÎªÌÆÈËÃÀÑçÑ°µÃ"+ob->query("name")+"£¬";
  message_vision ("$N¶Ô$nËµµÀ£º¶àÐ»ÕâÎ»"+RANK_D->query_respect(who)+
                  reason+"ÕæÊÇÎª´óÌÆÌìÏÂÃñÖÚÔì¸£ÍÛ£¡\n",me,who);
  reward = quest_reward(who, quests_food, "food");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/food/times",1);
  who->add("quest/food/reward",reward);
  reporting (who,reason, reward, "½±·Ö");
  who->delete("quest/pending/food");
  quest_done(who);
}


ÿ

