// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("依天神龙", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "男性" );
	set("long",
		"守护第四重天的守护者----四海龙王依天神龙\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("family/family_name","东海龙宫");
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "守护者");
  set("combat_exp", 3600000);
  set("daoxing", 3600000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 40);
  set("max_mana", 6000);
  set("mana", 6000);
  set("mana_factor", 50);
	
                set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("fork", 350);
       set_skill("spells", 350);
       set_skill("seashentong", 350);
       set_skill("dragonfight", 350);
       set_skill("dragonforce", 350);
       set_skill("fengbo-cha", 350);
       set_skill("dragonstep", 350);
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("parry", "fengbo-cha");
       map_skill("dodge", "dragonstep");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: perform_action, "fork", "fengbo" :),

                }) );

	setup();
        carry_object("/d/obj/weapon/fork/fork")->wield();
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

        if((ob&&ob->query("9sky/san")=="done") && (ob&&ob->query("9sky/si")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【九重天】天极(Tian ji):"+ob->name()+
        "闯过了四重·楼兰天\n"NOR,users());
        ob->set("9sky/si","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 40000);
           ob->save();
         tell_object(ob,"你赢得了四十年道行");

        }
       ::die();
}


