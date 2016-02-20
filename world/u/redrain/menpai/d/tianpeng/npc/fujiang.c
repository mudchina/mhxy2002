// by gslxz@mhsj 2001/11/21 (”≈ªØ)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao(object me);
string ask_cancel();

void create()
{
  set_name("÷Ì∑ ±Ï", ({ "zhu feibiao", "zhu", "feibiao" }));
  set("age", 35);
  set("title", HIY"ÃÏ≈Ó∏Æ∏±Ω´"NOR);
  set("gender", "ƒ––‘");
  set("long", "À˚æÕ «ÃÏ≈Ó∏Æµƒ∏±Ω´°£\n");
  set("attitude", "peaceful");
       set("class", "xian");
  set("str", 50);
  set("per", 13);
  set("combat_exp", 5000000);
  set("daoxing", 3000000);

  set("max_kee", 2500);
  set("max_sen", 2500);
  set("max_mana", 3600);
  set("mana", 7200);
  set("max_force", 3600);
  set("force", 7200);
  set("force_factor", 550);
  set("mana_factor", 550);
  set_skill("unarmed", 530);
    set_skill("tianpeng-force", 530);
  set_skill("dodge", 550);
  set_skill("parry", 530);
  set_skill("rake", 530);
  set_skill("force", 530);
  set_skill("spells", 530);
  set_skill("xbuddhism", 530);
  set_skill("yanxing-steps", 530);
  set_skill("skyriver-rake", 550);
  set_skill("sougu-zhua", 530);
  map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
   create_family("ÃÏ≈Ó∏Æ", 2, "µ‹◊”");
         set("inquiry", ([
     "≥˝∂Ò" : (:ask_mieyao:),
   "cancel": (:ask_cancel:),
    ]));
 setup();
  carry_object("/d/tianpeng/obj/gangpa")->wield();
  carry_object("/d/tianpeng/obj/jinjia")->wear();
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

// void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 1500000 )) {
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
ˇ
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="ÃÏ≈Ó∏Æ") {
//  if(me->query("faith")<100)
//      return ("ƒ„ªπ «œ»∂‡º”–ﬁ¡∂Œ™√Ó°£");
    tell_room(environment(me),"’Ú‘™¥Ûœ…ƒÓƒÓ”–¥ .....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
    return ("∑«Œ“√≈»À,∫Œπ ¿¥¥À?\n");
}

ˇ
