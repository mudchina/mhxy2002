// Changed by sjmao  09-11-97
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);



void create()
{
       set_name("ÁúÅ®", ({"long nu","gongzhu","long","princess"}));

	set("long","×ÏÔÆ¹¬Ö÷ÈË£¬ÁúÍõµÄÅ®¶ù£®\n");
       set("gender", "Å®ĞÔ");
       set("age", 20);
	set("int", 25+random(5));
        set("title", "×ÏÔÆ¹«Ö÷");
       set("attitude", "peaceful");
        set("combat_exp", 350000);
  set("daoxing", 100000);

       set("rank_info/respect", "¹«Ö÷µîÏÂ");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 900);
       set("max_sen", 700);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 500);
       set("mana", 400);
       set("mana_factor", 30);
       set_skill("literate", 80);
       set_skill("unarmed", 100);
       set_skill("dodge", 120);
       set_skill("force", 80);
       set_skill("parry", 100);
       set_skill("fork", 80);
       set_skill("spells", 100);
        set_skill("seashentong", 80);
        set_skill("dragonfight", 80);
        set_skill("dragonforce", 80);
        set_skill("fengbo-cha", 100);
        set_skill("dragonstep", 120);
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");

        set("inquiry", ([ "Àë¹¬": (: expell_me :),
                "leave": (: expell_me :), ]) );

    create_family("¶«º£Áú¹¬", 2, "Ë®×å");
	setup();

        carry_object("/d/obj/cloth/pinkskirt")->wear();
	carry_object("/d/sea/obj/yincha")->wield();
}

void attempt_apprentice(object ob)
{
        command("jump");
	command("say ÎÒÓÖ¶àÁËÒ»¸öµÜ×ÓÒ®£¡\n");
        command("recruit " + ob->query("id") );
        message("system", HIY"ÎÒ¶«º£Áú¹¬ÓÖ¶àÁËÒ»¸öµÜ×Ó  "+this_player()->name()+HIW"
                 ¶«º£Áú¹¬ÊÆÁ¦¼ÓÇ¿ÁË¡£\n"NOR,users());
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="¶«º£Áú¹¬")
    {
      message_vision("×ÏÔÆ¹«Ö÷ÄÑ¹ıµØÍû×Å$N£¬ÓûÑÔÓÖÖ¹¡£\n", me);
      return ("ÄãÈ¥ÎÊÎÒ¸¸Íõ°É¡£\n");
    }
  return ("È¥ÎÊÎÊ±ğÈË°É£¡ÎÒÔõÃ´»áÖªµÀ£¡¡\n");
}
ÿ