// by gslxz@mhsj 2001/11/21 (”≈ªØ)
inherit NPC;
#include <ansi.h>

#include <quest_fd.c>
#include <reporting.c>
string ask_mieyao(object me);
string ask_cancel();


int test_player();

void create()
{
  set_name("÷Ì∞ÀΩ‰", ({ "zhu bajie", "zhu", "bajie" }));
  set("age", 70);
    set("title", HIW"ÃÏ≈Ó∏Æ◊Ê ¶“Ø"NOR);
    set("nickname", HIY"ÃÏ≈Ó‘™Àß"NOR);
    set("gender", "ƒ––‘");
  set("long", "∫Ÿ∫Ÿ£¨¡¨¿œ÷Ì∂º≤ª»œ ∂¿≤£ø\n");
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
  set_skill("unarmed", 999);
  set_skill("dodge", 999);
  set_skill("parry", 999);
  set_skill("rake", 999);
  set_skill("force", 999);
    set_skill("tianpeng-force", 999);
  set_skill("spells", 999);
  set_skill("xbuddhism", 999);
  set_skill("yanxing-steps", 999);
  set_skill("skyriver-rake", 999);
  set_skill("sougu-zhua", 999);
  map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("chat_chance",5);
  set("chat_msg",({
    "÷Ì∞ÀΩ‰¿÷∫«∫«µÿÀµµ¿£∫À≠ƒ‹∏¯∞≥¿œ÷Ì»•’“µ„≥‘µƒ∂´Œ˜¿¥°£\n",
    "÷Ì∞ÀΩ‰œÎœÎÀµ£∫œÁœ¬∑¢¥ÛÀÆ‘÷¡À£¨¿œ÷Ì∏√µ±æ»º√º¢√Ò°£\n",
    "÷Ì∞ÀΩ‰Àµµ¿£∫¿œ÷Ì“™—∞±ÈÃÏœ¬√¿æ∆º—Î»£¨‘Ÿ«Î ¿»À¿¥∞≥Àß∏Æ∆∑≥¢∆∑≥¢°£\n",
    "÷Ì∞ÀΩ‰Àµµ¿£∫≤ª «¿œ÷ÌÃ∞◊Ï£¨∞≥¿œ÷ÌœÎ¥’∏ˆ√¿—Á£¨«Î∆Ω√Ò∞Ÿ–’“≤ƒ‹≥¢∏ˆ–¬œ °£\n",
    "÷Ì∞ÀΩ‰◊‘—‘◊‘”ÔµÿÀµ£∫∞≥¿œ÷Ì≤ª «Œ™◊‘º∫£¨¿œ÷ÌœÎ ’ºØ ¿…œ√¿ ≥£¨»√¥ÛÃ∆»À∂ºƒ‹¿¥≥¢≥¢°£\n",
    "÷Ì∞ÀΩ‰≈§π˝…Ì»•≈ı∆‘Ë≈Ë¥ÛµƒΩ∑π≈Ë∞…‡™∞…‡™¥ÛΩ¿¡À∆¿¥°£\n",
    "÷Ì∞ÀΩ‰Õ‰—¸≈ı∆ÀÆÕ∞¥Ûµƒ“¯æ∆∫¯πæﬂÀπæﬂÀµÿπ‡¡Àœ¬»•°£\n",
  }));
  set("inquiry", ([
        "here":   "¥ÀƒÀÃÏ≈ÓÀß∏Æ“≤£¨¿œ÷ÌŒ˜ÃÏπÈ¿¥∫ÛÃ∆Ã´◊⁄”˘¥Õ‘⁄¥Àø™∏Æ£¨◊® ¬“˚ ≥¥»…∆“µ°£\n",
        "name":   "÷Ì∞ÀΩ‰£¨À≠»À≤ª÷™“≤°£\n",
             "food":   (: test_player() :),
        "√¿ ≥":   (: test_player() :),
        "√¿æ∆":   (: test_player() :),
        "√¿—Á":   (: test_player() :),
        "º—Î»":   (: test_player() :),
        " ≥ŒÔ":   (: test_player() :),
        "“˚ÀÆ":   (: test_player() :),
        "≥‘":   (: test_player() :),
        "∫»":   (: test_player() :),
     "≥˝∂Ò" : (:ask_mieyao:),
   "cancel": (:ask_cancel:),
]));
   create_family("ÃÏ≈Ó∏Æ", 1, "¿∂");
  setup();
  carry_object("/d/tianpeng/obj/tianpengpa")->wield();
  carry_object("/clone/armor/jinjia")->wear();
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
     return ("√ª”√µƒ∂´Œ˜£°");
}
else
{
     return ("ƒ„”–»ŒŒÒ¬£ø£°");
}
}
void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 3000000 )) {
	command("say " + RANK_D->query_respect(ob) +
                          "µƒµ¿––≤ªπª∏ﬂ…Ó£¨”––©æ¯—ß√ÿ∑®ø÷≈¬ƒ—“‘¡ÏŒÚ°£\n");
	return;
	}

	if ( (string)ob->query("family/family_name")=="ÃÏ≈Ó∏Æ") {
        command("pat "+ob->query("id"));
        command("say ∫√£¨œ£Õ˚" + RANK_D->query_respect(ob) +
"∂‡º”≈¨¡¶£¨∞—Œ“√«ÃÏ≈Ó∏Æ∑¢—Ôπ‚¥Û°£\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"ªπ «œ»»•—ß–©ª˘¥°π¶∑Ú∞…°£\n");
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
    "$N¬‘”–À˘Àºµÿµ„µ„Õ∑∂‘$nÀµµ¿£∫∞≥¿œ÷ÌœÎ∏¯¥ÛÃ∆»À¥’∏ˆ√¿—Á£¨’˝»±",
    "$N∂‘$nÀµµ¿£∫¿œ÷ÌŒ“Àƒ¥¶—∞«ÛÃÏœ¬√¿Œ∂º—Î»£¨’˝“™’“",
    "$N∂‘$nÀµµ¿£∫∂‘¡ÀœÁœ¬∑¢¥ÛÀÆ‘÷£¨”–º∏∏ˆ‘÷√ÒœÎ“™ ≤√¥",
    "$N∂‘$nÀµµ¿£∫æ©≥«øÕµΩ£¨‘⁄ø™∑‚∏Æ…œ£¨∆‰÷–”–“ªπŸ»À»√¿œ÷ÌŒ“¥˙—∞ ≤√¥",
    "$N∂‘$nµ„Õ∑Àµµ¿£∫ÀÆ¬Ω¥Ûª·º¥Ω´ø™—Á«Î∏˜¬∑∑® ¶µΩª·£¨Ã˝Àµ”–∑® ¶œÎ“™ ≤√¥",
    "$N∂‘$n“ªµ„Õ∑Àµµ¿£∫∞≥¿œ÷Ìæ»º√º¢√Ò£¨Ã˝Àµ’˝–Ë“™",
    "$NœÎœÎÀµ£∫”–»Àµπ «œÎ»√∞≥¿œ÷Ì∏¯’“∏ˆ ≤√¥ ≤√¥",
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
    message_vision ("$N∂‘$nÀµµ¿£∫’‚Œª"+RANK_D->query_respect(who)+
                    "£¨∞≥º˚ƒ„…Ì…œœÈ‘∆ª∑»∆£¨∫Œ≤ª»•¥”ÀŸ∏∞≥§∞≤Ω¯π¨«Î…Õ£ø\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/food"))
  {
    message_vision ("$N∂‘$nÀµµ¿£∫’‚Œª"+RANK_D->query_respect(who)+
                    "£¨∞≥ªπµ»◊≈«Îƒ˙∞Ô√¶’“µƒ"+
		    who->query("quest/pending/food/name")+"ƒÿ£°\n",me,who);
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
    message_vision ("$N∂‘$nÃæ∆¯Àµµ¿£∫’‚Œª"+RANK_D->query_respect(who)+
                    "∏√◊ˆµƒ ¬◊ˆ¡À≤ª…Ÿ£¨∞≥ø¥ƒ˙ªπ «“‘∫Û‘Ÿ¿¥∞…°£\n",me,who);
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
        "£¨\n’‚Œª"+RANK_D->query_respect(who)+
        "ø…∑Ò…Õ¿œ÷Ì∏ˆ¥Û¡≥…Ë∑®◊”»•∏¯≈™¿¥£ø\n";
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
    message_vision ("$N∂‘$nÀµµ¿£∫’‚Œª"+RANK_D->query_respect(who)+
                    "…Ì…œœÈ‘∆ª∑»∆£¨«ÎÀŸ∏∞≥§∞≤Ω¯π¨«Î…Õ£°\n",me,who);
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

  message_vision ("$Nº˚$n ÷…œƒ√◊≈"+ob->query("name")+"£¨±„∏œΩÙ…Ï ÷Ω”π˝»•°£\n",me,who);
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
     message_vision ("$N“°“°Õ∑£∫∞≥¿œ÷Ìœ÷‘⁄÷ª–Î“™≥‘µƒ∫»µƒ°£\n",me);
     return 0;
  }
*/

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N∂‘$nÀµµ¿£∫’‚Œª"+RANK_D->query_respect(who)+
                    "£¨∞≥º˚ƒ„…Ì…œœÈ‘∆ª∑»∆£¨∫Œ≤ª»•¥”ÀŸ∏∞≥§∞≤Ω¯π¨«Î…Õ£ø\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/food"))
  {
    message_vision ("$N∂‘$nÀµµ¿£∫ƒ˙∏¯¿œ÷Ì’‚∏… ≤√¥£ø∞≥¿œ÷Ìæ°π‹Ã∞◊Ï“≤≤ª ‹≤ª“Â÷Æ≤∆“≤°£\n",me,who);
    return 0;
  }

  if(ob->is_character()) return 0;

  if (who->query("quest/pending/food/name") != ob->query("name"))
  {
    message_vision ("$N∂‘$nÀµµ¿£∫’‚Œª"+RANK_D->query_respect(who)+
                    "£¨∞≥µ»◊≈«Îƒ˙∞Ô√¶’“µƒ"+
		    who->query("quest/pending/food/name")+
                    "£¨ƒ˙»¥∏¯∞≥"+ob->query("name")+"£¨’‚°≠°≠\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/food/id") != ob->query("id"))
  {
    message_vision ("$N∂‘$nÀµµ¿£∫’‚Œª"+RANK_D->query_respect(who)+
                    "£¨∞≥µ»◊≈ƒ˙µƒ"+who->query("quest/pending/food/name")+
                    "£¨∂´Œ˜µπÕ¶œÛ£¨µ´≤ª «Õ¨“ª∏ˆªı£ª∞≥“™µƒ «("+
                    who->query("quest/pending/food/id")+")£¨ƒ˙∏¯µƒ «("+
                    ob->query("id")+")£°\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/food/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N∂‘$n“°Õ∑µ¿£∫’‚√¥øÏæÕªÿ¿¥¡À£ø∞≥¿œ÷Ì≤ª“™ºŸªı°£\n",me,who);
    message_vision ("$N”÷∑‘∏¿µ¿£∫ƒ˙‘Ÿª®∏ˆ"+chinese_number((t-uptime())/60+1)+
                    "∑÷÷”»•—∞—∞°£\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: »√¿œ÷Ì“™œ¬∂´Œ˜°£\n");
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

  reason = "Œ™Ã∆»À√¿—Á—∞µ√"+ob->query("name")+"£¨";
  message_vision ("$N∂‘$nÀµµ¿£∫∂‡–ª’‚Œª"+RANK_D->query_respect(who)+
                  reason+"’Ê «Œ™¥ÛÃ∆ÃÏœ¬√Ò÷⁄‘Ï∏£Õ€£°\n",me,who);
  reward = quest_reward(who, quests_food, "food");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/food/times",1);
  who->add("quest/food/reward",reward);
  reporting (who,reason, reward, "Ω±∑÷");
  who->delete("quest/pending/food");
  quest_done(who);
}
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="ÃÏ≈Ó∏Æ") {
//  if(me->query("faith")<100)
//      return ("ƒ„ªπ «œ»∂‡º”–ﬁ¡∂Œ™√Ó°£");
    return "/d/obj/mieyao"->query_yao(me);
}
    return ("∑«Œ“√≈»À,∫Œπ ¿¥¥À?\n");
}


ˇ

