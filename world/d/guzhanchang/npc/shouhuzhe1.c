// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("白发老人", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "男性" );
	set("long",
		"守护第一重天的守护者----将军府祖师白发老人\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 150);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "守护者");
  set("family/family_name","将军府");
  set("combat_exp", 3000000);
  set("daoxing", 3000000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 100);
  set("max_mana", 6000);
  set("mana", 6000);
  set("mana_factor", 100);
	
  set_skill("literate", 350);
  set_skill("unarmed", 350);
  set_skill("force", 350);
  set_skill("lengquan-force", 350);
  set_skill("axe", 350);
  set_skill("sword", 350);
  set_skill("dodge", 350);
  set_skill("parry", 350);
  set_skill("sanban-axe", 350);
  set_skill("xiaofeng-sword", 350);
  set_skill("spells", 350);
  set_skill("baguazhou", 350);
  set_skill("yanxing-steps", 350);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("sword", "xiaofeng-sword");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: perform_action, "axe", "sanban" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
                }) );
	setup();
  carry_object("/d/obj/weapon/axe/huafu")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}


void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("此乃天界，岂容你乱来？\n",me);
        return 1;
} 


void die()
{

        object ob = query_temp("my_killer");

        if(ob&&ob->query("9sky/yi")!="done")
        {
        ob->start_busy(3);
        message("chat",HIY+"【九重天】天极(Tian ji):"+ob->name()+
        "闯过了一重·傲野天\n"NOR,users());
        ob->set("9sky/yi","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 10000);
            ob->save();
        tell_object(ob,"你赢得了十年道行");
        
        }
       ::die();
}

